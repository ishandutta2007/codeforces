#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[200005];
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			cout << a[i];
		return 0;
	}
	if(n==1&&k==1)
	{
		cout << 0;
		return 0;
	}
	if(a[1]==1)
		++k;
	a[1]=1;
	for(int i=2;i<=k;i++)
	{
		if(i>n)
			break;
		if(a[i]==0)
			++k;
		a[i]=0;
	}
	for(int i=1;i<=n;i++)
		cout << a[i];
	return 0;
}