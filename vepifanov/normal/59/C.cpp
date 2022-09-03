#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int k = 0, l = 0;
string s;

int was[26];

int main() {
    cin >> n >> s;  
    m = sz (s) - 1;
    for (int i = 0; 2 * i <= m; i++) {
        if (s[i] == '?' && s[m - i] == '?') k++; else
        if (s[i] == '?') s[i] = s[m - i]; else
        if (s[m - i] == '?') s[m - i] = s[i]; else
        if (s[i] != s[m - i]) {
            printf ("IMPOSSIBLE\n");
            re 0;
        }
        if (s[i] != '?') {
            l += 1 - was[s[i] - 'a'];
            was[s[i] - 'a'] = 1;
        }
    }
    if (l + k < n) {
        printf ("IMPOSSIBLE\n");
        re 0;
    }
    int r = 0;
    for (int i = 0; 2 * i <= m; i++)
        if (s[i] == '?') {
            if (l + k > n) s[i] = s[m - i] = 'a'; else {
                while (r < n && was[r]) r++;
                s[i] = s[m - i] = 'a' + r;
                was[r] = 1;
                l++;
                r++;
            }
            k--;
        }

    cout << s << endl;

    return 0;
}