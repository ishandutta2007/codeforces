#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],vis[100005];
vector <int> x,y;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) vis[i]=0;
		int ans=n;
		x.clear(),y.clear();
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]<=n&&!vis[a[i]]) vis[a[i]]=1,--ans;
			else x.push_back(a[i]);
		}
		for(int i=1;i<=n;i++) if(!vis[i]) y.push_back(i);
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		int flag=1;
		for(int i=0;i<x.size();i++)
			if(y[i]*2>=x[i]) flag=0;
		if(!flag) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}