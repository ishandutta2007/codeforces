#include <iostream>
#include <cstring>
using namespace std;
string a[100005];
int cnt[200],w[10005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int ans=0;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=0;i<m;i++)
	{
		int mx=0;
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++)
		{
			++cnt[a[j][i]];
			mx=max(mx,cnt[a[j][i]]);
		}
	//	cout << w[i+1] << " " << mx << endl;
		ans+=w[i+1]*mx;
	}
	cout << ans;
	return 0;
}