#include <iostream>
using namespace std;
int hzh[100005],a[100005];
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,p,k;
		cin >> n >> p >> k;
		for(int i=1;i<=n;i++)
		{
			char c;
			cin >> c;
			if(c=='1') a[i]=1;
			else a[i]=0;
		}
		int x,y;
		cin >> x >> y;
		for(int i=n;i>=1;i--)
		{
			hzh[i]=!a[i];
			if(i+k<=n) hzh[i]+=hzh[i+k];
		}
		int ans=2e9;
		for(int i=p;i<=n;i++)
		{
			ans=min(ans,hzh[i]*x+(i-p)*y);
		}
		cout << ans << "\n";
	}
	return 0;
}