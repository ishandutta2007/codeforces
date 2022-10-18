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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

const int MOD = 1000000007;

int powM(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return ((ll)x*powM(x, n-1))%MOD;
    int p = powM(x, n/2);
    return ((ll)p*p)%MOD;
}

int f, w, h, fact[maxN], invFact[maxN];

int C(int n, int k) {
    if (k > n) return 0;
    return ((ll)fact[n]*(((ll)invFact[k]*invFact[n-k])%MOD))%MOD;
}

int Calc(ll s, int k) {
    if (s < 0) return 0;
    if (s == 0) return 1;
    return C(k+s-1, k-1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    //debug((2LL*powM(3, MOD-2, MOD))%MOD);
    //debug((4LL*powM(6, MOD-2, MOD))%MOD);
    fact[0] = invFact[0] = 1;
    fto(i, 1, maxN-1) {
        fact[i] = ((ll)fact[i-1]*i)%MOD;
        invFact[i] = powM(fact[i], MOD-2);
    }

    scanf("%d%d%d", &f, &w, &h);
    if (w == 0) {puts("1"); return 0;}

//    debug(Calc(1, 2));

    int p = 0, q = 0;
    fto(i, 1, w) {
//        if (i%100 == 0) debug(i);
//        printf("%d %d %d %d\n", i, f-(i-1), w-i, w-(h+1)*i);
//        debug((ll)Calc(f-(i-1), i+1)*Calc(w-i, i));
//        debug((ll)Calc(f-(i-1), i+1)*Calc(w-(h+1)*i, i));
        q = (q+(ll)Calc(f-(i-1), i+1)*Calc(w-i, i))%MOD;
        p = (p+(ll)Calc(f-(i-1), i+1)*Calc(w-(ll)(h+1)*i, i))%MOD;
    }
//    debug(q);
//    debug(p);

    printf("%d", ((ll)p*powM(q, MOD-2))%MOD);


    return 0;
}