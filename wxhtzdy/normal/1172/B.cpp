#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
    int n;
    scanf("%i",&n);
    map<int,int> cnt;
    for(int i=0,u,v;i<n-1;i++)scanf("%i %i",&u,&v),cnt[u]++,cnt[v]++;
    long long ans=n;
    for(int i=1;i<=n;i++)for(int j=1;j<=cnt[i];j++)ans*=j,ans%=mod;
    printf("%lld",ans);
    return 0;
}