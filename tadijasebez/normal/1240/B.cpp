#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb long double
const int mod=1e9+7;//998244353;
void ckmx(int &x, int y){ x=max(x,y);}
void ckmn(int &x, int y){ x=min(x,y);}
void ckmx(ll &x, ll y){ x=max(x,y);}
void ckmn(ll &x, ll y){ x=min(x,y);}
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
const int N=300050;
int a[N],l[N],r[N],dp[N];
int main()
{
    int q;
    scanf("%i",&q);
    while(q--)
	{
		int n;
		scanf("%i",&n);
		vector<int> id;
		for(int i=1;i<=n;i++) scanf("%i",&a[i]),id.pb(a[i]);
		sort(id.begin(),id.end());
		id.erase(unique(id.begin(),id.end()),id.end());
		for(int i=1;i<=n;i++) a[i]=lower_bound(id.begin(),id.end(),a[i])-id.begin()+1;
		for(int i=1;i<=id.size();i++) l[i]=n+1,r[i]=0;
		for(int i=1;i<=n;i++) l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
        dp[1]=1;
        for(int i=2;i<=id.size();i++)
		{
			if(l[i]>r[i-1]) dp[i]=dp[i-1]+1;
			else dp[i]=1;
		}
		int ans=1;
		for(int i=1;i<=id.size();i++) ans=max(ans,dp[i]);
		printf("%i\n",id.size()-ans);
	}
	return 0;
}