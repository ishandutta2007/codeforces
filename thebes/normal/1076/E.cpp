#include <bits/stdc++.h>
using namespace std;

const int MN = 4e5+5;
typedef long long ll;
struct idk{ll a, b, c;}q[MN], t[2*MN];
ll n, m, i, j, k, x, y, w, nxt, vis[MN][2], st[3*MN], lz[3*MN], dep[MN], wew[MN], ans[MN];
vector<ll> adj[MN];
void dfs(ll n,ll p,ll d){
        dep[n]=d; vis[n][0]=++nxt;
        for(auto v : adj[n])
                if(v != p) dfs(v, n, d+1);
        vis[n][1]=nxt;
}
inline void push_down(ll i,ll s,ll e){
        if(!lz[i]) return;
        st[i] += lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i]=0;
}
void upd(ll i,ll s,ll e,ll ss,ll se,ll val){
        if(lz[i]) push_down(i,s,e);
        if(s>=ss&&e<=se) lz[i]=val, push_down(i,s,e);
        else{
                if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val);
                else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val);
                else upd(2*i,s,(s+e)/2,ss,se,val), upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        }
}
ll qu(ll i,ll s,ll e,ll ind){
        if(lz[i]) push_down(i,s,e);
        if(s==e) return st[i];
        else if((s+e)/2<ind) return qu(2*i+1,(s+e)/2+1,e,ind);
        else return qu(2*i,s,(s+e)/2,ind);
}
int main(){
        for(scanf("%lld",&n),i=1;i<n;i++){
                scanf("%lld%lld",&x,&y);
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        for(i=1;i<=n;i++) wew[i]=i;
        dfs(1, 0, 1);
        sort(wew+1,wew+n+1,[](ll i,ll j){return vis[i][0]<vis[j][0];});
        for(scanf("%lld",&m),i=1;i<=m;i++){
                scanf("%lld%lld%lld",&q[i].a,&q[i].b,&q[i].c);
                t[2*i-1].a=vis[q[i].a][0];t[2*i-1].b=i;t[2*i-1].c=0LL;
                t[2*i].a=vis[q[i].a][1]+1;t[2*i].b=i;t[2*i].c=1LL;
        }
        sort(t+1,t+2*m+1,[](idk i,idk j){return i.a<j.a;});
        for(i=j=k=1;k<=3*n;k++){
                while(i<=2*m&&t[i].a<=k){
                        ll id = t[i].b, coef = t[i].c? -1:1;
                        ll d2 = min(n,dep[q[id].a]+q[id].b);
                        upd(1,1,n,dep[q[id].a],d2,coef*q[id].c); i++;
                }
                while(j<=n&&vis[wew[j]][0]<=k){
                        ans[wew[j]]=qu(1,1,n,dep[wew[j]]);
                        j++;
                }
        }
        for(i=1;i<=n;i++) printf("%lld ",ans[i]);
        printf("\n");
        return 0;
}