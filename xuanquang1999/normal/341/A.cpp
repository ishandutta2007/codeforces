using namespace std;
#include <bits/stdc++.h>
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

ll n, a[maxN], sum1, cursum, sum2;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%I64d", &n);
    fto(i, 1, n) scanf("%I64d", &a[i]);
    a[0] = 0;
    sort(a+1, a+n+1);

    fto(i, 1, n) sum1+=a[i];

    fto(i, 1, (n-1)/2) {
        cursum+=a[n+1-i]-a[i];
        sum2+=2*cursum;
    }
    if ((n-1)%2 == 1) {
        cursum+=a[n/2+1]-a[n/2];
        sum2+=cursum;
    }

    ll sum = sum1+2*sum2;
    ll u = __gcd(sum, n);
    printf("%I64d %I64d", sum/u, n/u);

    return 0;
}