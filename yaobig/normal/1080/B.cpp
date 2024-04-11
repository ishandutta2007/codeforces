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

ll ask(int n)
{
    ll B=1ll*n*(n+1)/2;
    int h=n/2;
    ll C=2ll*h*(h+1);
    return C-B;
}

int main()
{
    int q; scanf("%d",&q);
    while(q--)
    {
        int l,r; scanf("%d%d",&l,&r);
        ll ans=ask(r)-ask(l-1);
        printf("%I64d\n",ans);
    }

    return 0;
}