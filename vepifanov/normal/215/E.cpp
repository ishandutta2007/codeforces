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
ll l, r;
int p[100];

ll get (string s, int n) {
    if (n == 1) re 0;
    int m = n, o = 0;
    for (int i = 2; i <= m; i++)
        if (m % i == 0) {
            p[o++] = i;
            while (m % i == 0) m /= i;
        }
    ll ans = 0;
    for (int i = 1; i < (1 << o); i++) {
        int tmp = 1, q = -1;
        for (int j = 0; j < o; j++)
            if ((i >> j) & 1) {
                q = -q;
                tmp *= p[j];
            }   
        int cur = n / tmp;
        if (sz (s) <= cur) {
            if (sz (s) == 0) ans += ((ll)1 << (cur - 1)) * q; else ans += ((ll)1 << (cur - sz (s))) * q;
        } else {
            int ok = 1;
            for (int j = cur; j < sz (s); j++)
                if (s[j] != s[j - cur]) {
                    ok = 0;
                    break;
                }   
            if (ok) ans += q;
        }
    }
    re ans;
}

ll go (string s, string t, int i) {
    if (s == t) re get (s, sz (s));
    if (s[i] == '0') re go (s, t + '0', i + 1);
    re get (t + '0', sz (s)) + go (s, t + '1', i + 1);
}

ll get (ll x) {
    if (x == 0) re 0;
    string s = "";
    while (x) {
        s += char (x % 2 + '0');
        x /= 2;
    }
    reverse (all (s));
    ll ans = 0;
    for (int i = 2; i < sz (s); i++)    
        ans += get ("", i);
    ans += go (s, "1", 1);
    re ans;
}                        

int main () {
    cin >> l >> r;
    cout << get (r) - get (l - 1) << endl;
    return 0;
}