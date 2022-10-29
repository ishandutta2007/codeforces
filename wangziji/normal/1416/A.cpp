#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[300005],ans[300005],nxt[300005];
vector <int> v[300005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			v[i].clear();
		for(int i=1;i<=n;i++)
			v[i].push_back(0);
		for(int i=1;i<=n;i++)
		{
		    cin >> a[i];
			v[a[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
			v[i].push_back(n+1);
		for(int i=1;i<=n;i++)
			ans[i]=1e9;
		for(int i=1;i<=n;i++)
		{
			int mx=0;
			for(int j=1;j<v[i].size();j++)
				mx=max(mx,v[i][j]-v[i][j-1]);
			ans[mx]=min(ans[mx],i);
		}
		for(int i=2;i<=n;i++) ans[i]=min(ans[i],ans[i-1]);
		for(int i=1;i<=n;i++)
		{
			if(ans[i]>n) printf("-1 ");
			else cout << ans[i] << " ";
		}
		puts("");
	}
	return 0;
}