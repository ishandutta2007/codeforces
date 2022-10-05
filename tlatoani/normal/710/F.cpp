//
// Created by Danny Mittal on 8/2/20.
//

#define ll long long

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int LIMIT = 550;
const int MAXN = 300001;

int children[26][MAXN];
int ix[MAXN];
int k = 0;
int currIx = 0;

map<int, string> large;


void computeLPSArray(string pat, int* lps);

// Prints occurrences of txt[] in pat[]
int KMPSearch(string pat, string txt) {
    int res = 0;

    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, lps);

    int j = 0; // index for pat[]
    int k = 0;
    while (k < N) {
        if (pat[j] == txt[k]) {
            j++;
            k++;
        }

        if (j == M) {
            res++;
            j = lps[j - 1];
        }

            // mismatch after j matches
        else if (k < N && pat[j] != txt[k]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                k++;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    for (; m; m--) {
        int type;
        string s;
        cin >> type >> s;
        if (type == 1) {
            int node = 0;
            for (char chara : s) {
                if (children[chara - 'a'][node] == 0) {
                    children[chara - 'a'][node] = ++k;
                }
                node = children[chara - 'a'][node];
            }
            ix[node] = ++currIx;
            if (s.size() > LIMIT) {
                large[currIx] = s;
            }
        } else if (type == 2) {
            int node = 0;
            for (char chara : s) {
                if (children[chara - 'a'][node] == 0) {
                    children[chara - 'a'][node] = ++k;
                }
                node = children[chara - 'a'][node];
            }
            if (s.size() > LIMIT) {
                large.erase(ix[node]);
            }
            ix[node] = 0;
        } else {
            ll res = 0;
            for (int a = 0; a < s.size(); a++) {
                int node = 0;
                for (int b = a; b < min((int) s.size(), a + LIMIT); b++) {
                    node = children[s[b] - 'a'][node];
                    if (!node) {
                        break;
                    }
                    if (ix[node]) {
                        res++;
                    }
                }
            }
            if (s.size() > LIMIT) {
                for (auto it = large.begin(); it != large.end(); it++) {
                    res += (ll) KMPSearch(it->second, s);
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}