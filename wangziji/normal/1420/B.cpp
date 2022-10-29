#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int cnt[100];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		memset(cnt,0,sizeof cnt);
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int x,qwq=0;
			cin >> x;
			while(x) x>>=1,++qwq;
			++cnt[qwq];
		}
		int ans=0;
		for(int i=0;i<=60;i++)
			ans+=cnt[i]*(cnt[i]-1)/2;
		cout << ans << "\n";
	}
	return 0;
}