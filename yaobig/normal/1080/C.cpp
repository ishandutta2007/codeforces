#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

struct rec
{
    int x1,y1,x2,y2;
    rec(){}
    rec(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){}
    void in() {scanf("%d%d%d%d",&x1,&y1,&x2,&y2);}
    pll cal()
    {
        if(x1>x2 || y1>y2) return mp(0,0);
        ll X=x2-x1+1,Y=y2-y1+1;
        ll ans=X*Y/2;
        if(X%2==0 || Y%2==0) return mp(ans,ans);
        if((x1+y1)%2==0) return mp(ans+1,ans);
        else return mp(ans,ans+1);
    }
    pll all(int c)
    {
        if(x1>x2 || y1>y2) return mp(0,0);
        ll ans=1ll*(x2-x1+1)*(y2-y1+1);
        if(c==0) return mp(ans,0);
        else return mp(0,ans);
    }
};
rec cross(rec a,rec b)
{
    return rec(max(a.x1,b.x1),max(a.y1,b.y1),min(a.x2,b.x2),min(a.y2,b.y2));
}

pll operator +(pll a,pll b) {return mp(a.fi+b.fi,a.se+b.se);}
pll operator -(pll a,pll b) {return mp(a.fi-b.fi,a.se-b.se);}

int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int n,m; scanf("%d%d",&n,&m);
        ll B,W;
        rec whole(1,1,n,m);
        rec w,b;
        w.in();
        b.in();
        rec c=cross(w,b);
        pll ans=whole.cal();
        ans=ans-w.cal();
        ans=ans+w.all(0);
        ans=ans-c.all(0);
        ans=ans+c.cal();
        ans=ans-b.cal();
        ans=ans+b.all(1);
        printf("%I64d %I64d\n",ans.fi,ans.se);
    }

    return 0;
}