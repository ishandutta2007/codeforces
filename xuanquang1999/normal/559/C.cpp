//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 200005
#define maxK 2005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, m, k;
ll fact[2*maxN], invFact[2*maxN], dp[maxK];
vector<ii> S;

ll power(ll x, ll n) {
    if (n == 0) return 1;
    if (n%2 == 1) return (x*power(x, n-1))%MOD;
    ll p = power(x, n/2);
    return (p*p)%MOD;
}

ll f(ii a, ii b) {
    int x = b.ff-a.ff, y = b.ss-a.ss;
    return ((fact[x+y]*invFact[x])%MOD * invFact[y])%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fact[0] = 1;
    fto(i, 1, n+m) fact[i] = (fact[i-1]*i)%MOD;
    fto(i, 0, n+m) invFact[i] = power(fact[i], MOD-2);

    S.resize(k+1);
    fto(i, 0, k-1) scanf("%d%d", &S[i].ff, &S[i].ss);
    S[k] = mp(n, m);
    sort(S.begin(), S.end());

    dp[0] = f(mp(1, 1), S[0]);
    fto(i, 1, k) {
        dp[i] = f(mp(1, 1), S[i]);
        fto(j, 0, i-1) {
            if (S[j].ss <= S[i].ss) dp[i] = (dp[i]+dp[j]*(MOD-f(S[j], S[i])))%MOD;
        }
    }

    cout << dp[k];

    return 0;
}