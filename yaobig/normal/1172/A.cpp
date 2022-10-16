#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int n,ans;
int a[maxn+5],b[maxn+5];
int av[maxn+5];

void check()
{
    int l=b[n];
    rep(i,0,l-1) if(b[n-i]!=l-i) return;
    rep(i,l+1,n) if(av[i]>=i-l) return;
    ans=min(ans,n-l);
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&b[i]);
    rep(i,1,n) if(a[i]) av[a[i]]=0;
    rep(i,1,n) if(b[i]) av[b[i]]=i;
    rep(i,1,n) ans=max(ans,av[i]-i+1);
    ans+=n;
    check();
    printf("%d\n",ans);
    return 0;
}