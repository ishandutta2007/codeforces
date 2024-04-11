#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
signed a[100005];
signed mu[100005],n;
long long cnt[100005];
const int B=405,m=100000;
vector <int> f[100005];
inline signed gcd(signed x,signed y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y;
}
inline int cal(int x)
{
	if(x<=B)
	{
		int rtn=0;
		memset(cnt,0,sizeof cnt);
	//	for(int i=x;i<=n;i+=x) ++cnt[a[i]];
	//	for(int i=1;i<=m;i++)
	//		for(int j=i+i;j<=m;j+=i) cnt[i]+=cnt[j];
		for(int i=x;i<=n;i+=x) for(auto t:f[a[i]]) ++cnt[t]; 
		for(int i=1;i<=m;i++) cnt[i]*=cnt[i];
		for(int i=m;i>=1;i--)
			for(int j=i+i;j<=m;j+=i) cnt[i]-=cnt[j];
		for(int i=1;i<=m;i++) rtn+=cnt[i]*i,rtn%=mod;
		return rtn;
	}
	else
	{
		int rtn=0,sum=0;
		for(int i=x;i<=n;i+=x)
		{
			sum+=a[i];
			for(int j=i+x;j<=n;j+=x)
				rtn+=gcd(a[i],a[j]);
		}
		return (rtn*2+sum)%mod;
	}
}
int qwq[100005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) 
		cin >> a[i];
for(int i=1;i<=m;i++)
	for(int j=i;j<=m;j+=i) f[j].push_back(i);
	for(int i=2;i<=m;i++) mu[i]=1;
	for(int i=2;i<=m;i++)
		for(int j=i+i;j<=m;j+=i) mu[j]-=mu[i];
	int ans=0;
	for(int i=1;i<=n;i++) qwq[i]=cal(i);
	for(int i=n;i>=1;i--)
		for(int j=i+i;j<=n;j+=i) qwq[i]-=qwq[j];
	for(int i=1;i<=n;i++)
		ans+=i*qwq[i]%mod,ans%=mod;
	cout << (ans%mod+mod)%mod;
	return 0;
}