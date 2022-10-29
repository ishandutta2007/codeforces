#include <iostream>
using namespace std;
char a[1005][1005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cin >> a[i][j];
		}
		int x=a[1][2],y=a[2][1],z=a[n-1][n],w=a[n][n-1];
		if(x==y&&z==w)
		{
			if(x!=z)
			{
				puts("0");
				continue;
			}
			cout << 2 << "\n";
			cout << "1 2\n2 1\n";
			continue;
		}
		if(x!=y&&z==w)
		{
			puts("1");
			if(x==z)
				cout << "1 2\n";
			else cout << "2 1\n";
			continue; 
		}
		if(x==y&&z!=w)
		{
			puts("1");
			if(x==z)
				cout << n-1 << " " << n << "\n";
			else cout << n << " " << n-1 << "\n";
			continue; 
		}
		if(x!=y&&z!=w)
		{
			puts("2");
			if(x==z) cout << "2 1\n" << n-1 << " " << n << "\n";//1010
			else cout << "1 2\n" << n-1 << " " << n << "\n";//1001
			continue;
		}
	}
	return 0;
}