#include <iostream>
#include <map>
#define int long long
using namespace std;
int a[100005],cnt[100005],b[200];
inline int CNT(int x)
{
	int rtn=0;
	while(x)
	{
		rtn+=x&1;
		x>>=1;
	}
	return rtn;
}
map <int,int> mp;
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=70000;i++)
		cnt[i]=CNT(i);
	for(int i=0;i<65536;i++)
	{
		for(int j=1;j<=n;j++)
			b[j]=cnt[(a[j]&65535)^i];
		for(int j=n;j>=1;j--)
			b[j]-=b[1];
		int now=0;
		for(int j=1;j<=n;j++)
			now*=27,now+=-b[j];
		mp[now]=i;
	}
	for(int i=0;i<65536;i++)
	{
		for(int j=1;j<=n;j++)
			b[j]=cnt[(a[j]>>16)^i];
		for(int j=n;j>=1;j--)
			b[j]-=b[1];
		int now=0;
		for(int j=1;j<=n;j++)
			now*=27,now+=b[j];
		if(mp.count(now))
		{
			cout << (i<<16)+mp[now];
			return 0;
		}
	}
	cout << -1;
	return 0;
}