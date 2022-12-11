#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
struct graph{
        int n,m;
        int v[N][2];
        vector <int> e[N];
        
        int depth[N];
        int pa[N][20],pe[N];
        int f[N];
        int ans[N];
        int in_tree[N],sub[N];
        int LCA(int x,int y){
                if (depth[x]<depth[y]) swap(x,y);
                for(int i=0,val=depth[x]-depth[y];val;i++,val>>=1)
                        if (val&1) x=pa[x][i];
                if (x==y) return x;
                for(int i=int(log2(depth[x]));i>=0;i--)
                        if (pa[x][i]!=pa[y][i])
                                x=pa[x][i],y=pa[y][i];
                return pa[x][0];
        }
        void prepare(){
                cin>>n>>m;
                for(int i=1;i<=m;i++){
                        int x,y;
                        cin>>x>>y;
                        v[i][0]=x;v[i][1]=y;
                        e[x].push_back(i);
                        e[y].push_back(i);
                }
        }
        int q[N];
        void BFS(int st){
                static int top=1,bot=0;
                q[++bot]=st;
                pa[st][0]=0;
                depth[st]=1;
                while (top<=bot){
                        int x=q[top++];
                        for(auto i:e[x]){
                                int y=v[i][0]+v[i][1]-x;
                                if (depth[y]) continue;
                                pa[y][0]=x;
                                pe[y]=i;
                                depth[y]=depth[x]+1;
                                q[++bot]=y;
                        }
                }
        }
        void answer(){
                prepare();
                for(int i=1;i<=n;i++) if (!depth[i])
                        BFS(i);
                for(int j=1;j<20;j++)
                        for(int i=1;i<=n;i++) pa[i][j]=pa[pa[i][j-1]][j-1];
                for(int i=1;i<=n;i++) in_tree[pe[i]]=1;

                for(int i=1;i<=m;i++) if (!in_tree[i]){
                        sub[v[i][0]]++;
                        sub[v[i][1]]++;
                        sub[LCA(v[i][0],v[i][1])]-=2;
                }
                for(int i=n;i>=1;i--){
                        int x=q[i];
                        sub[pa[x][0]]+=sub[x]; 
                }
                for(int i=1;i<=n;i++){
                        int x=q[i];
                        f[x]=f[pa[x][0]];
                        if (sub[x]==1) f[x]++;
                        else f[x]=0;
                }
                for(int i=1;i<=m;i++) if (!in_tree[i]){
                        int z=LCA(v[i][0],v[i][1]);
                        if (f[v[i][0]]<depth[v[i][0]]-depth[z]) continue;
                        if (f[v[i][1]]<depth[v[i][1]]-depth[z]) continue;
                        ans[i]=1;
                }
                memset(sub,0,sizeof(sub));
                for(int i=1;i<=m;i++) if (ans[i]){
                        sub[v[i][0]]++;
                        sub[v[i][1]]++;
                        sub[LCA(v[i][0],v[i][1])]-=2;
                }
                for(int i=n;i>=1;i--){
                        int x=q[i];
                        if (sub[x]==1) ans[pe[x]]=1;
                        sub[pa[x][0]]+=sub[x]; 
                }
                int nans=count(ans+1,ans+m+1,1);
                cout<<nans<<'\n';
                for(int i=1;i<=m;i++) if (ans[i]) cout<<i<<" ";
        }
}mgr;

int main(){
        mgr.answer();
}