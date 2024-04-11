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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 300000 + 10;

const int mod = 1000*1000*1000 + 7;

int n;
int m;
pair<ii, int> v[N];
int p[N];
int q[N];
int t[N];
int st[N];
int c0[N];
int c1[N];
int c2[N];
ll dans[N];
string a, b, c;
int lcp[N];
int ft[N];

int main () {
    cin >> a >> b >> c;
    int la = sz (a);
    int lb = sz (b);
    int lc = sz (c);
    string s = a + char ('z' + 1) + b + char ('z' + 2) + c + char ('z' + 3);
    n = sz (s);
    for (int i = 0; i < n; i++)
        p[i] = s[i] - 'a';
    for (int i = 0; (1 << i) < n; i++) {
        int len = 1 << i;
        for (int j = 0; j < n; j++)
            if (j + len < n)
                v[j] = mp (mp (p[j], p[j + len]), j);
            else
                v[j] = mp (mp (p[j], 1e9), j);
        sort (v, v + n);
        int r = 0;
        for (int j = 0; j < n; j++) {
            if (j > 0 && v[j - 1].fi != v[j].fi)
                r++;
            p[v[j].se] = r; 
        }   
    }
    for (int i = 0; i < n; i++) {
        q[p[i]] = i;
        if (i < la)
            t[i] = 0;
        else
        if (i >= la + 1 && i < la + 1 + lb)
            t[i] = 1;
        else
        if (i >= la + 1 + lb + 1 && i < la + 1 + lb + 1 + lc)
            t[i] = 2;
        else
            t[i] = 3;   
    }   
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int a = p[i];
        int b = a + 1;
        if (b == n) {
            lcp[a] = cur = 0;
            continue;
        }
        int j = q[b];
        cur = max (0, cur - 1);
        while (i + cur < n && j + cur < n && s[i + cur] == s[j + cur]) cur++;
        lcp[a] = cur;
//      cout << s.substr (i) << " " << s.substr (j) << " = " << cur << endl;
    }
    int r = 1;
    st[0] = 0;
    c0[0] = int (t[q[0]] == 0);
    c1[0] = int (t[q[0]] == 1);
    c2[0] = int (t[q[0]] == 2);
    ft[0] = t[q[0]];    
//  cout << s.substr (q[0]) << " " << t[q[0]] << "\n";
    for (int i = 1; i < n; i++) {
        int ct = t[q[i]];
        int pt = t[q[i - 1]];
        int cur = lcp[i - 1];
//      cout << s.substr (q[i]) << " " << ct << " " << cur << "\n"; 
        while (r > 1 && st[r - 1] > cur) {
            ll tmp = ((ll)c0[r - 1] * c1[r - 1] * c2[r - 1]) % mod;
            int pr = max (st[r - 2], cur);
//          printf ("%d %d = %d * %d * %d\n", pr + 1, st[r - 1], c0[r - 1], c1[r - 1], c2[r - 1]);
            (dans[pr + 1] += tmp) %= mod;
            (dans[st[r - 1] + 1] -= tmp) %= mod;
            if (r > 1 && pr == st[r - 2]) {
                c0[r - 2] += c0[r - 1] - int (ft[r - 1] == 0);
                c1[r - 2] += c1[r - 1] - int (ft[r - 1] == 1);
                c2[r - 2] += c2[r - 1] - int (ft[r - 1] == 2);
                r--;
            } else {
//              printf ("ok %d %d\n", pr, cur);
                st[r - 1] = pr;
                break;
            }
        }
        if (r > 0 && st[r - 1] == cur) {
            c0[r - 1] += int (ct == 0);
            c1[r - 1] += int (ct == 1);
            c2[r - 1] += int (ct == 2);
            continue;
        } else {
            st[r] = cur;
            c0[r] = int (ct == 0) + int (pt == 0);
            c1[r] = int (ct == 1) + int (pt == 1);
            c2[r] = int (ct == 2) + int (pt == 2);
            ft[r] = pt;
            r++;
        }
    }
    while (r > 1) {    
        ll tmp = ((ll)c0[r - 1] * c1[r - 1] * c2[r - 1]) % mod;
        int pr = st[r - 2];
        (dans[pr + 1] += tmp) %= mod;
        (dans[st[r - 1] + 1] -= tmp) %= mod;
        c0[r - 2] += c0[r - 1] - int (ft[r - 1] == 0);
        c1[r - 2] += c1[r - 1] - int (ft[r - 1] == 1);
        c2[r - 2] += c2[r - 1] - int (ft[r - 1] == 2);
        r--;
    }
    ll ans = 0;
    for (int i = 1; i <= min (la, min (lb, lc)); i++) {
        (ans += dans[i]) %= mod;
        if (ans < 0) ans += mod;
        cout << ans << " ";
    }
    printf ("\n");
    return 0;
}