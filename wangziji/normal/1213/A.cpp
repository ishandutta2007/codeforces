#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int x=0,y=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		x+=t&1;
	}
	cout << min(x,n-x);
	return 0;
}