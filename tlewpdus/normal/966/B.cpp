#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll x1, x2;
ll arr[300100];
int ord[300100];

int main() {
    int i;

    scanf("%d%lld%lld",&n,&x1,&x2);
    for (i=0;i<n;i++) ord[i] = i+1;
    for (i=0;i<n;i++)scanf("%lld",&arr[i]);
    sort(ord,ord+n,[](int a, int b){return arr[a-1]<arr[b-1];});
    sort(arr,arr+n);

    for (i=n-2;i>=0;i--) {
        ll k = (x1+arr[i]-1)/arr[i];
        if (n-i-k<1) continue;
        if (x2<=arr[i+k]*(n-i-k)) {
            printf("Yes\n");
            printf("%lld %lld\n",k,n-i-k);
            for (int j=i;j<i+k;j++) printf("%lld ",ord[j]);
            printf("\n");
            for (int j=i+k;j<n;j++) printf("%lld ",ord[j]);
            printf("\n");
            return 0;
        }
    }

    for (i=n-2;i>=0;i--) {
        ll k = (x2+arr[i]-1)/arr[i];
        if (n-i-k<1) continue;
        if (x1<=arr[i+k]*(n-i-k)) {
            printf("Yes\n");
            printf("%lld %lld\n",n-i-k,k);
            for (int j=i+k;j<n;j++) printf("%lld ",ord[j]);
            printf("\n");
            for (int j=i;j<i+k;j++) printf("%lld ",ord[j]);
            printf("\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}