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

int h1, a1, x1, y1;
int h2, a2, x2, y2;

int main () {
    scanf ("%d", &m);
    scanf ("%d%d", &x1, &y1);
    scanf ("%d%d", &h1, &a1);
    scanf ("%d%d", &x2, &y2);
    scanf ("%d%d", &h2, &a2);
    ll cur = 0;
    while (x1 != y1) {
        x1 = ((ll)x1 * h1 + a1) % m;
        x2 = ((ll)x2 * h2 + a2) % m;
        cur++;
        if (cur > m) {
            printf ("-1\n");
            re 0;
        }
    }
    if (x2 != y2) {
        int per = 0;
        int h = 1, a = 0;
        do {
            x1 = ((ll)x1 * h1 + a1) % m;
            x2 = ((ll)x2 * h2 + a2) % m;
            cur++;
            per++;
            h = ((ll)h * h2) % m;
            a = ((ll)a * h2 + a2) % m;
            if (per > m) {
                printf ("-1\n");
                re 0;
            }
        } while (x1 != y1);
        int tmp = 0;
        while (x2 != y2) {
            x2 = ((ll)x2 * h + a) % m;
            cur += per;
            tmp++;
            if (tmp > m) {
                printf ("-1\n");
                re 0;
            }
        }
    }
    cout << cur << endl;
    return 0;
}