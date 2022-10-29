#include <iostream>
using namespace std;
int a[10005];
signed main() {
	int T;
	cin >> T;
	while(T--)
	{
		int n,u,v;
		cin >> n >> u >> v;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int flag=0,F=1;
		for(int i=2;i<=n;i++)
		{
			if(max(a[i]-a[i-1],a[i-1]-a[i])>=2) flag=1;
			if(a[i]!=a[i-1]) F=0;
		}
		if(flag)
		{
			puts("0");
			continue;
		}
		if(F)
		{
			cout << min(u+v,v+v) << "\n";
			continue;
		}
		cout << min(u,v) << "\n";
	}
	return 0;
}