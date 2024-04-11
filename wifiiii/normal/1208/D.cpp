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

ll mx[800005],lz[800005],idx[800005];
void build(int l,int r,int rt)
{
    if(l==r) {cin>>mx[rt];idx[rt]=l;return;}
    int m=(l+r)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    mx[rt]=min(mx[rt<<1],mx[rt<<1|1]);
    if(mx[rt<<1] < mx[rt<<1|1]) idx[rt] = idx[rt<<1];
    else idx[rt] = idx[rt<<1|1];
}
void update(int L,int R,ll val,int l,int r,int rt)
{
    if(L<=l && r<=R) {lz[rt]+=val;mx[rt]+=val;return;}
    int m=(l+r)/2;
    if(lz[rt])
    {
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        mx[rt<<1]+=lz[rt],mx[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    if(m>=L) update(L,R,val,l,m,rt<<1);
    if(m< R) update(L,R,val,m+1,r,rt<<1|1);
    mx[rt]=min(mx[rt<<1],mx[rt<<1|1]);
    if(mx[rt<<1] < mx[rt<<1|1]) idx[rt] = idx[rt<<1];
    else idx[rt] = idx[rt<<1|1];
}
int ans[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    build(1,n,1);
    for(int i=1;i<=n;++i)
    {
        int pos = idx[1];
        ans[pos] = i;
        update(pos,pos,1e18,1,n,1);
        if(pos+1<=n) update(pos+1,n,-i,1,n,1);
    }
    ii cout<<ans[i]<<" ";cout<<endl;
}