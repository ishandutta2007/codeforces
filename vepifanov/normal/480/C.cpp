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

const int mod = 1000*1000*1000+7;

int n;
int m;
int a, b, k;
int res[5001];
int sum[5001];

int main () {
    scanf ("%d%d%d%d", &n, &a, &b, &k); a--; b--;
    for (int i = 0; i < n; i++) res[i] = 1;
    for (int i = 0; i < k; i++) {
        sum[n] = 0;
        for (int j = n - 1; j >= 0; j--) sum[j] = (sum[j + 1] + res[j]) % mod;
        for (int j = 0; j < n; j++) {
            if (j != b) {
                int t = abs (j - b) - 1;
//              printf ("%d = %d %d\n", j, max (j - t, 0), min (n - 1, j + t));
                res[j] = ((sum[max (j - t, 0)] - sum[min (n, j + t + 1)] + mod) % mod - res[j] + mod) % mod;
            } else res[j] = 0;                                        
//          printf ("%d %d = %d\n", i + 1, j, res[j]);
        }
    }
    printf ("%d\n", res[a]);
    return 0;
}