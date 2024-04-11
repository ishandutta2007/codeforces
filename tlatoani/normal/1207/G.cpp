//
// Created by Danny Mittal on 7/2/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int LIMIT = 640;
const int MAXN = 400001;

int parent[MAXN];
vector<int> children[MAXN];
vector<int> queries[MAXN];
char letters[MAXN];

int answer[MAXN];
int queryNodes[MAXN];
int queryChildren[26][MAXN];
int amt[MAXN];



void computeLPSArray(string pat, int* lps);

// Prints occurrences of txt[] in pat[]
int KMPSearch(string pat, int txt) {
    int res = 0;

    int M = pat.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, lps);

    int j = 0; // index for pat[]
    while (txt) {
        if (pat[j] == letters[txt]) {
            j++;
            txt = parent[txt];
        }

        if (j == M) {
            res++;
            j = lps[j - 1];
        }

            // mismatch after j matches
        else if (txt && pat[j] != letters[txt]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                txt = parent[txt];
        }
    }
    return res;
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int* lps) {
    int M = pat.size();
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void recur(int node) {
    int songCurr = node;
    int queryCurr = 0;
    for (int j = LIMIT; j; j--) {
        if (!songCurr) {
            break;
        }
        queryCurr = queryChildren[letters[songCurr] - 'a'][queryCurr];
        if (!queryCurr) {
            break;
        }
        amt[queryCurr]++;
        songCurr = parent[songCurr];
    }
    for (int query : queries[node]) {
        answer[query] = amt[queryNodes[query]];
    }
    for (int child : children[node]) {
        recur(child);
    }
    songCurr = node;
    queryCurr = 0;
    for (int j = LIMIT; j; j--) {
        if (!songCurr) {
            break;
        }
        queryCurr = queryChildren[letters[songCurr] - 'a'][queryCurr];
        if (!queryCurr) {
            break;
        }
        amt[queryCurr]--;
        songCurr = parent[songCurr];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    parent[0] = -1;
    letters[0] = -1;
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++) {
        int type;
        cin >> type;
        if (type == 1) {
            parent[j] = 0;
        } else {
            cin >> parent[j];
        }
        children[parent[j]].push_back(j);
        cin >> letters[j];
    }
    //cout << "hi" << endl;
    //memset(amt, 0, MAXN * sizeof(int));
    //memset(queryChildren, 0, 26 * MAXN * sizeof(int));
    int m;
    cin >> m;
    int x = 0;
    for (int k = 0; k < m; k++) {
        //cout << "k = " << k << endl;
        int j;
        string t;
        cin >> j >> t;
        //cout << "k = " << k << ", t = '" << t << "', length = " << t.size() << endl;
        if (t.size() <= LIMIT) {
            int node = 0;
            for (int a = t.size() - 1; a >= 0; a--) {
                int letter = t[a] - 'a';
                if (queryChildren[letter][node] == 0) {
                    queryChildren[letter][node] = ++x;
                }
                node = queryChildren[letter][node];
            }
            queryNodes[k] = node;
            queries[j].push_back(k);
        } else {
            for (int a = 0; a < (t.size() >> 1); a++) {
                swap(t[a], t[t.size() - a - 1]);
            }
            //cout << "k = " << k << ", t = '" << t << "', length = " << t.size() << endl;
            answer[k] = KMPSearch(t, j);
        }
    }
    //cout << "bye" << endl;
    recur(0);
    for (int k = 0; k < m; k++) {
        cout << answer[k] << '\n';
    }
    cout << flush;
}