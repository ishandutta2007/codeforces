#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct P
{
    int x,y;
    P():x(0),y(0){}
    P(int a,int b):x(a),y(b){}
    void in() {scanf("%d%d",&x,&y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
    ll norm2() {return 1ll*x*x+1ll*y*y;}
    bool operator ==(const P &a) const {return a.x==x && a.y==y;}
};
ll cross(P a,P b) {return 1ll*a.x*b.y-1ll*a.y*b.x;}
ll dot(P a,P b) {return 1ll*a.x*b.x+1ll*a.y*b.y;}

vector<P> p,o;
int ans;

bool judge(P a,P b,P c,P d) // judge if acbd is a square
{
    if((a-b).norm2()==(c-d).norm2() && dot(a-b,c-d)==0 && a+b==c+d && (a-b).norm2()!=0) return 1;
    return 0;
}

bool check()
{
    if(judge(p[0],p[1],p[2],p[3])) return 1;
    if(judge(p[0],p[2],p[1],p[3])) return 1;
    if(judge(p[0],p[3],p[1],p[2])) return 1;
    return 0;
}

void dfs(int dep,int step)
{
    if(dep==4)
    {
        if(check()) chmin(ans,step);
        return;
    }
    rep(i,0,3)
    {
        dfs(dep+1,step+i);
        P &a=p[dep];
        a=a-o[dep];
        a=P(-a.y,a.x)+o[dep];
    }
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        p=o=vector<P>(4);
        rep(i,0,3) p[i].in(),o[i].in();
        ans=inf;
        dfs(0,0);
        if(ans==inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}