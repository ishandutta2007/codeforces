#include <iostream>
#include <queue>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int n,k;
pair <int,int> a[300005];
priority_queue <int,vector <int>, greater<int> > q;
int inv[300005],jcinv[300005],jc[300005],b[600005],Cnt;
inline int C(int x,int y)
{
	if(x<y) return 0;
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
signed main(int argc, char** argv) {
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].first,&a[i].second),b[++Cnt]=a[i].first,b[++Cnt]=a[i].second;
	inv[1]=jcinv[0]=jcinv[1]=jc[0]=jc[1]=1;
	for(int i=2;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+Cnt+1);
	int now=1,cnt=0,ans=0;
	for(int qwq=1;qwq<=Cnt;qwq++)
	{
		int i=b[qwq];
		while(now<=n&&a[now].first<=i)
			ans+=C(cnt,k-1),++cnt,q.push(a[now++].second);
		while(!q.empty()&&q.top()<=i) --cnt,q.pop();
	}
	cout << ans%mod;
	return 0;
}