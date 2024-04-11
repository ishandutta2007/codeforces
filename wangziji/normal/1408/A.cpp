#include <iostream>
using namespace std;
int a[105],b[105],c[105];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		for(int i=1;i<=n;i++)
			cin >> c[i];
		int lst=0;
		for(int i=1;i<=n;i++)
		{
			if(i<n)
			{
				if(a[i]!=lst) cout << (lst=a[i]) << " ";
				else if(b[i]!=lst) cout << (lst=b[i]) << " ";
				else if(c[i]!=lst) cout << (lst=c[i]) << " ";
			}
			else
			{
				if(a[i]!=lst&&a[i]!=a[1]) cout << a[i];
				else if(b[i]!=lst&&b[i]!=a[1]) cout << b[i];
				else if(c[i]!=lst&&c[i]!=a[1]) cout << c[i];
			}
		}
		puts("");
	}
	return 0;
}