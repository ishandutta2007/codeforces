#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		for(int i=n;i>=1;--i) printf("%d%c",a[i],i>1?' ':'\n');
	}
	return 0;
}