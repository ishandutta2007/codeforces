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
#define prev PREV
                         
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

char h[1000000];
set<ll> all[600001];
ll p[600001];

int main () {
    p[0] = 1;
    for (int i = 1; i <= 600000; i++) p[i] = (p[i - 1] * 239017) % 1000000009;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf (" %s", h);
        string s (h);
        ll ht = 0;
        for (int j = 0; j < sz (s); j++)
            (ht += s[j] * p[j]) %= 1000000009;
        for (int j = 0; j < sz (s); j++)
            for (int k = 0; k < 3; k++)
                if (s[j] - 'a' != k)
                    all[sz (s)].insert (((ht - s[j] * p[j] + ('a' + k) * p[j]) % 1000000009 + 1000000009) % 1000000009);
    }
    for (int i = 0; i < m; i++) {
        scanf (" %s", h);
        string s (h);
        ll ht = 0;
        for (int j = 0; j < sz (s); j++)
            (ht += s[j] * p[j]) %= 1000000009;
        if (all[sz (s)].find (ht) != all[sz (s)].end ()) printf ("YES\n"); else printf ("NO\n");
    }
    return 0;
}