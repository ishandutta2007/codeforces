#include <iostream>
using namespace std;
int cnt[200005],pos[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			++cnt[x],pos[x]=i;
		}
		int ans=-1;
		for(int i=n;i>=1;i--)
		{
			if(cnt[i]==1) ans=pos[i];
		}
		cout << ans << "\n";
	}
	return 0;
}