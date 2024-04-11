#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100010
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
ll A[maxn+5],B[maxn+5];

int main()
{
    int n,d,m; scanf("%d%d%d",&n,&d,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    int N=0,M=0;
    rep(i,1,n) if(a[i]>m) B[++M]=a[i]; else A[++N]=a[i];
    sort(A+1,A+N+1,greater<ll>());
    sort(B+1,B+M+1,greater<ll>());
    rep(i,1,N) A[i]=A[i-1]+A[i];
    rep(i,1,M) B[i]=B[i-1]+B[i];
    ll ans=0;
    rep(i,0,N)
    {
        int j=(n-i+d)/(d+1);
        j=min(j,M);
        //printf("? %d %d: %lld %lld\n",i,j,A[i],B[j]);
        ans=max(ans,A[i]+B[j]);
    }
    printf("%lld\n",ans);
    return 0;
}