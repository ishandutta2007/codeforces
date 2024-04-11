#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;

long long ans=0;
int n;
int a[maxn];
vector<pair<int,int> > vec;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        int m;
        scanf("%d",&m);
        for (int j=1;j<=m;++j){
            scanf("%d",&a[j]);
        }
        bool fg=0;
        for (int j=1;j<m;++j){
            if (a[j]<a[j+1]) fg=1;
        }
        if (!fg) vec.push_back({2*a[1]-1,-1}), vec.push_back({2*a[m],1});
    }
    int val=0;
    sort(vec.begin(),vec.end());
    for (auto c:vec){
        if (c.second>0) ans+=val;
        else val++;
    }
    ans=1ll*n*n-ans;
    printf("%lld\n",ans);
    return 0;
}