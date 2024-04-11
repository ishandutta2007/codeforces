#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int n; 
int a[maxn+5];

void S1(vi &A)
{
    rep(i,0,n-1)
    {
        int b=i*2;
        swap(A[b],A[b+1]);
    } 
}
void S2(vi &A)
{
    rep(i,0,n-1) swap(A[i],A[i+n]);
}

int main()
{
    scanf("%d",&n); 
    rep(i,1,n*2) scanf("%d",&a[i]);
    vi A(n*2),I(n*2),B;
    rep(i,1,n*2) A[i-1]=a[i];
    rep(i,1,n*2) I[i-1]=i; 
    B=A;
    int ans=inf;
    if(A==I) ans=0;
    rep(i,1,n*2)
    {
        if(i&1) S1(A);
        else S2(A);
        if(A==I) chmin(ans,i);
    }
    A=B;
    rep(i,1,n*2)
    {
        if(i&1) S2(A);
        else S1(A);
        if(A==I) chmin(ans,i);
    }
    if(ans==inf) return puts("-1"),0;
    printf("%d\n",ans);
    return 0;
}