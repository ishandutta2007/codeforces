#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
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
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			if(a[i])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			puts("0");
			continue; 
		}
		int L=1,R=n;
		while(!a[L])
			++L;
		while(!a[R])
			--R;
		flag=true;
		for(int i=L;i<=R;++i)
		{
			if(!a[i])
			{
				flag=false;
				break;
			}
		}
		puts(flag?"1":"2");
	}
	return 0;
}