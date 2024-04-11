#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct node
{
    int sum,ls,rs;
}t[1000000*40+5];
int cnt,root[maxn+5];
void init()
{
    cnt=0;
    t[0].sum=0;
}
void upd(int l,int r,int &x,int y,int pos)
{
    t[x=++cnt]=t[y];t[x].sum++;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(pos<=mid) upd(l,mid,t[x].ls,t[y].ls,pos);
    else upd(mid+1,r,t[x].rs,t[y].rs,pos);
}
int query(int l,int r,int x,int y,int pos)
{
    if(l>=pos) return t[y].sum-t[x].sum;
    if(r<pos) return 0;
    int mid=(l+r)>>1;
    return query(l,mid,t[x].ls,t[y].ls,pos)+query(mid+1,r,t[x].rs,t[y].rs,pos);
}

struct P
{
    int x,y;
}p[maxn+5];
bool cmp(P a,P b) {return a.x<b.x;}

int getid(int l,int r,int x)
{
    r++;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(p[mid].x>x) r=mid;
        else l=mid+1;
    }
    return l-1;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmp);
    rep(i,1,n) upd(1,1000000,root[i],root[i-1],p[i].y);

    while(m--)
    {
        int N; scanf("%d",&N);
        vi pp; pp.pb(0);
        rep(i,1,N)
        {
            int x; scanf("%d",&x);
            pp.pb(x);
        }
        sort(pp.begin(),pp.end());
        int ans=0;
        rep(i,1,N)
        {
            int L=getid(1,n,pp[i-1]);
            int R=getid(1,n,pp[i]);
            ans+=query(1,1000000,root[L],root[R],pp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}