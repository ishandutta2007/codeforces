#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 500000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct P
{
    int x,y,z;
}a[maxn+5];
bool cmpxyz(P a,P b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y>b.y;
}

int t[maxn+5];
void add(int x,int v) {for(;x<=maxn;x+=x&-x) t[x]=min(t[x],v);}
int ask(int x)
{
    int res=inf;
    for(;x;x-=x&-x) res=min(res,t[x]);
    return res;
}

vi vec;

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i].x),a[i].x=-a[i].x;
    rep(i,1,n) scanf("%d",&a[i].y),a[i].y=-a[i].y;
    rep(i,1,n) scanf("%d",&a[i].z),a[i].z=-a[i].z;

    rep(i,1,n) vec.pb(a[i].y);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    rep(i,1,n) a[i].y=lower_bound(vec.begin(),vec.end(),a[i].y)-vec.begin()+1;

    sort(a+1,a+n+1,cmpxyz);
    memset(t,63,sizeof t);

    int ans=0;
    rep(i,1,n)
    {
        int x=ask(a[i].y-1);
        if(x<a[i].z) ans++;
        add(a[i].y,a[i].z);
    }
    printf("%d\n",ans);
    return 0;
}