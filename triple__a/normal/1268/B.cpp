#include<bits/stdc++.h>

using namespace std;

const int maxn=300007;
int n,a[maxn];
long long ans[2];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i){
        ans[i%2]+=a[i]/2;
        ans[(i+1)%2]+=a[i]/2+(a[i]&1);
    }
    printf("%lld\n",min(ans[0],ans[1]));
    return 0;
}