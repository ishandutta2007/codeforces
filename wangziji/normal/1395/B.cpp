#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int x,y,n,m;
	cin >> n >> m >> x >> y;
	int now=y;
	for(int i=x;i<=n;i++)
	{
		for(int j=now;j<=m;j++)
			cout << i << " " << j << "\n";
		for(int j=1;j<now;j++)
			cout << i << " " << j << "\n";
		if(now==1) now=m;
		else --now;
	}
	for(int i=x-1;i>=1;i--)
	{
		for(int j=now;j<=m;j++)
			cout << i << " " << j << "\n";
		for(int j=1;j<now;j++)
			cout << i << " " << j << "\n";
		if(now==1) now=m;
		else --now;
	}
	return 0;
}