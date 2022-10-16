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

int n,m;

int ask(int h,int w,int x1,int y1,int x2,int y2)
{
    printf("? %d %d %d %d %d %d\n",h,w,x1,y1,x2,y2); fflush(stdout);
    int ans; scanf("%d",&ans);
    return ans;
}

int ask(int l,int off,int _row)
{
    if(_row) return ask(l,m,off,1,off+l,1);
    else return ask(n,l,1,off,1,off+l);
}

int judge(int L,int l,int _row)
{
    int N=L/l;
    while(N!=1)
    {
        if(ask(N/2*l,1+(N&1)*l,_row)==0) return 0;
        N-=N/2;
    }
    return 1;
}

int solve(int L,int _row)
{
    int tmp=L;
    vi pfac;
    rep(i,2,tmp) if(tmp%i==0)
    {
        pfac.pb(i);
        while(tmp%i==0) tmp/=i;
    }
    int ans=L;
    for(auto p: pfac) while(ans%p==0 && judge(ans,ans/p,_row)) ans/=p;
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    int x=solve(n,1);
    int y=solve(m,0);
    auto factor=[](int x) {
        int ans=0;
        rep(i,1,x) if(x%i==0) ans++;
        return ans;
    };
    printf("! %d\n",factor(n/x)*factor(m/y));
    fflush(stdout);
    return 0;
}