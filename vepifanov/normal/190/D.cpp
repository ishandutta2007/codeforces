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
int m = 0, K;
int x[400000];
int cnt[400000];
map<int, int> num;
set<ii> all;

int get (int x) {
    if (num.find (x) != num.end ()) re num[x];
    num[x] = m;
    m++;
    re m - 1;
}

int add (int i) {
    all.erase (mp (cnt[x[i]], x[i]));
    cnt[x[i]]--;
    all.insert (mp (cnt[x[i]], x[i]));
    re 0;
}

int del (int i) {
    all.erase (mp (cnt[x[i]], x[i]));
    cnt[x[i]]++;
    all.insert (mp (cnt[x[i]], x[i]));
    re 0;
}

int main () {
    scanf ("%d%d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        x[i] = get (x[i]);
    }   
    for (int i = 0; i < m; i++) all.insert (mp (0, i));
    int k = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (k < n && -all.begin()->fi < K) {
            add (k);
            k++;
        }
        if (-all.begin()->fi >= K) ans += n - k + 1;
        del (i);
    }
    printf ("%I64d\n", ans);
    return 0;
}