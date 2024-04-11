#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> cnt;
int main(){
    int n;scanf("%d",&n);
    vector<int> x(n+1),y(n+1);
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        cnt[{x[i]+x[j],y[i]+y[j]}]++;
    long long ans=0;
    for(auto&c:cnt){
        ans+=c.second*1LL*(c.second-1)/2;
    }
    printf("%lld",ans);
    return 0;
}