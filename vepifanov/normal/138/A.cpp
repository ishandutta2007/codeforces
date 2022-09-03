#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const string tp[4] = {"aaaa", "aabb", "abab", "abba"};

int n;
int m, k;

string w[10000];

int main () {
    cin >> n >> k;
    n *= 4;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        w[i] = "";
        int l = 0;
        while (l < k && sz (s)) {
            char c = s[sz (s) - 1];
            w[i] += c;
            s.erase (sz (s) - 1);
            if (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u') l++;
        }
        if (l < k) bad = 1;
    }
    if (!bad)
        for (int t = 0; t < 4; t++) {
            int ok2 = 1;
            for (int i = 0; i < n; i += 4) {
                int ok = 1;
                for (int p = 0; p < 4 && ok; p++)
                    for (int q = p + 1; q < 4 && ok; q++)
                        if (tp[t][p] == tp[t][q] && w[i + p] != w[i + q])
                            ok = 0;
                if (!ok) { ok2 = 0; break; }
            }
            if (ok2) {
                cout << tp[t] << endl;
                re 0;
            }
        }   
    cout << "NO" << endl;
    return 0;
}