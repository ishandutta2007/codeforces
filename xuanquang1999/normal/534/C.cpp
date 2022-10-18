#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ll long long
#define maxN 200005
using namespace std;
ll a[maxN];
int n;
ll A, s;

int main() {
    scanf("%d%I64d", &n, &A);
    fto(i, 0, n-1) {
        scanf("%I64d", &a[i]);
        s+=a[i];
    }

    fto(i, 0, n-1) {
        ll r = A-(n-1), l = A-(s-a[i]);
        ll ans = max((ll)0, min(r, a[i])-max(l, (ll)1)+1);
        printf("%I64d ", a[i]-ans);
    }
}