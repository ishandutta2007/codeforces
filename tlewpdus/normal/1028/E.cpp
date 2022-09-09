#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
ll brr[150000];
ll arr[150000];

int main() {
    int i;

    scanf("%d",&n);
    bool flag = 1;
    for (i=0;i<n;i++) {
        scanf("%d",&brr[i]);
        if (brr[i]!=brr[0]) flag = 0;
    }
    if (flag) {
        if (brr[0]==0) {
            printf("YES\n");
            for (i=0;i<n;i++) printf("1 ");
            printf("\n");
            return 0;
        }
        printf("NO\n");
        return 0;
    }
    int t = -1;
    for (i=0;i<n;i++) {
        if (brr[i]<brr[(i+1)%n]){
            t = (i+1)%n;
            break;
        }
    }
    if (t<0) {
        printf("NO\n");
        return 0;
    }
    arr[t] = brr[t];
    arr[(t+n-1)%n] = arr[t]*200000LL+brr[(t+n-1)%n];
    for (i = (t+n-1)%n+n-1;i>(t+n-1)%n+1;i--) {
        arr[i%n] = arr[(i+1)%n]+brr[i%n];
    }
    printf("YES\n");
    for (i=0;i<n;i++) printf("%lld ",arr[i]);
    printf("\n");

    return 0;
}