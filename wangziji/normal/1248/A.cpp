#include <iostream>
#define int long long
using namespace std;
int a[100005],b[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int o,e;
		o=e=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			o+=a[i]&1;
			e+=1-(a[i]&1);
		}
		int m,ans=0;
		cin >> m;
		for(int i=1;i<=m;i++)
		{
			cin >> b[i];
			if(b[i]&1)
				ans+=o;
			else
				ans+=e;
		}
		cout << ans << endl;
	}
	return 0;
}