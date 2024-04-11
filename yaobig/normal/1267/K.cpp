#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 50
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int cnt[30];

ll C(int n,int m)
{
    if(m<0 || n<m) return 0;
    ll res=1;
    rep(i,1,m) res=res*(n-i+1);
    rep(i,1,m) res/=i;
    return res;
}

ll cal(int n)
{
    //printf("!! %d\n",n);
    ll ans=1;
    int oc=0;
    per(i,0,27) if(cnt[i])
    {
        int p=i>=2?n-i+1:n;
        //printf("??? %d: %d %d\n",i,p-oc,cnt[i]);
        ans*=C(p-oc,cnt[i]);
        oc+=cnt[i];
    }
    return ans;
}

int main()
{
    int CAS; scanf("%d",&CAS);
    while(CAS--)
    {
        ll x; scanf("%I64d",&x);
        rep(i,0,27) cnt[i]=0;
        int N=1;
        while(x)
        {
            N++;
            int r=x%N;
            cnt[r]++;
            x/=N;
        }
        ll ans=cal(N-1);
        if(cnt[0])
        {
            //printf("??? %I64d\n",ans);
            cnt[0]--;
            ans-=cal(N-2);
        }
        printf("%I64d\n",ans-1);
    }
	return 0;
}