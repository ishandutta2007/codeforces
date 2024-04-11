#include <iostream>
using namespace std;
int a[305][305],b[305][305];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >> a[i][j];
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=4;
				b[i][j]-=(i==1||i==n);
				b[i][j]-=(j==1||j==m);
				if(a[i][j]>b[i][j]) flag=0;
			}
		}
		if(!flag) puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					cout << b[i][j] << " ";
				puts("");
			}
		}
	}
	return 0;
}