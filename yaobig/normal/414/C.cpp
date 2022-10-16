#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn (1<<20)
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
ll le[25],gr[25];

vi solve(int dep,int l,int r)
{
    if(l==r) return vi{a[l]};
    int mid=(l+r)>>1;
    vi A=solve(dep+1,l,mid);
    vi B=solve(dep+1,mid+1,r);
    vi A2=A,B2=B;
    vi C;
    ll GR=0,LE=0;
    while(A.size() && B.size())
    {
        if(A.back()>B.back()) C.pb(A.back()),A.pop_back(),GR+=B.size();
        else if(A.back()<B.back()) C.pb(B.back()),B.pop_back();
        else C.pb(B.back()),B.pop_back();
    }
    while(A.size()) C.pb(A.back()),A.pop_back();
    while(B.size()) C.pb(B.back()),B.pop_back();
    reverse(C.begin(),C.end());

    while(A2.size() && B2.size())
    {
        if(A2.back()>B2.back()) A2.pop_back();
        else if(A2.back()<B2.back()) B2.pop_back(),LE+=A2.size();
        else A2.pop_back();
    }
    while(A2.size()) A2.pop_back();
    while(B2.size()) B2.pop_back();
    gr[dep]+=GR;
    le[dep]+=LE;
    return C;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,(1<<n)) scanf("%d",&a[i]);
    solve(0,1,1<<n);
    int q; scanf("%d",&q);
    while(q--)
    {
        int x; scanf("%d",&x);
        x=n-x;
        rep(i,x,n-1) swap(gr[i],le[i]);
        ll s=0;
        rep(i,0,n-1) s+=gr[i];
        printf("%lld\n",s);
    }
    return 0;
}