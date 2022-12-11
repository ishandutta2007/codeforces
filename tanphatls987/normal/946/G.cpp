#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
const int inf=1e9+10;
int n,a[N],p[N],new_a[N];
int f[N][2];

struct BIT{
        int b[N];
        void add(int x,int v,int n=N-1){
                assert(x>0);
                while (x<=n){
                        b[x]=min(b[x],v);
                        x+=x&-x;
                }

        }
        int get(int x){
                int ans=inf;
                while (x){
                        ans=min(ans,b[x]);
                        x-=x&-x;
                }
                return ans;
        }
        void reset(){
                fill(b,b+N,inf);
        }
}mbit[2];

int solve(){
        for(int i=0;i<=1;i++) mbit[i].reset();
        for(int i=1;i<=n;i++){
                if (i>=2) {
                        int ridx=lower_bound(p,p+n+1,new_a[i-2]-1)-p+1;
                        mbit[1].add(ridx,f[i-2][0]-(i-2)-1);
                }
                for(int j=0;j<=1;j++)
                        mbit[j].add(a[i-1],f[i-1][j]-(i-1));
                for(int j=0;j<=1;j++)
                        f[i][j]=mbit[j].get(a[i])+i-1;
        }
        return f[n][1];
}
void prepare(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) a[i]-=i;
        a[++n]=inf;
        a[0]=-inf;
        for(int i=0;i<=n;i++) p[i]=a[i];
        sort(p,p+n+1);
        for(int i=0;i<=n;i++) new_a[i]=a[i];
        for(int i=0;i<=n;i++) a[i]=lower_bound(p,p+n+1,a[i])-p+1;
}
int main(){
        prepare();
        cout<<solve();
}