#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

void solve(){
    ll a, b, c, d, k1, k2, k3, k4, A, B, C;
    long double D;
    int fl = 0;
    double x, cur;
    cin >> a >> b >> c >> d;
    if (a * d == b * c){
        printf("0.0000000000\n");
        return;
    }
    for(int mask = 0; mask < 16; mask++){
        k1 = k2 = k3 = k4 = 1;
        if (mask & 1){
            k1 = -1;
        }
        if (mask & 2){
            k2 = -1;
        }
        if (mask & 4){
            k3 = -1;
        }
        if (mask & 8){
            k4 = -1;
        }
        A = k1 * k4 - k2 * k3;
        B = k1 * d + k4 * a - k2 * c - k3 * b;
        C = a * d - b * c;
        //printf("%lld %lld %lld\n", A, B, C);
        if (A == 0){
            if (B == 0){
                if (C == 0){
                    x = 0.;
                    fl = 1;
                }
            } else {
                cur = fabs(-C / (B + 0.));
                //printf("%d %lld %lld %lld\n", mask, A, B, C);
                //printf("# %.12lf\n", cur);
                if (!fl || x > cur){
                    fl = 1;
                    x = cur;
                }
            }
        } else {
            D = ((long double)B) * ((long double)B) - (long double)4 * A * C;
            if (D >= -EPS){
                if (D < 0.){
                    D = 0.;
                }
                cur = fabs((-B + sqrt(D + 0.)) / (2. * A));
                //printf("## %.12lf\n", cur);

                if (!fl || x > cur){
                    fl = 1;
                    x = cur;
                }
                cur = fabs((-B - sqrt(D + 0.)) / (2. * A));
                //printf("### %.12lf\n", cur);

                if (!fl || x > cur){
                    fl = 1;
                    x = cur;
                }
                
            }
        }
        //printf("%.12lf\n", x);
    }
    printf("%.12lf\n", x);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}