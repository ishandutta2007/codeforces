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
int p[100001], q[100001];
int lcp[100001];
ii u[100001];

int main () {
    cin >> s;
    n = sz (s);
    for (int i = 0; i < n; i++) p[i] = s[i] - 'a';
    for (int i = 1; i < n; i *= 2) {
        vector<pair<ii, int> > w;
        for (int j = 0; j < n; j++) 
            if (j + i < n)
                w.pb (mp (mp (p[j], p[j + i]), j));
            else
                w.pb (mp (mp (p[j], -1), j));
        sort (all (w));
        int r = 0;
        for (int j = 0; j < n; j++) {
            if (j > 0 && w[j - 1].fi != w[j].fi) r++;
            p[w[j].se] = r;
        }
    }
    for (int i = 0; i < n; i++) q[p[i]] = i;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur = max (cur - 1, 0);
        int a = p[i];
        if (a + 1 == n) 
            cur = 0; 
        else
            while (q[a] + cur < n && q[a + 1] + cur < n && s[q[a] + cur] == s[q[a + 1] + cur]) cur++;
        lcp[a] = cur;
    }
    int r = 0;
    ll ans = 0;
    lcp[n] = 0;
    u[r++] = mp (-1, 0);
    for (int i = 0; i < n; i++) {
        int tmp2 = lcp[i];
        if (i > 0) tmp2 = max (tmp2, lcp[i - 1]);
        ans += (n - i) - tmp2;
        int tmp = 1;
        while (r > 0 && lcp[i] <= u[r - 1].se) {
            tmp += u[r - 1].fi;
            int l = u[r - 1].se - max (lcp[i], u[r - 2].se);
            ans += (ll)l * tmp * (tmp + 1) / 2;
            r--;
        }
        u[r++] = mp (tmp, lcp[i]);
    }
    cout << ans << endl;
    return 0;
}