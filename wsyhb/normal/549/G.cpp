#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int b[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		b[i]=a+i;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n-1;++i)
	{
		if(b[i]==b[i+1])
		{
			puts(":(");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d%c",b[i]-i," \n"[i==n]);
	return 0;
}