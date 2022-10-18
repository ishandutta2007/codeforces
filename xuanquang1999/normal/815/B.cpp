//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 200005
#define MOD 1000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}



int n, a[maxN];
ll fact[maxN], invFact[maxN], c[2][maxN];
//int b[maxN][maxN];

ll power(ll x, int n) {
    if (n == 0) return 1;
    if (n&1) return (x*power(x, n-1))%MOD;
    ll p = power(x, n/2);
    return (p*p)%MOD;
}

ll C(int n, int k) {
    return ((invFact[k]*invFact[n-k])%MOD * fact[n])%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    fact[0] = invFact[0] = 1;
    fto(i, 1, n) {
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = power(fact[i], MOD-2);
    }
//    fto(n, 1, 16) {
//
//    }
    int k = (n-1)/4;
    fto(i, 0, 2*k) {
        c[0][2*i] = C(2*k, i);
        c[0][2*i+1] = 0;
    }
    bool forw = true;
    fto(i, 4*k+1, n-1) {
        c[1][0] = c[0][0];
        bool isPlus = (i%2 == 0);
        fto(j, 1, i) {
            if (isPlus) c[1][j] = (c[0][j-1]+c[0][j]+MOD)%MOD;
            else if (forw) c[1][j] = (c[0][j-1]-c[0][j]+MOD)%MOD;
            else c[1][j] = (c[0][j]-c[0][j-1]+MOD)%MOD;
            isPlus = !isPlus;
        }
        forw = !forw;
        fto(j, 0, i) c[0][j] = c[1][j];
    }

    ll ans = 0;
    fto(i, 0, n-1) ans = (ans+(a[i]+MOD)*c[0][i])%MOD;
    cout << ans;

//    fto(i, 0, n-1) printf("%lld ", c[0][i]);
//    puts("");

//    fto(n, 1, 16) {
//        fto(k, 0, n-1) {
//            fto(j, 0, n-1) b[0][j] = 0;
//            b[0][k] = 1;
//            int cnt = 0;
//            fto(i, 1, n-1) {
//                fto(j, 0, n-i-1) {
//                    ++cnt;
//                    if (cnt%2 == 1) b[i][j] = b[i-1][j]+b[i-1][j+1];
//                    else b[i][j] = b[i-1][j]-b[i-1][j+1];
//                }
//            }
////            fto(i, 0, n-1) {
////                fto(j, 0, n-i-1) printf("%d ", b[i][j]);
////                puts("");
////            }
////            puts("");
//            printf("%d ", b[n-1][0]);
//        }
//        puts("");
//    }

    return 0;
}
/*
1
1 1
1 2 -1
1 -1 1 -1
1 0 2 0 1
1 1 2 2 1 1
1 2 1 4 -1 2 -1
1 -1 3 -3 3 -3 1 -1
1 0 4 0 6 0 4 0 1
1 1 4 4 6 6 4 4 1 1
1 2 3 8 2 12 -2 8 -3 2 -1
1 -1 5 -5 10 -10 10 -10 5 -5 1 -1
1 0 6 0 15 0 20 0 15 0 6 0 1
1 1 6 6 15 15 20 20 15 15 6 6 1 1
1 2 5 12 9 30 5 40 -5 30 -9 12 -5 2 -1
1 -1 7 -7 21 -21 35 -35 35 -35 21 -21 7 -7 1 -1
*/