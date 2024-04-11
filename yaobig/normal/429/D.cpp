#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
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
    ll norm2() {return 1ll*x*x+1ll*y*y;}
};

int a[maxn+5];

ll solve(vector<P> &A,int l,int r)
{
    if(l==r) return 1ll<<62;
    int mid=(l+r)>>1;
    ll ans=1ll<<62;
    chmin(ans,solve(A,l,mid));
    chmin(ans,solve(A,mid+1,r));
    int p1=l,p2=mid+1;
    vector<P> tmp;
    while(p1<=mid && p2<=r)
    {
        if(A[p1].y<=A[p2].y) tmp.pb(A[p1++]);
        else tmp.pb(A[p2++]);
    }
    while(p1<=mid) tmp.pb(A[p1++]);
    while(p2<=r) tmp.pb(A[p2++]);
    rep(i,l,r) A[i]=tmp[i-l];
    rep(i,l,r) rep(j,1,7) if(i+j<=r) chmin(ans,(A[i]-A[i+j]).norm2());
    return ans;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) a[i]+=a[i-1];
    vector<P> A;
    rep(i,1,n) A.pb(P(i,a[i]));
    sort(A.begin(),A.end(),[](P p,P q){return p.x<q.x;});
    ll ans=solve(A,0,n-1);
    printf("%lld\n",ans);
    return 0;
}