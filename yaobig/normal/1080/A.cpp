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


int main()
{
    ll n,k; scanf("%I64d%I64d",&n,&k);
    ll ans=0;
    ans+=(n*2+k-1)/k;
    ans+=(n*5+k-1)/k;
    ans+=(n*8+k-1)/k;
    printf("%I64d\n",ans);
    return 0;
}