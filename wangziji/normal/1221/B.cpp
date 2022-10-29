#include <iostream>
using namespace std;
int a[105][105],n;
inline void dfs(int x,int y)
{
	if(!a[x+1][y+2]&&x+1<=n&&y+2<=n)
		a[x+1][y+2]=3-a[x][y],dfs(x+1,y+2);
	if(!a[x-1][y+2]&&x-1>0&&y+2<=n)
		a[x-1][y+2]=3-a[x][y],dfs(x-1,y+2);
	if(!a[x+1][y-2]&&x+1<=n&&y-2>0)
		a[x+1][y-2]=3-a[x][y],dfs(x+1,y-2);
	if(!a[x-1][y-2]&&x-1>0&&y-2>0)
		a[x-1][y-2]=3-a[x][y],dfs(x-1,y-2);
		
	if(!a[x+2][y+1]&&x+2<=n&&y+1<=n)
		a[x+2][y+1]=3-a[x][y],dfs(x+2,y+1);
	if(!a[x-2][y+1]&&x-2>0&&y+1<=n)
		a[x-2][y+1]=3-a[x][y],dfs(x-2,y+1);
	if(!a[x+2][y-1]&&x+2<=n&&y-1>0)
		a[x+2][y-1]=3-a[x][y],dfs(x+2,y-1);
	if(!a[x-2][y-1]&&x-2>0&&y-1>0)
		a[x-2][y-1]=3-a[x][y],dfs(x-2,y-1);
}
int main(int argc, char** argv) {
	cin >> n;
	a[1][1]=2;
	dfs(1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
				cout << 'B';
			else
				cout << 'W';
		}
		cout << endl;
	}
	return 0;
}