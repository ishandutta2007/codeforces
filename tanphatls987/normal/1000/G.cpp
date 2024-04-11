#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;

int test;
int n;
int v[N][2];
long long wv[N],we[N];
vector <int> e[N];

int depth[N],pv[N][20];
int pe[N],q[N];
void BFS(){
        int top=1,bot=1;
        q[1]=1;
        while (top<=bot){
                int xa=q[top++];
                for(auto i:e[xa]) if (pe[xa]!=i){
                        int xb=v[i][0]+v[i][1]-xa;
                        q[++bot]=xb;
                        pe[xb]=i;
                }
        }
}
void prepare(){
        cin>>n>>test;
        for(int i=1;i<=n;i++) cin>>wv[i];
        for(int i=1;i<n;i++){
                int xa,xb;
                cin>>xa>>xb>>we[i];
                e[xa].push_back(i);
                e[xb].push_back(i);
                v[i][0]=xa;
                v[i][1]=xb;
        }
        BFS();
        for(int i=2;i<=n;i++){
                int xa=q[i];
                int par_xa=v[pe[xa]][0]+v[pe[xa]][1]-xa;
                depth[xa]=depth[par_xa]+1;
                pv[xa][0]=par_xa;
        }
}

long long f1[N],fp[N];
long long pathf[N][20];
void solve(){
        for(int i=n;i>=1;i--){
                int xa=q[i];
                for(auto edge:e[xa]) if (edge!=pe[xa]){
                        int xb=v[edge][0]+v[edge][1]-xa;
                        f1[xa]+=max(0LL,f1[xb]-2*we[edge]+wv[xb]);
                }
        }
        for(int i=1;i<=n;i++){
                int xa=q[i];
                long long sum=fp[xa]+f1[xa];
                for(auto edge:e[xa]) if (edge!=pe[xa]){
                        int xb=v[edge][0]+v[edge][1]-xa;
                        fp[xb]=max(0LL,sum-max(0LL,f1[xb]-2*we[edge]+wv[xb])-2*we[edge]+wv[xa]);
                }
                for(auto edge:e[xa]) if (edge!=pe[xa]){
                        int xb=v[edge][0]+v[edge][1]-xa;
                        pathf[xb][0]=wv[xb]+f1[xa]-we[edge]-max(0LL,f1[xb]-2*we[edge]+wv[xb]);
                }
        }
        for(int j=1;j<20;j++)
                for(int i=1;i<=n;i++)
                {
                        pv[i][j]=pv[pv[i][j-1]][j-1];
                        pathf[i][j]=pathf[i][j-1]+pathf[pv[i][j-1]][j-1];
                }
        //for(int i=1;i<=n;i++) cout<<f1[i]<<" \n"[i==n];
        //for(int i=1;i<=n;i++) cout<<fp[i]<<" \n"[i==n];
}

long long query(int x,int y){
        if (depth[x]<depth[y]) swap(x,y);
        long long ans=f1[x];
        for(int i=0,val=depth[x]-depth[y];val;i++,val>>=1)
                if (val&1){
                        ans+=pathf[x][i];
                        x=pv[x][i];
                }
        if (x==y) {
                ans+=wv[y]+fp[y];
                return ans;
        }
        ans+=f1[y];
        for(int i=int(log2(depth[x]));i>=0;i--) 
                if (pv[x][i]!=pv[y][i]){
                        ans+=pathf[x][i]+pathf[y][i];
                        x=pv[x][i],y=pv[y][i];
                }
        int z=pv[x][0];
        ///from x,y -> z
        ans+=wv[x]+wv[y]+wv[z];
        ans-=we[pe[x]]+we[pe[y]];
        ans+=f1[z]+fp[z]-max(0LL,f1[x]-2*we[pe[x]]+wv[x])-max(0LL,f1[y]-2*we[pe[y]]+wv[y]);
        return ans;
}
int main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        prepare();
        solve();
        while (test--){
                int xa,xb;
                cin>>xa>>xb;
                cout<<query(xa,xb)<<'\n';
        }
}