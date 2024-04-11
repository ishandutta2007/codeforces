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

ll sum[4000005],lz[4000005];
void update(int L,int R,int val,int l,int r,int rt)
{
    if(L<=l && r<=R) {sum[rt]+=val;lz[rt]+=val;return;}
    if(lz[rt])
    {
        sum[rt<<1]+=lz[rt],sum[rt<<1|1]+=lz[rt];
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    int m=(l+r)/2;
    if(m>=L) update(L,R,val,l,m,rt<<1);
    if(m< R) update(L,R,val,m+1,r,rt<<1|1);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
ll ans[1000005];
void print(int l,int r,int rt)
{
    if(l==r) {ans[l]=sum[rt];return;}
    if(lz[rt])
    {
        sum[rt<<1]+=lz[rt],sum[rt<<1|1]+=lz[rt];
        lz[rt<<1]+=lz[rt],lz[rt<<1|1]+=lz[rt];
        lz[rt]=0;
    }
    int m=(l+r)/2;
    print(l,m,rt<<1);
    print(m+1,r,rt<<1|1);
}
int a[1000005],tmp[1000005],q[1000005],head=1,tail=0;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        for(int i=1;i<=k;++i) cin>>a[i];
        if(k*2 >= m)
        {
            head=1,tail=0;
            for(int i=1;i<=m;++i)
            {
                if(head<=tail && q[head]<i-m+k) head++;
                if(i<=k)
                {
                    while(head<=tail && a[q[tail]]<a[i]) tail--;
                    q[++tail]=i;
                }
                tmp[i]=a[q[head]];
            }
            for(int i=1;i<=m-k;++i) tmp[i]=max(tmp[i],0);
            for(int i=k+1;i<=m;++i) tmp[i]=max(tmp[i],0);
            for(int i=1;i<=m;++i) update(i,i,tmp[i],1,m,1);
        }
        else
        {
            for(int i=1;i<=k;++i) tmp[i] = max(tmp[i-1], a[i]);
            for(int i=m;i>=m-k+1;--i) tmp[i] = max(tmp[i+1], a[i-m+k]);
            for(int i=1;i<=k;++i) update(i,i,tmp[i],1,m,1);
            for(int i=m;i>=m-k+1;--i) update(i,i,tmp[i],1,m,1);
            update(k+1,m-k,tmp[k],1,m,1);
        }
    }
    print(1,m,1);
    for(int i=1;i<=m;++i) cout<<ans[i]<<" ";cout<<endl;
}