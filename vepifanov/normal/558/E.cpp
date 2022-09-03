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

const int N = 400000;

int n;
int m;
char h[100001];
int cnt[N][26];
int x[N];
int y[N];
int z[N];
set<ii> all;

int right (int a, int k, int b) {
    if (z[a]) {
        for (int i = 0; i < 26 && k; i++) {
            int tmp = min (cnt[a][i], k);
            cnt[a][i] -= tmp;
            cnt[b][i] += tmp;
            k -= tmp;
        }
    } else {
        for (int i = 25; i >= 0 && k; i--) {
            int tmp = min (cnt[a][i], k);
            cnt[a][i] -= tmp;
            cnt[b][i] += tmp;
            k -= tmp;
        }
    }   
    re 0;
}

int left (int a, int k, int b) {
    if (z[a]) {
        for (int i = 25; i >= 0 && k; i--) {
            int tmp = min (cnt[a][i], k);
            cnt[a][i] -= tmp;
            cnt[b][i] += tmp;
            k -= tmp;
        }
    } else {    
        for (int i = 0; i < 26 && k; i++) {
            int tmp = min (cnt[a][i], k);
            cnt[a][i] -= tmp;
            cnt[b][i] += tmp;
            k -= tmp;
        }
    }
    re 0;
}

int out () {
    for (auto it = all.begin (); it != all.end (); it++) {
        int j = it->se;
//      printf ("%d - %d = %d\n", x[j], y[j], z[j]);
        if (z[j]) {
            for (int k = 25; k >= 0; k--)
                for (int i = 0; i < cnt[j][k]; i++) {
                    printf ("%c", 'a' + k);
                }
        } else {
            for (int k = 0; k < 26; k++)
                for (int i = 0; i < cnt[j][k]; i++) {
                    printf ("%c", 'a' + k);
                }
        }
    }
    printf ("\n");  
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    scanf (" %s", h);
    int o = 0;
    for (int i = 0; i < n; i++) {
        all.insert (mp (i, o));
        cnt[o][h[i] - 'a']++;
        x[o] = y[o] = i;
        o++;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--; c ^= 1;
        auto it = all.lower_bound (mp (a, -1));
        if (it != all.begin ()) {
            it--;
            int j = it->se;
            if (y[j] >= a) {
                if (y[j] >= b) {
                    if (y[j] > b) {
//                      printf ("%d %d %d %d\n", x[j], y[j], a, b);
                        right (j, y[j] - b, o + 1);
                        right (j, b - a + 1, o);
                        x[o] = a;
                        y[o] = b;
                        z[o] = c;
                        x[o + 1] = b + 1;
                        y[o + 1] = y[j];
                        z[o + 1] = z[j];
                        y[j] = a - 1;
                        all.insert (mp (a, o));
                        all.insert (mp (b + 1, o + 1));
                        o += 2;
                        continue;   
                    }
                    right (j, b - a + 1, o);
                    x[o] = a;
                    y[o] = b;
                    z[o] = c;
                    y[j] = a - 1;
                    all.insert (mp (a, o));
                    o++;
                    continue;
                }
                right (j, y[j] - a + 1, o);
                y[j] = a - 1;
            } else {
                it++;
                j = it->se;
                if (y[j] >= b) {
                    if (y[j] > b) {
                        right (j, y[j] - b, o);
                        x[o] = b + 1;
                        y[o] = y[j];
                        z[o] = z[j];
                        all.insert (mp (b + 1, o));
                        y[j] = b;
                        z[j] = c;
                        o++;
                        continue;
                    }
                    z[j] = c;
                    continue;
                }
                left (j, 1e9, o);
                all.erase (it);
            }
        }
        while (true) {
            auto it = all.lower_bound (mp (a, -1));
            if (it == all.end ()) break;
            int j = it->se;
//          printf ("%d %d %d %d\n", x[j], y[j], a, b);
            if (x[j] <= b) {
                if (y[j] <= b) {
                    left (j, 1e9, o);
                    all.erase (it);
                } else {
                    left (j, b - x[j] + 1, o);
                    all.erase (it);
                    x[j] = b + 1;
                    all.insert (mp (b + 1, j));
                    break;
                }   
            } else break;
        }
        x[o] = a;
        y[o] = b;
        z[o] = c;
        all.insert (mp (a, o));
        o++;
//      printf("%d %d %d\n", a, b, c);
//      out ();
    }
    out ();
    return 0;                
}