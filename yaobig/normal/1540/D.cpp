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

template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x)
    {
        for(;i<=n;i+=i&-i) a[i]+=x;
    }
    int find(T x) // find the least number pos such that a[pos] + pos >= x.
    {
        int pos=0;
        per(i,0,31-__builtin_clz(n)) // log_2(n) = 31 - __builtin_clz(n)
        {
            if(pos + (1<<i) <= n && a[pos + (1<<i)] + pos + (1<<i) < x) 
            {
                pos|=1<<i;
                x-=a[pos];
            }
        }
        return pos+1;
    }
};
BIT<int> bit;

int a[maxn+5];
int bel[maxn+5],L[1000+5],R[1000+5];
vi V[1000+5];

void build(int id)
{
    V[id].clear();
    rep(i,L[id],R[id])
    {
        int p=bit.find(a[i]+1);
        V[id].pb(p-1); bit.add(p,1);
    }
    for(auto p: V[id]) bit.add(p+1,-1);
    sort(V[id].begin(),V[id].end());
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    
    const int Bsz=200;
    memset(L,63,sizeof L);
    rep(i,1,n)
    {
        bel[i]=(i+Bsz-1)/Bsz;
        chmin(L[bel[i]],i);
        chmax(R[bel[i]],i);
    }
    int M=bel[n];
    bit.init(n);
    rep(id,1,M) build(id);

    int q; scanf("%d",&q);
    while(q--)
    {
        int op; scanf("%d",&op);
        if(op==1)
        {
            int x,y; scanf("%d%d",&x,&y);
            a[x]=y;
            build(bel[x]);
        }
        else
        {
            int x; scanf("%d",&x);
            int ans=a[x];
            rep(i,x+1,R[bel[x]]) if(ans>=a[i]) ans++;
            rep(id,bel[x]+1,M) ans+=upper_bound(V[id].begin(),V[id].end(),ans)-V[id].begin();
            printf("%d\n",n-ans);
        }
    }
	return 0;
}