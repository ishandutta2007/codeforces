#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 10001
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vector<pii> H[maxn+5],V[maxn+5];

struct bit
{
    int a[maxn+5];
    void init()
    {
        memset(a,0,sizeof a);
    }
    void add(int x,int v) {for(;x<=maxn;x+=x&-x) a[x]+=v;}
    int ask(int x) 
    {
        int res=0;
        for(;x;x-=x&-x) res+=a[x];
        return res;
    }
    int ask(int l,int r) {return ask(r)-ask(l-1);}
}b;

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1+=5001; x2+=5001;
        y1+=5001; y2+=5001;
        if(y1==y2)
        {
            if(x1>x2) swap(x1,x2);
            H[y1].pb({x1,x2});
        }
        else
        {
            if(y1>y2) swap(y1,y2);
            V[y2].pb({y1,x1});
        }
    }
    auto binom2=[](int n) {return n*(n-1)/2;};
    ll ans=0;
    rep(y1,0,maxn) for(auto [l,r]: H[y1])
    {
        b.init();
        per(y2,y1+1,maxn) 
        {
            for(auto [y_down,x]: V[y2]) if(y_down<=y1 && x>=l && x<=r) b.add(x,1);
            for(auto [x1,x2]: H[y2]) ans+=binom2(b.ask(x1,x2));
        }
    }
    printf("%lld\n",ans);
    return 0;
}