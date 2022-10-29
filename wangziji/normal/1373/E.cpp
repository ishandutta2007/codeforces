#include <iostream>
#define int long long
using namespace std;
int n,k;
inline int s(int x)
{
	int rtn=0;
	while(x) rtn+=x%10,x/=10;
	return rtn;
}
inline bool pd(int x)
{
//	cout << x << "\n";
	int rtn=0;
	for(int i=0;i<=k;i++)
	{
		rtn+=s(x+i);
		if(rtn>n) return 0;
	}
	return rtn==n;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		int ans=9e18;
		for(int i=0;i<=1000;i++)
		{
			if(pd(i))
			{
				ans=i;
				break;
			}
		}
		if(ans<=8e18)
		{
			cout << ans << "\n";
			continue;
		}
		for(int i=1;i<=9;i++)
		{
			for(int j=0;j<=15;j++)
			{
				int now=i;
				for(int k=1;k<=j;k++)
					now*=10,now+=9;
				for(int k=80;k<=99;k++)
				{
					if(pd(now*100+k))
						ans=min(ans,now*100+k);
				}
			}
		}
		if(ans>8e18) puts("-1");
		else cout << ans << "\n";
	}
	return 0;
}