#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

#define X first
#define Y second

const int N=2e5+10;
const int alp=26;
const int inf=1e9+10;
const int bar=100004;

int n,a[N][2];
vector <int> v[2][2][N];
vector <ii> imp[N];

int f[2][N][2];


struct BIT{
        int b[N<<1];
        void add(int x,int val,int n=2*N-1){
                assert(x>0&&x<2*N);
                while (x<=n){
                        b[x]+=val;
                        x+=x&-x;
                }
        }
        int get(int x){
                int ans=0;
                while (x){
                        ans+=b[x];
                        x-=x&-x;
                }
                return ans;
        }
        void clear(){
                memset(b,0,sizeof(b));
        }
}mbit[2];


void findbound(int re){
        for(int dim=0;dim<=1;dim++){
                for(int i=0;i<N;i++) f[dim][i][0]=inf,f[dim][i][1]=-inf;
                ///go down
                int use=inf;
                for(int i=N-1;i>=0;i--){
                        use++;
                        for(auto j:v[re][dim][i]) use=min(use,j+1);
                        f[dim][i][0]=min(f[dim][i][0],use);
                }
                use=inf;
                for(int i=0;i<N;i++){
                        use++;
                        for(auto j:v[re][dim][i]) use=min(use,j+1);
                        f[dim][i][0]=min(f[dim][i][0],use);
                }
                /// go up
                use=-inf;
                for(int i=N-1;i>=0;i--){
                        use--;
                        for(auto j:v[re][dim][i]) use=max(use,j-1);
                        f[dim][i][1]=max(f[dim][i][1],use);
                }
                use=-inf;
                for(int i=0;i<N;i++){
                        use--;
                        for(auto j:v[re][dim][i]) use=max(use,j-1);
                        f[dim][i][1]=max(f[dim][i][1],use);
                }
        }
}
long long solve(int re){
        findbound(re);
        for(int i=0;i<N;i++) imp[i].clear();
        for(int i=0;i<N;i++) if (f[1][i][0]<=f[1][i][1]){
                imp[f[1][i][0]-1].push_back(ii(i,-1));
                imp[f[1][i][1]].push_back(ii(i,1));
        }
        mbit[0].clear();
        mbit[1].clear();
 
        long long ans=0;
        for(int i=0;i<N;i++) {
                if (f[0][i][0]<=f[0][i][1]){
                        int use=i&1;
                        mbit[use].add(f[0][i][0],1);
                        mbit[use].add(f[0][i][1]+1,-1);
                }
                for(auto cur:imp[i]){
                        int use=(cur.X&1)^re^1;;
                        ans+=mbit[use].get(cur.X)*cur.Y;
                }
                  
        }
        return ans;
}
int main(){
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>a[i][0]>>a[i][1];
                a[i][0]+=100004,a[i][1]+=100004;
                int re=(a[i][0]+a[i][1])&1;
                v[re][0][a[i][0]].push_back(a[i][1]);
                v[re][1][a[i][1]].push_back(a[i][0]);
        }
        long long ans=0;
        for(int re=0;re<=1;re++) ans+=solve(re);
        cout<<ans;
}