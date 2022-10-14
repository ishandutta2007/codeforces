#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
const ll mod=998244353;
vector<int> E[N];
bool was[N],ok=1;
int col[N],cnt[2];
ll ckpow(ll a,ll b){
    if(b==0)return 1;
    ll res=1;
    while(b>0){
        if(b&1)res*=a;
        if(res>=mod)res%=mod;
        b=b>>1;a*=a;
        if(a>=mod)a%=mod;
    }
    return res;
}
void DFS(int u,int c){
    was[u]=1,col[u]=c,cnt[c]++;
    for(int e:E[u]){
        if(was[e]&&col[e]==col[u])ok=0;
        if(!was[e])DFS(e,c^1);
    }
}
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,m;scanf("%i %i",&n,&m);
        for(int i=1;i<=n;i++)E[i].clear(),was[i]=0,col[i]=-1;
        for(int i=1;i<=m;i++){
            int u,v;scanf("%i %i",&u,&v);
            E[u].pb(v);
            E[v].pb(u);
        }
        ok=1;
        ll ans=1;
        for(int i=1;i<=n;i++){
            if(!was[i]){
                cnt[0]=0,cnt[1]=0,DFS(i,0);
                ans*=ckpow((ll)2,(ll)cnt[0])+ckpow((ll)2,(ll)cnt[1]);
                if(ans>=mod)ans%=mod;
            }
        }
        if(!ok){
            printf("0\n");
            continue;
        }else printf("%lld\n",ans);
    }
    return 0;
}