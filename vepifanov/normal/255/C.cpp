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
int x[4000], cnt[4000], p[4000], q[4000], was[4000];
map<int, int> all;
int ct;
              
int get (int x) {
    if (all.find (x) != all.end ()) re all[x];
    re all[x] = m++;
}

int main () {
    scanf ("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        x[i] = get (x[i]);
        cnt[x[i]]++;
        ans = max (ans, cnt[x[i]]);
    }
    for (int i = 0; i < m; i++) {
        memset (cnt, 0, sizeof (cnt));
        ct++;
        for (int j = 0; j < n; j++)
            if (x[j] == i) ct++; else
            if (was[x[j]] != ct) {
                was[x[j]] = ct;
                cnt[x[j]]++;
            }
        memset (p, 0, sizeof (p));
        memset (q, 0, sizeof (q));
        for (int j = 0; j < n; j++) {
            if (x[j] == i) break;
            cnt[x[j]] -= 1 - p[x[j]];
            p[x[j]] = 1;
        }   
        for (int j = n - 1; j >= 0; j--) {
            if (x[j] == i) break;
            cnt[x[j]] -= 1 - q[x[j]];
            q[x[j]] = 1;
        }   
        for (int j = 0; j < m; j++)
            if (j != i)
                ans = max (ans, cnt[j] * 2 + 1 + p[j] + q[j]);
    }
    printf ("%d\n", ans);
    return 0;
}