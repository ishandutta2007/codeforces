#include <bits/stdc++.h>

using namespace std;


const int N=1e5+10;
typedef pair<int,int> ii;

#define X first
#define Y second

struct segtree{
        ii a[N];
        ii b[N<<2];
        int laz[N<<2];
        void lazyupdate(int node,int L,int R){
                b[node].X+=laz[node];
                if (L<R){
                        laz[node*2]+=laz[node];
                        laz[node*2+1]+=laz[node];
                }
                laz[node]=0;
        }
        void build(int node,int L,int R){
                if (L==R){
                        b[node]=a[L];
                        return;
                }
                build(node*2,L,(L+R)/2);
                build(node*2+1,(L+R)/2+1,R);
                b[node]=max(b[node*2],b[node*2+1]);
        }
        void update(int node,int L,int R,int l,int r,int val){
                lazyupdate(node,L,R);
                if (L>r||R<l) return;
                if (l<=L&&R<=r){
                        laz[node]+=val;
                        lazyupdate(node,L,R);
                        return;
                }
                update(node*2,L,(L+R)/2,l,r,val);
                update(node*2+1,(L+R)/2+1,R,l,r,val);
                b[node]=max(b[node*2],b[node*2+1]);
        }
}mseg;

int ans[N];
struct graph{
        int n;
        vector <int> v[N];
        int des[N];

        int pa[N];
        int q[N];
        int BFS(int st){
                int top=1,bot=1;
                q[1]=st;
                pa[st]=0;
                while (top<=bot){
                        int x=q[top++];
                        for(auto y:v[x]) if (y!=pa[x]){
                                pa[y]=x;
                                q[++bot]=y;
                        }
                }
                return bot;
        }
        
        int d[N],in[N],out[N];
        int p[N];
        void DFS(int x){
                static int n1=0;
                d[x]=d[pa[x]]+1;
                p[++n1]=x;
                in[x]=n1;
                for(auto y:v[x]) if (!des[y]&&y!=pa[x]) {
                        pa[y]=x;
                        DFS(y);
                }
                out[x]=n1;
                
                
        }
        void prepare(){
                cin>>n;
                for(int i=1;i<n;i++){
                        int x,y;
                        cin>>x>>y;
                        v[x].push_back(y);
                        v[y].push_back(x);
                }
        }
        void solve(){
                ans[1]=1;
                BFS(1);int sx=q[n];
                BFS(sx);int sy=q[n];
                ans[2]=0;
                while (sy){
                        ans[2]++;
                        des[sy]=1;
                        sy=pa[sy];
                }
                for(int i=1;i<=n;i++) if (des[i]){
                        for(auto x:v[i]) if (!des[x]){ 
                                pa[x]=i;
                                DFS(x);
                        }
                }
                
                int n1=n-ans[2];
                if (n1){
                        for(int i=1;i<=n1;i++) mseg.a[i]=ii(d[p[i]],p[i]);

                        mseg.build(1,1,n1);
                        for(int i=1;i<=n1;i++){
                                int x=mseg.b[1].Y;
                                ans[2+i]=ans[2+i-1]+mseg.b[1].X;
                                while (!des[x]){
                                        mseg.update(1,1,n1,in[x],out[x],-1);
                                        des[x]=1;
                                        x=pa[x];
                                }
                        }
                }
                for(int i=3+n1;i<=n;i++) ans[i]=n;
                
                for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        }

}mgraph;
int main(){
        mgraph.prepare();
        mgraph.solve();
}