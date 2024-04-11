#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<int,int> M;

int main()
{
    int num=0;

    int n,k; scanf("%d%d",&n,&k);
    int B=(1<<k)-1;
    M[0]++;
    int now=0;
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        now^=x;
        if(now&(1<<k-1)) now^=B;
        M[now]++;
    }
    ll ans=1ll*(n+1)*n/2;
    for(auto it: M)
    {
        int x=it.second;
        int half=x>>1;
        ans-=1ll*half*(half-1)/2+1ll*(x-half)*(x-half-1)/2;
    }
    printf("%I64d\n",ans);
    return 0;
}