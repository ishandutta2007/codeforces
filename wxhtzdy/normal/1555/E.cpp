#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ff(i,l,r) for (int i=l;i<r;i++)
#define fff(i,l,r) for (int i=l;i<=r;i++)
#define bff(i,l,r) for (int i=r-1;i>=l;i--)
#define bfff(i,l,r) for (int i=r;i>=l;i--)
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf popfront

using namespace std;
long long int typedef li;
long double typedef ld;
pair<int,int> typedef pii;

struct struk
{
    int l,r,w;
}a[300005];

int val[2929292],upd[2929292];
vector<int> b[1000005];

void Upd(int p, int l, int r)
{
    val[p]=min(val[p],upd[p]);
    if(l!=r)
    {
        upd[p*2]=min(upd[p*2],upd[p]);
        upd[p*2+1]=min(upd[p*2+1],upd[p]);
    }
    upd[p]=1e9;
}

void Set(int p, int l, int r, int ll, int rr, int x)
{
    if (ll>r || rr<l) return Upd(p,l,r);
    if (ll<=l && r<=rr) return upd[p]=x,Upd(p,l,r);
    int mid=(l+r)/2;
    Upd(p,l,r),Set(p*2,l,mid,ll,rr,x),Set(p*2+1,mid+1,r,ll,rr,x);
    val[p]=max(val[p*2],val[p*2+1]);
}

int main()
{
    FAST;

    int n,m; cin>>n>>m; m--;
    ff(i,0,n) cin>>a[i].l>>a[i].r>>a[i].w, b[a[i].w].pb(i);

    ff(i,0,2929292) val[i]=1e9,upd[i]=1e9;

    int ans=1e9;
    bfff(i,1,1e6)
    {
        for (int j:b[i]) Set(1,1,m,a[j].l,a[j].r-1,i);
        ans=min(ans,val[1]-i);
    }
    cout<<ans<<"\n";
}