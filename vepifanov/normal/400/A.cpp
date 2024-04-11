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

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vii v;
        for (int j = 1; j <= 12; j++)
            if (12 % j == 0) {
                int ok = 0;
                int k = 12 / j;
                for (int b = 0; b < k; b++) {
                    int ok2 = 1;
                    for (int a = 0; a < j; a++)
                        if (s[a * k + b] != 'X')
                            ok2 = 0;
                    if (ok2) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) v.pb (mp (j, 12 / j));
            }
        printf ("%d", sz (v));
        for (int i = 0; i < sz (v); i++)
            printf (" %dx%d", v[i].fi, v[i].se);
        printf ("\n");
    }
    return 0;
}