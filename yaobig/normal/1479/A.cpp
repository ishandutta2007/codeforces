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

int a[maxn+5];

int ask(int x)
{
    if(a[x]==-1)
    {
        printf("? %d\n",x);
        fflush(stdout);
        scanf("%d",&a[x]);
    } 
    return a[x];
}

int main()
{
    memset(a,-1,sizeof a);
    int n; scanf("%d",&n);
    a[0]=a[n+1]=n+1;
    int l=1,r=n;
    while(r-l>=4)
    {
        int mid=(l+r)>>1;
        if(ask(mid)<ask(mid+1)) r=mid;
        else l=mid+1;
    }
    rep(i,l,r) if(ask(i-1)>ask(i) && ask(i)<ask(i+1))
    {
        printf("! %d\n",i);
        return 0;
    }
    assert(0);
    return 0;
}