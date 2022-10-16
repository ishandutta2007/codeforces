#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int fa[maxn+5];
ll v[maxn+5];
int getfa(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=getfa(fa[x]);
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,2,n)
    {
        for(int j=i*2;j<=n;j+=i)
        {
            int fi=getfa(i);
            int fj=getfa(j);
            if(fi!=fj) fa[fj]=fi,v[fi]+=v[fj];
            v[fi]+=j/i;
        }
    }
    ll ans=0;
    rep(i,1,n) ans=max(ans,v[getfa(i)]);
    printf("%I64d\n",ans*4);
    return 0;
}