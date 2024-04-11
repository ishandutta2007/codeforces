#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
#define FI first
#define SE second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vi d[3];

ll getday(ll n)
{
    ll x=sqrt(n*2);
    while(x*(x+1)<2*n) x++;
    while(x*(x+1)>2*n) x--;
    return x;
}

int A[maxn+5];

int main()
{
    int a,b; scanf("%d%d",&a,&b);
    int N=getday(a+b);
    int n=getday(a);
    rep(i,1,N) A[i]=2;
    rep(i,1,n) A[i]=1;
    int rem=a-n*(n+1)/2;
    if(rem>0 && b>=n+1-rem)
    {
        //printf("?? %d %d\n",n+1,n+1-rem);
        A[n+1]=1;
        A[n+1-rem]=2;
    }
    rep(i,1,N) if(A[i]==1) d[1].pb(i); else d[2].pb(i);
    //rep(i,1,N) printf("%d: %d\n",i,A[i]);
    printf("%d\n",n);
    rep(i,0,n-1) printf("%d%c",d[1][i]," \n"[i==n-1]);
    n=N-n;
    printf("%d\n",n);
    rep(i,0,n-1) printf("%d%c",d[2][i]," \n"[i==n-1]);

    return 0;
}