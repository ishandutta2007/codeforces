#include <iostream>
#include <cstdio>
using namespace std;
int a[1000005],b[1000005];
int main(int argc, char** argv) {
	int n,m,p;
	cin >> n >> m >> p;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]%=p;
	}
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&b[j]);
		b[j]%=p;
	}
	int w=0;
	for(int i=n;i>=0;i--)
	{
		if(a[i]!=0)
		{
			w=i;
			break;
		}
	}
	for(int i=m;i>=0;i--)
	{
		if(b[i]!=0)
		{
			cout << i+w-2;
			return 0;
		}
	}
	cout << "dlstxdy!";
	return 0;
}