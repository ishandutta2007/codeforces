#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+10,mod=998244353;
struct edge{
    long long to,nxt;
};
edge ed[N<<1];
long long cnt,h[N];
void add(long long st,long long et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
long long deg[N],n,t,m,a[N];
void fix(long long &x){
    while(x>2*mod)x-=mod;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        vector<pair<long long,long long>>vec[N];
        for(long long i=1;i<=n;i++){
            long long x;
            h[i]=0;
            scanf("%lld",&x);
            vec[i].push_back({0,x});
        }
        cnt=0;
        for(long long i=1;i<=m;i++){
            long long x,y;
            scanf("%lld%lld",&x,&y);
            add(x,y);
            deg[y]++;
        }
        queue<long long>q;
        for(long long i=1;i<=n;i++)if(!deg[i])q.push(i);
        long long ans=0;
        while(q.size()){
            long long x=q.front();
            q.pop();
            stable_sort(vec[x].begin(),vec[x].end());
            vector<pair<long long,long long>>now;
            pair<long long,long long>kk={0,0};
            for(auto [p,q]:vec[x]){
                if(p<=kk.first+kk.second)kk.second+=q,fix(kk.second);
                else{
                    now.push_back(kk);
                    kk={p,q};
                }
            }
            now.push_back(kk);
            ans=now.back().first+now.back().second;
            for(int i=h[x];i;i=ed[i].nxt){
                int v=ed[i].to;
                for(auto [p,q]:now)if(q)vec[v].push_back({p+1,q});
                deg[v]--;
                if(!deg[v])q.push(v);
            }
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}