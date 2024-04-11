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
#define maxK 20
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

ll power(ll x, int n) {
    if (n == 0) return 1;
    if (n&1) return (x*power(x, n-1))%MOD;
    ll p = power(x, n/2);
    return (p*p)%MOD;
}

int n, fr[maxN];
char s[maxN];
ll fact[maxN], invFact[maxN];

ll Calc(int n, int k) {
    return ((fact[n]*invFact[k])%MOD * invFact[n-k])%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", s); n = strlen(s);

    fact[0] = invFact[0] = 1;
    fto(i, 1, n) {
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = power(fact[i], MOD-2);
    }

    fdto(i, n-1, 0) fr[i] = fr[i+1] + (s[i] == ')');

    int cnt = 0, ans = 0;
    fto(i, 0, n-1) {
        if (s[i] == '(') {
            if (fr[i+1] > 0) ans = (ans+Calc(cnt+fr[i+1], fr[i+1]-1))%MOD;
            ++cnt;
        }
    }

    printf("%d", ans);

    return 0;
}