#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
double ans;
long long n, k, m, a[MN], i, tot;

int main(){
    for(scanf("%lld%lld%lld",&n,&k,&m),i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        tot += a[i];
    }
    ans = max(ans, (tot+min(k*n,m))/(double)n);
    sort(a+1,a+n+1);
    for(i=1;i<n;i++){
        tot -= a[i];
        if(i<=m) ans = max(ans, (tot+min(k*(n-i),m-i))/(double)(n-i));
    }
    printf("%.6f\n",ans);
    return 0;
}