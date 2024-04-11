using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(ll i = r; i >= l; --i)
#define fto(i, l, r) for(ll i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define e 1000000007

ll n, k, a[maxN], sum, ans, e10[maxN], fact[maxN];
char s[maxN];

ll powM(ll x, ll n) {
    if (n == 0) return 1;
    ll p = powM(x, n/2);
    if (n%2 == 0) return (p*p)%e;
    else return ((p*p)%e * x)%e;
}

ll C(int k, int n) {
    if (k < 0 || k > n) return 0;
    return (fact[n]*powM((fact[k]*fact[n-k])%e, e-2))%e;

}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> k;
    scanf("%s", &s);
    fto(i, 1, n) {
        a[i] = s[i-1]-48;
        sum+=a[i];
    }

    if (k == 0) {
        fto(i, 1, n) ans = (ans*10+a[i])%e;
        cout << ans;
        return 0;
    }

//    fto(i, 1, n) cout << a[i];
//    cout << endl;

    e10[0] = 1;
    fto(i, 1, n) e10[i] = (e10[i-1]*10)%e;

    fact[0] = 1;
    fto(i, 1, n) fact[i] = (fact[i-1]*i)%e;

    fto(m, 0, n-2) {
        sum-=a[n-m];
        ans = (ans + ((sum*e10[m])%e * C(k-1, n-m-2)))%e;
        //cout << ans << endl;
    }

    sum = 0;
    fdto(i, n, 1) {
        sum = (sum+a[i]*e10[n-i])%e;
        ans = (ans+sum*C(k-1, i-2))%e;
    }

    cout << ans;

    return 0;
}