#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
ll t;
ll a[200100], x[200100];
ll bmin[200100], bmax[200100];

void pung() {
    printf("No\n");
    exit(0);
}

int main() {
    int i, flag = 1;

    scanf("%d%lld",&n,&t);
    for (i=0;i<n;i++) scanf("%lld",&a[i]);
    for (i=0;i<n;i++) {
        scanf("%lld",&x[i]);
        x[i]--;
    }
    for (i=1;i<n;i++) if (x[i-1]>x[i]) flag = 0;
    for (i=0;i<n;i++) if (x[i]<i) flag = 0;
    if (!flag) pung();
    for (i=0;i<n;i++) bmax[i] = 3e18+1234;
    for (i=0;i<n;i++) {
            bmin[i]++; bmin[x[i]]--;
            if (x[i]!=n-1) bmax[x[i]] = min(bmax[x[i]],a[x[i]+1]+t-1);
    }
    for (i=1;i<n;i++) bmin[i] += bmin[i-1];
    for (i=0;i<n;i++) {
        bmin[i] = (bmin[i]?a[i+1]+t:a[i]+t);
        if (i) bmin[i] = max(bmin[i],bmin[i-1]+1);
        if (bmin[i]>bmax[i]) flag = 0;
    }
    if (!flag) pung();
    printf("Yes\n");
    for (i=0;i<n;i++) printf("%lld ",bmin[i]);
    printf("\n");

    return 0;
}