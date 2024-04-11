#include <iostream>
#define int long long
using namespace std;
int a[30][30],hzh[30][30];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int j=n-1;j>=1;j--)
	{
		for(int i=2;i<=n;i++)
		{
			int x=0,y=a[i-1][j+1];
			for(int k=j+1;k<=n;k++)
				x+=a[i][k];
			for(int k=i;k<n;k++)
				y+=a[k][j+1];
			for(int k=j+1;k<=n;k++)
				y+=a[n][k];
			a[i][j]=y-x+1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=n;j>=1;j--)
			hzh[i][j]=a[i][j]+hzh[i][j+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while(q--)
	{
		int k;
		cin >> k;
		int x=1,y=1;
		while(x<=n&&y<=n)
		{
			cout << x << " " << y << endl;
			k-=a[x][y];
			if(k>=hzh[x+1][y]&&x<n) ++x;
			else ++y;
		}
		cerr << "**" << k << "\n";
	}
	return 0;
}