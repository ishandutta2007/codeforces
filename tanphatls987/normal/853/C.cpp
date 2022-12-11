#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=3e5+10;

int n,m;
int a[N];
ii q[N<<2];
vector <int> v[N];
ll ans[N];


struct BIT{
    int b[N];
    void add(int x,int v){
        while (x<=n){
            b[x]+=v;
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
}mbit;

void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=m;i++){
        int xa,ya,xb,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        q[i]=ii(ya,yb);
        v[xa-1].push_back(-i);
        v[xb+1].push_back(i);
        ans[i]=1LL*n*(n-1)/2-1LL*(xa-1)*(xa-2)/2-1LL*(ya-1)*(ya-2)/2-1LL*(n-xb)*(n-xb-1)/2-1LL*(n-yb)*(n-yb-1)/2;
//        cout<<ans[i]<<'\n';
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        mbit.add(a[i],1);
        for(auto j:v[i]){
            int sign=(j<0)?-1:1;
            int pos=j*sign;
            if (sign==-1){
                int v1=mbit.get(q[pos].X-1),v2=mbit.get(n)-mbit.get(q[pos].Y);
                ans[pos]+=1LL*v1*(v1-1)/2+1LL*v2*(v2-1)/2;
            }
        }
    }
    memset(mbit.b,0,sizeof(mbit.b));
    for(int i=n;i>=1;i--){
        mbit.add(a[i],1);
        for(auto j:v[i]){
            int sign=(j<0)?-1:1;
            int pos=j*sign;
            if (sign==1){
                int v1=mbit.get(q[pos].X-1),v2=mbit.get(n)-mbit.get(q[pos].Y);
                ans[pos]+=1LL*v1*(v1-1)/2+1LL*v2*(v2-1)/2;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
}
int main(){
    prepare();
    solve();
}