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
set<int> all[100001];
int was[100001];

int main () {
    scanf ("%d%d\n", &n, &m);
    for (int i = 0; i < m; i++) {
        char t[2];
        int x;
        scanf ("%s %d\n", t, &x);
        if (t[0] == '+') {
            if (was[x]) printf ("Already on\n"); else { 
                int bad = 0;
                for (int i = 1; i * i <= x; i++)
                    if (x % i == 0) {
                        if (i > 1 && !all[i].empty ()) {
                            bad = *all[i].begin ();
                            break;
                        }
                        if (i * i != x && !all[x / i].empty ()) {
                            bad = *all[x / i].begin ();
                        }
                    }
                    if (bad) printf ("Conflict with %d\n", bad); else {
                        was[x] = 1;
                        for (int i = 1; i * i <= x; i++)
                        if (x % i == 0) {
                            if (i > 1) all[i].insert (x);
                            if (i * i != x) all[x / i].insert (x);
                        }
                    printf ("Success\n");
                }   
            }
        } else {
            if (!was[x]) printf ("Already off\n"); else {
                was[x] = 0;
                    for (int i = 1; i * i <= x; i++)
                    if (x % i == 0) {
                        if (i > 1) all[i].erase (x);
                        if (i * i != x) all[x / i].erase (x);
                    }
                printf ("Success\n");
            }
        }   
    }
    return 0;
}