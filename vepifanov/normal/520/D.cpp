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
map<ii, int> all;
set<ii> now;
set<int> can;
int x[100000];
int y[100000];

int stable (int x, int y) {
    for (int t = -1; t <= 1; t++)
        if (now.count (mp (x + t, y + 1))) {
            int tmp = 0;
            for (int s = -1; s <= 1; s++)
                if (now.count (mp (x + t + s, y)))
                    tmp++;
            if (tmp == 1) re 0;
        }
    re 1;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        all[mp (x[i], y[i])] = i;
        now.insert (mp (x[i], y[i]));
    }
    for (int i = 0; i < n; i++)
        if (stable (x[i], y[i]))
            can.insert (i);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j;
        if (i & 1)
            j = *can.begin ();
        else
            j = *can.rbegin ();
//      printf ("%d %d\n", j, sz (can));    
        ans = ((ll)ans * n + j) % 1000000009;
        can.erase (j);
        now.erase (mp (x[j], y[j]));
        for (int t = -2; t <= 2; t++)
            if (now.count (mp (x[j] + t, y[j])) && can.count (all[mp (x[j] + t, y[j])]) && !stable (x[j] + t, y[j]))
                can.erase (all[mp (x[j] + t, y[j])]);
        for (int t = -1; t <= 1; t++)
            if (now.count (mp (x[j] + t, y[j] - 1)) && stable (x[j] + t, y[j] - 1))
                    can.insert (all[mp (x[j] + t, y[j] - 1)]);
    }
    printf ("%d\n", ans);
    return 0;
}