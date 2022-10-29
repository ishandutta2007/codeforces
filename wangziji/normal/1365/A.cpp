#include <iostream>
using namespace std;
int a[100][100];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >>a[i][j];
		int x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			++x;
			for(int j=1;j<=m;j++)
				if(a[i][j]){--x;break;}
		}
		for(int j=1;j<=m;j++)
		{
			++y;
			for(int i=1;i<=n;i++)
				if(a[i][j]){--y;break;}
		}
		if(min(x,y)&1) puts("Ashish");
		else puts("Vivek");
	}
	return 0;
}