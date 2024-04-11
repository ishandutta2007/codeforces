#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100;
int a[N][N],b[N][N];
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%i",&a[i][j]);
	vector<pair<int,int>> ans;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1)
		{
			b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
			ans.pb({i,j});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]!=b[i][j]) return 0*printf("-1\n");
	printf("%i\n",ans.size());
	for(auto p:ans) printf("%i %i\n",p.first,p.second);
	return 0;
}