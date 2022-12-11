#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

typedef long long ll;
typedef pair<int,int> ii;


#define X first
#define Y second
int n;
int a[2][N];

vector<ii> v[N];

multiset <ll> mse;
ll f[N];
struct segtree{
        ll laz[N<<2],b[N<<2];
        void lazyupdate(int node,int L,int R){
                b[node]+=laz[node];
                if (L<R) {
                        laz[node*2]+=laz[node];
                        laz[node*2+1]+=laz[node];
                }
                laz[node]=0;
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
                b[node]=min(b[node*2],b[node*2+1]);
        }
}mseg;

void prepare(){
        for(int i=0;i<n;i++) mseg.update(1,0,n-1,i,i,a[1][i]);
        for(int i=1;i<=n;i++){
                for(auto j:v[i]) mseg.update(1,0,n-1,0,j.X-1,j.Y);
                f[i]=mseg.b[1];
        }
        for(int i=1;i<=n;i++) mse.insert(a[0][i]+f[i]);
}
int main(){
        int test,m;
        scanf("%d%d%d",&n,&m,&test);
        for(int i=1;i<n;i++) scanf("%d%d",a[0]+i,a[1]+i);
        while (m--){
                int x,y,wei;
                scanf("%d%d%d",&x,&y,&wei);
                v[x].push_back(ii(y,wei));
        }
        prepare();
        cout<<*mse.begin()<<'\n';
        while (test--){
                int x,wei;
                scanf("%d%d",&x,&wei);
                mse.erase(mse.find(a[0][x]+f[x]));
                a[0][x]=wei;
                mse.insert(a[0][x]+f[x]);
                cout<<*mse.begin()<<'\n';
        }
}