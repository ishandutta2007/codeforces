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
vi res;
int a[200000];
int b[200000];
int c[200000];
int cnt[400000];
int cur[400000];
int p;
int o = 0;
map<int, int> all;

int get (int x) {
    if (all.find (x) != all.end ()) re all[x];
    all[x] = o++;
    re o - 1;
}

int go (int h) {
    
    int rem = m, k = 0;
    for (int i = h; i < n; i += p)
        c[k++] = a[i];
    for (int i = 0; i < k; i++) {
        int j;
        if (i >= m) {
            j = c[i - m];
            rem -= abs (cur[j] - cnt[j]);
            cur[j]--;
            rem += abs (cur[j] - cnt[j]);
        }
        j = c[i];
        rem -= abs (cur[j] - cnt[j]);
        cur[j]++;
        rem += abs (cur[j] - cnt[j]);
        if (i + 1 >= m && rem == 0) res.pb (h + (i - m + 1) * p + 1);
    }
    for (int i = 0; i < k; i++) cur[c[i]] = 0;
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &a[i]);
        a[i] = get (a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d", &b[i]);
        b[i] = get (b[i]);
        cnt[b[i]]++;
    }
    for (int i = 0; i < p && i < n; i++) go (i);
    sort (all (res));
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}