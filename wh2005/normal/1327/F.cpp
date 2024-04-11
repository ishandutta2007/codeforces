#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
const ll mod=998244353;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}
const int MAXN=5e5+7;
int n,m,k;
vector<pii> vec[MAXN];
pii q[MAXN];
int main(){
    // freopen("rand.in","r",stdin);
    scanf("%d%d%d",&n,&k,&m);k--;
    for(ri i=1;i<=m;++i) {
        int l,r,w;scanf("%d%d%d",&l,&r,&w);
        vec[r].push_back((pii){l,w});
    }
    int ans=1;
    for(ri t=0;t<=k;++t){
        int l=1,r=0,tot=1;
        q[++r]=(pii){0,1};
        for(ri i=1;i<=n;++i){
            q[++r]=(pii){i,tot};
            tot=add(tot,tot);
            for(auto w:vec[i]){
                if(w.second>>t&1){
                    while(l<=r&&q[r].first>=w.first) tot=dec(tot,q[r--].second);
                }
                else{
                    while(l<=r&&q[l].first<w.first)  tot=dec(tot,q[l++].second);
                }
            }
            if(!tot) break;
        }
        ans=1ll*ans*tot%mod;
    }
    printf("%d\n",ans);
}