#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define maxp 4000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];
int p[maxp+5],cnt[maxp+5];
bool np[maxp+5]={1,1};
map<int,int> M;

int main()
{
    int pnum=0;
    rep(i,2,maxp)
    {
        if(!np[i]) p[++pnum]=i;
        rep(j,1,pnum)
        {
            ll v=1ll*i*p[j];
            if(v>maxp) break;
            np[v]=1;
            if(i%p[j]==0) break;
        }
    }

    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int g=0;
    rep(i,1,n) g=__gcd(g,a[i]);
    rep(i,1,n)
    {
        a[i]/=g;
        rep(j,1,pnum) if(a[i]%p[j]==0)
        {
            cnt[j]++;
            while(a[i]%p[j]==0) a[i]/=p[j];
        }
        if(a[i]>1) M[a[i]]++;
    }
    int ans=0;
    rep(i,1,pnum) ans=max(ans,cnt[i]);
    for(auto it: M) ans=max(ans,it.SE);
    printf("%d\n",ans?n-ans:-1);
    return 0;
}