using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

bool isPrime(int n) {
    if (n < 2) return false;
    int k = trunc(sqrt(n));
    fto(i, 2, k)
        if (n%i == 0) return false;
    return true;
}

int nTest;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        ll n;
        scanf("%I64d", &n);
        ll x = trunc(sqrt(n));
        printf((isPrime(x) && x*x == n) ? "YES\n" : "NO\n");
    }

    return 0;
}