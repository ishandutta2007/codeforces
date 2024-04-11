#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];/*,fa[1005][1005];
inline int ff(int x,int y)
{
	
	if(fa[x][y]==x) return x;
	return fa[x][y]=ff(fa[x][y],y);
}*/
int main(int argc, char** argv) {
	int n,m,k;
/*	ios::sync_with_stdio(false);
	cin.tie(0);*/
	cin >> n >> m >> k;
	//for(int i=0;i<=n+1;i++) for(int j=1;j<=m;j++) fa[i][j]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> a[i][j];
	/*		if(a[i][j]==2)
				fa[i][j]=fa[i+1][j];*/
		}
	}
	while(k--)
	{
		int x=1,y;
		cin >> y;
		while(x<=n)
		{
		/*	if(a[x][y]==2) x=ff(x,y);
			else
			{
				a[x][y]=2;
				fa[x][y]=ff(x+1,y);
				if(a[x][y]==1) ++y;
				else --y;
			}*/
			if(a[x][y]==2) ++x;
			else if(a[x][y]==1) a[x][y]=2,++y;
			else a[x][y]=2,--y;
		}
		cout << y << " ";
	}
	return 0;
}