#include <bits/stdc++.h>
using namespace std;
int n,k,a[30];
bool check;
int main()
{
	cin>>n>>k;
	check=true;
	for (int i=1;i<k;i++)
	{
		int j=2;
		while (j*j<=n&&n%j) ++j;
		if (n%j==0) a[i]=j; else check=false;
		if (n%j==0) n=n/j;
	}
	a[k]=n;
	if (n==1||(!check)) cout << -1 << endl; else
	{
	for (int i=1;i<=k;i++) cout << a[i] << ' ';
	cout << endl;
}
return 0;
}