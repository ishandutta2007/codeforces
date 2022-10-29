#include <iostream>
using namespace std;
char a[6][6];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	int x=1,y=1,ans=(a[1][1]=='*');
	while(x!=n||y!=m)
	{
		int mn=1e9,X=0,Y=0;
		for(int j=y;j<=m;j++)
		{
			for(int i=x;i<=n;i++)
			{
				if(i==x&&j==y) continue;
				if(a[i][j]=='*')
					if(j-y+i-x<=mn) mn=j-y+i-x,X=i,Y=j;
			}
		}
		if(mn==1e9) break;
		x=X,y=Y,++ans;
	}
	cout << ans;
	return 0;
}