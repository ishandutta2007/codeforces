#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int a[105][105],vis[105][105];
vector <int> ans[105];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) cin >> a[i][j];
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
		for(int i=1;i<=100;i++) ans[i].clear();
		for(int i=1;i<=m;i++)
		{
			int mn=2e9,pos=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(!vis[i][j]&&a[i][j]<mn) mn=min(mn,a[i][j]),pos=i;
			for(int i=1;i<=n;i++)
			{
				if(i==pos)
				{
					for(int j=1;j<=m;j++)
						if(!vis[i][j]&&a[i][j]==mn) {ans[i].push_back(a[i][j]),vis[i][j]=1;break;}
				}
				else
				{
					int mx=0,p=0;
					for(int j=1;j<=m;j++)
						if(!vis[i][j]&&a[i][j]>mx) mx=a[i][j],p=j;
					
					ans[i].push_back(a[i][p]),vis[i][p]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(auto t:ans[i]) cout << t << " ";
			cout << "\n";
		}
	}
	return 0;
}