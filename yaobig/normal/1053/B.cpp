#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 300000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll lowbit(ll x) {return x&-x;}
int a[maxn+5];
int cnt[maxn+5][2];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        ll x; scanf("%I64d",&x);
        while(x)
        {
            a[i]++;
            x-=lowbit(x);
        }
    }
    int S=0;
    ll ans=0;
    cnt[0][0]=1;
    rep(i,1,n)
    {
        S+=a[i];
        cnt[i][0]=cnt[i-1][0]+((S&1)==0);
        cnt[i][1]=cnt[i-1][1]+(S&1);
        int sum=0,mx=0;
        per(j,i-59,i)
        {
            if(j<=0) break;
            sum+=a[j];
            mx=max(mx,a[j]);
            if(sum&1) continue;
            if(sum>=2*mx) ans++;
        }
        if(i-61>=0)
        {
            ans+=cnt[i-61][S&1];
        }
    }
    printf("%I64d\n",ans);
    return 0;
}