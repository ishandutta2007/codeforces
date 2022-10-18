//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 1005
#define EPS 1e-15
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll n, m, ans;

ll mul(ll a, ll b) {
    return ((a%MOD) * (b%MOD))%MOD;
}

ll trinum(ll x) {
    return mul(x, x-1);
}

ll powmod(ll x, ll n) {
    if (n == 0) return 1;
    if (n%2 == 1) return (powmod(x, n-1)*x)%MOD;
    ll p = powmod(x, n/2);
    return (p*p)%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m;

    if (m > n) {
        ans = (2*mul(m-n, n))%MOD;
        m = n;
    }
    fto(d, 1, n) {
        ll r = floor(1.0*n/d), l = ceil(1.0*n/(d+1));
        if (n%(d+1) == 0) ++l;
        ll cnt = r-l+1, lost = max(0LL, r-max(l-1, m));
        ll sum = mul(trinum(cnt)-trinum(lost), d) + 2*mul(cnt-lost, n%r);
//        printf("%d %lld %lld %lld %lld %lld\n", d, cnt, lost, r, l, sum);
        if (r-l+1 == 1) {
            fto(i, 1, min(m, r)) ans = (ans + (n%i)*2)%MOD;
            break;
        }
        ans = (ans + sum)%MOD;
    }

    cout << (ans*powmod(2, MOD-2))%MOD;

    return 0;
}