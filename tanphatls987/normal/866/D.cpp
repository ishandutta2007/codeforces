#include <bits/stdc++.h>

using namespace std;


const int N=3e5+10;

int n,a[N],p[N];

bool comp(const int& x,const int& y){
        return a[x]<a[y];
}
struct seg_tree{
        int low[N<<2],laz[N<<2];
        void lazyupdate(int node,int L,int R){
                low[node]+=laz[node];
                if (L<R){
                        laz[node*2]+=laz[node];
                        laz[node*2+1]+=laz[node];
                }
                laz[node]=0;
        }
        void update(int node,int L,int R,int l,int r,int val){
                lazyupdate(node,L,R);
                if (L>r||R<l) return;
                if (l<=L&&R<=r) {
                        laz[node]+=val;
                        lazyupdate(node,L,R);
                        return;
                }
                update(node*2,L,(L+R)/2,l,r,val);
                update(node*2+1,(L+R)/2+1,R,l,r,val);
                low[node]=min(low[node*2],low[node*2+1]);
        }
}mseg;
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];

        long long ans=0;
        for(int i=1;i<=n;i++) ans-=a[i];
        for(int i=1;i<=n;i++) p[i]=i;
        sort(p+1,p+n+1,comp);
        
        for(int i=1;i<=n;i++) mseg.update(1,1,n,i,n,1);
        for(int i=n;i>=1;i--){
                for(int j=0;j<=1;j++){
                        mseg.update(1,1,n,p[i],n,-1);
                        if (mseg.low[1]<0)
                                mseg.update(1,1,n,p[i],n,1);
                        else ans+=a[p[i]];
                }
        }
        cout<<ans;
}