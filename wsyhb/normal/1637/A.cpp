#include<bits/stdc++.h>
using namespace std;
const int max_n=1e4+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		bool flag_sorted=true;
		for(int i=1;i<=n-1;++i)
			flag_sorted&=a[i]<=a[i+1];
		puts(flag_sorted?"NO":"YES");
	} 
	return 0;
}