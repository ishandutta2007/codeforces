#include <iostream>
#include <cmath>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int mx=0;
		int X=0,N=1e9;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(i==1) continue;
			if(a[i]==-1&&a[i-1]==-1)
				continue;
			if(a[i]!=-1&&a[i-1]!=-1)
			{
				mx=max(mx,abs(a[i]-a[i-1]));
				continue;
			}
			if(a[i]==-1&&a[i-1]!=-1)
			{
				X=max(X,a[i-1]),N=min(N,a[i-1]);
				continue;
			}
			if(a[i]!=-1&&a[i-1]==-1)
			{
				X=max(X,a[i]),N=min(N,a[i]);
				continue;
			}
		}
		int ans=(X+N)/2;
		if(X<N)
		{
			cout << mx << " " << 7 << "\n";
		}
		else
		cout << max(mx,max(X-ans,ans-N)) << " " << ans << "\n";
	}
	return 0;
}