#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT
 
using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;
 
template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
 
int n;
int m;
int x[200000];
map<int, int> num;

int main () {
    int tt;
    scanf ("%d", &tt);
    for (int it = 0; it < tt; it++) {
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int ok = 1;
                for (int a = i; a < j && ok; a++)
                    for (int b = a + 1; b < j && ok; b++)
                        ok &= 1 - int ((x[a] <= x[b] && x[b] <= x[j]) || (x[a] >= x[b] && x[b] >= x[j]));
                if (!ok) break;
                ans++;                        
            }
        }
        printf ("%d\n", ans);
    }
    re 0;
}