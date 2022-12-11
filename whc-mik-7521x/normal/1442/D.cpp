#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,k,t[N];
vector<int>a[N];
long long s[N];
vector<long long>solve(int l,int r){
    vector<long long>res(k+1,0);
    if(l==r){
        for(int i=1;i<=min(t[l],k);i++)res[i]=res[i-1]+a[l][i-1];
        return res;
    }
    int mid=(l+r)>>1;
    auto fl=solve(l,mid),fr=solve(mid+1,r);
    for(int i=l;i<=mid;i++)for(int o=k;o>=t[i];o--)fr[o]=max(fr[o],fr[o-t[i]]+s[i]);
    for(int i=mid+1;i<=r;i++)for(int o=k;o>=t[i];o--)fl[o]=max(fl[o],fl[o-t[i]]+s[i]);
    for(int i=0;i<=k;i++)res[i]=max(fl[i],fr[i]);
    return res;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        for(int o=1;o<=t[i];o++){
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
            s[i]+=x;
        }
    }
    printf("%lld\n",solve(1,n)[k]);
    return 0;
}