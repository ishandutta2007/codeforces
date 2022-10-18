//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define MOD 1000000007
#define oo 1000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int GCD(int a, int b) {return (b == 0) ? a : GCD(b, a%b);}

ll n, k;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

//    f[1] = 1;
//    fto(n, 2, 25) {
//        int cnt = 0;
//        fto(i, 1, n-1) {
//            if (GCD(i, n-i) == 1) ++cnt;
//        }
//        f[n] = cnt;
//        printf("%d %d\n", n, cnt);
//    }
//
//    fto(n, 1, 25) {
//        int cnt = 0;
//        fto(i, 1, n) {
//            if (n%i == 0) cnt += f[i];
//        }
//        g[n] = cnt;
//        printf("%d %d\n", n, cnt);
//    }

    cin >> n >> k;
    k = min(50LL, (k+1)/2);
    fto(i, 1, k) {
        ll f = 1;
        fto(i, 2, sqrt(n)) {
    //        debug(i);
            if (n%i == 0) {
                ll cur = i-1; n /= i;
                while (n%i == 0) {
                    n /= i;
                    cur *= i;
                }
                f *= cur;
            }
        }
        if (n > 1) f *= n-1;
        n = f;
    }
    cout << n%MOD;

    return 0;
}