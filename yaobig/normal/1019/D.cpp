#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
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
    ll x,y;
    P():x(0),y(0){}
    P(ll a,ll b):x(a),y(b){}
    void in() {scanf("%lld%lld",&x,&y);}
    void out() {printf("%lld %lld\n",x,y);}
    P operator +(const P &a) const {return P(x+a.x,y+a.y);}
    P operator -(const P &a) const {return P(x-a.x,y-a.y);}
    P operator *(const db &a) const {return P(x*a,y*a);}
    P operator /(const db &a) const {return P(x/a,y/a);}
}p[maxn+5];

ll cross(const P&a,const P&b) {return a.x*b.y-a.y*b.x;}

pii seg[maxn*maxn+5];
int rk[maxn+5];

int main()
{
    int n; ll S; scanf("%d%lld",&n,&S); S*=2;
    rep(i,1,n) p[i].in();
    sort(p+1,p+n+1,[](const P&a,const P&b) {return a.y==b.y?a.x<b.x:a.y<b.y;});
    int N=0;
    rep(i,1,n) rep(j,i+1,n) seg[++N]={i,j};
    sort(seg+1,seg+N+1,[](const pii&a,const pii&b) {return cross(p[a.SE]-p[a.FI],p[b.SE]-p[b.FI])>0;});
    rep(i,1,n) rk[i]=i;
    rep(i,1,N)
    {
        auto [a,b]=seg[i];
        int &A=rk[a],&B=rk[b];
        assert(A==B-1);

        int l=1,r=n-B+1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(cross(p[B]-p[A],p[B+mid]-p[A])>S) r=mid;
            else l=mid+1;
        }
        if(cross(p[B]-p[A],p[B+r-1]-p[A])==S)
        {
            puts("Yes");
            p[A].out();
            p[B].out();
            p[B+r-1].out();
            return 0;
        }
        l=1,r=A;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(cross(p[A-mid]-p[A],p[B]-p[A])>S) r=mid;
            else l=mid+1;
        }
        if(cross(p[A-r+1]-p[A],p[B]-p[A])==S)
        {
            puts("Yes");
            p[A].out();
            p[B].out();
            p[A-r+1].out();
            return 0;
        }
        swap(p[A],p[B]);
        swap(A,B);
    }
    puts("No");
    return 0;
}