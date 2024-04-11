#include <iostream>
#define int long long
using namespace std;
int cnt[100005],m;
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn*=x,rtn%=m;
		x*=x,x%=m,y>>=1;
	}
	return rtn;
}
int a[100005];
signed main(int argc, char** argv) {
	int n,ans=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(cnt[a[i]%m])
		{
			puts("0");
			return 0;
		}
		++cnt[a[i]%m];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans*=a[i]-a[j];
			if(ans<0) ans=-ans;
			ans%=m;
		}
	}
	cout << ans;
	return 0;
}