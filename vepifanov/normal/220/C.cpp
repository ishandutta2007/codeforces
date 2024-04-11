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
int x[100000];
int px[100000];
int y[100000];
int py[100000];
multiset<int> ai, ad;

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]); x[i]--;
        px[x[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf ("%d", &y[i]); y[i]--;
        py[y[i]] = i;
    }
    for (int i = 0; i < n; i++)
        if (py[i] >= px[i])
            ad.insert (py[i] - px[i]);
        else
            ai.insert (px[i] - py[i]);  
    int bd = 0, bi = 0;
    for (int i = 0; i < n; i++) {
        int ans = n + 1;
        if (!ad.empty ()) ans = min (ans, *ad.begin () + bd);
        if (!ai.empty ()) ans = min (ans, *ai.begin () + bi);
        printf ("%d\n", ans);
        while (!ad.empty () && *ad.begin () + bd == 0) {
            ai.insert (0 - bi);
            ad.erase (ad.begin ());
        }
        int j = y[i];
        ai.erase (ai.find (px[j] - bi));
        ad.insert (n - px[j] - bd);
        bd--;
        bi++;
    }
    return 0;
}