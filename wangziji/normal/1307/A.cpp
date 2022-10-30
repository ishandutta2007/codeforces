#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		int ans=0;
		cin >> ans;
		for(int i=1;i<n;i++)
		{
			int t;
			cin >> t;
			ans+=min(t,m/i);
			m-=min(t,m/i)*i;
		}
		cout << ans << "\n";
	}
	return 0;
}