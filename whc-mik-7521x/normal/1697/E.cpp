#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10,mod=998244353;
long long fac[N],inv[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N-1]=fp(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(long long x,long long y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long A(long long x,long long y){
    return fac[x]*inv[x-y]%mod;
}
int n,px[N],py[N],vis[N],dp[N];
int dis(int x,int y){
    return abs(px[x]-px[y])+abs(py[x]-py[y]);
}
vector<int>vec[N];
void dfs(int x,auto &it){
    if(it.count(x))return;
    it.insert(x);
    for(int i:vec[x])dfs(i,it);
}
int main(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&px[i],&py[i]);
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            if(o==i)continue;
            if(vec[i].size()){
                if(dis(vec[i].back(),i)==dis(i,o))vec[i].push_back(o);
                else if(dis(vec[i].back(),i)>dis(i,o))vec[i].clear(),vec[i].push_back(o);
            }
            else vec[i].push_back(o);
        }
    }
    vector<int>res;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        int d=dis(i,vec[i].back()),pd=0;
        set<int>st;
        dfs(i,st);
        for(int o:st){
            for(int j:st){
                if(o!=j&&dis(o,j)!=d)pd=1;
            }
        }
        if(!pd){
            for(int o:st)vis[o]=1;
            res.push_back(st.size());
        }
        else res.push_back(1);
        vis[i]=1;
    }
    dp[0]=1;
    for(int i:res){
        for(int o=100;o>=1;o--)dp[o]=((i==1?0:dp[o-1])+(o>=i?dp[o-i]:0))%mod;
        dp[0]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=1ll*dp[i]*A(n,i)%mod;
        ans%=mod;
    }
    printf("%d",ans);
    return  0;
}