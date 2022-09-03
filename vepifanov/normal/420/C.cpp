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
int cnt[300000];
map<ii, int> all;
int d[300001];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        if (a > b) swap (a, b);
        all[mp (a, b)]++;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 0; i < n; i++) d[cnt[i]]++;
    for (int i = n - 1; i >= 0; i--) d[i] += d[i + 1];
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += d[max (0, m - cnt[i])] - int (cnt[i] >= m - cnt[i]);
    ans /= 2;
    for (map<ii, int>::iterator it = all.begin (); it != all.end (); it++)
        if (cnt[it->fi.fi] + cnt[it->fi.se] >= m && cnt[it->fi.fi] + cnt[it->fi.se] - it->se < m)
            ans--;
    cout << ans << endl;
    return 0;
}