#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#define int long long
using namespace std;
int a[200005],n,ans;
inline int cal(int x)
{
	if(x<=1) return ans;
	//cout << x << " ";
	int rtn=0;
	for(int i=1;i<=n;i++)
	{
		int t=a[i]/x*x;
		if(t>0)
			rtn+=min(a[i]-t,t+x-a[i]);
		else rtn+=t+x-a[i];
		if(rtn>=ans) return ans;
	}
	return rtn;
}
signed main(int argc, char** argv) {
	srand((unsigned long long)new char);
	double st=clock();
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) ans+=a[i]&1;
	random_shuffle(a+1,a+n+1);
	for(int i=3;i<=10;i++)
		ans=min(ans,cal(i));
	while(clock()-st<=1.5*CLOCKS_PER_SEC)
	{
		int t=(int)rand()*rand()%n+1;
		for(int i=a[t]-1;i<=a[t]+1;i++)
		{
			int X=i;
			for(int j=2;j*j<=X;j++)
			{
				if(X%j==0)
					ans=min(ans,cal(j));
				while(X%j==0)
					X/=j;
			}
			ans=min(ans,cal(X));
		}
	}
	cout << ans;
	return 0;
}