#include <iostream>
using namespace std;
int a[1005][1005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{ 
				cin >> a[i][j];
				if(i+j&1) if(a[i][j]&1) ++a[i][j];
				if(!(i+j&1)) if(!(a[i][j]&1)) ++a[i][j];
				cout << a[i][j] << " ";
			}
			puts("");
		}
	}
	return 0;
}