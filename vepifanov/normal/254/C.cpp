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

int n;
int m;
int y[26], z[26];
string s, t;

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> s >> t;
    n = sz (s);
        for (int i = 0; i < n; i++) {
            y[s[i] - 'A']++;
            z[t[i] - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = s[i] - 'A';
            for (int b = 0; b < 26; b++)
                if (a == b) {
                    if (z[a] > 0) {
                        y[a]--;
                        z[a]--;
                        break;
                    }
                } else {
                    if (y[a] > z[a] && z[b] > y[b]) {
                        ans++;
                        s[i] = char (b + 'A');
                        y[a]--;
                        z[b]--;
                        break;
                    }
                }
        }
        cout << ans << endl << s << endl;
    return 0;
}