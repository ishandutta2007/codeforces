#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int c[200005];
ll lz[800005];
void update(int L,int R,int val,int l,int r,int rt)
{
    if(L<=l && r<=R) {lz[rt]+=val;return;}
    int m = (l+r)/2;
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    if(L<=m) update(L,R,val,l,m,rt<<1);
    if(m< R) update(L,R,val,m+1,r,rt<<1|1);
}
ll query(int pos,int l,int r,int rt)
{
    if(l==r) return lz[rt];
    int m = (l+r)/2;
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    if(pos <= m) return query(pos,l,m,rt<<1);
    return query(pos,m+1,r,rt<<1|1);
}
int main()
{
    int n,m;
    cin>>n>>m;
    ij cin>>c[i];
    for(int i=1;i<m;++i)
    {
        int a=c[i],b=c[i+1];
        if(a==b) continue;
        if(a>b) swap(a,b);
        if(a>1) update(1,a-1,b-a,1,n,1);
        update(a,a,b-1,1,n,1);
        if(a+1<=b-1) update(a+1,b-1,b-a-1,1,n,1);
        update(b,b,a,1,n,1);
        if(b+1<=n) update(b+1,n,b-a,1,n,1);
    }
    for(int i=1;i<=n;++i) cout<<query(i,1,n,1)<<" ";cout<<endl;
}