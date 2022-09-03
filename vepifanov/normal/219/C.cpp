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
string s;

int main () {
    cin >> n >> m >> s;
    if (m == 2) {
        int a1 = 0, a2 = 0;
        for (int i = 0; i < n; i++)
            if (s[i] - 'A' != (i & 1))
                a1++;
            else
                a2++;   
        cout << min (a1, a2) << endl;
        for (int i = 0; i < n; i++)
            if (a1 <= a2)
                cout << char ('A' + (i & 1));
            else
                cout << char ('B' - (i & 1));
        cout << endl;
        re 0;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1]) {
            ans++;
            int ok = 0;
            for (int c = 0; c < m; c++)
                if (s[i - 1] - 'A' != c && (i + 1 == n || s[i + 1] - 'A' != c)) {
                    s[i] = c + 'A';
                    ok = 1;
                    break;
                }
            if (!ok) s[i] = (s[i - 1] - 'A' + 1) % m + 'A';
        }
    cout << ans << endl << s << endl;
    return 0;
}