#include<stdio.h>
typedef long long unsigned wah;
typedef unsigned u;
wah a[100],b[100],s;
u n,t,m,k;
int main()
{
	s++;
	for(scanf("%u",&n);t<n;t++)
	{
		scanf("%u",&m);
		while(m--)
		{
			scanf("%u",&k);
			if(k>>6)b[t]|=s<<(k&63);
			else a[t]|=s<<k;
		}
	}
	for(t=0;t<n;t++)
	{
		for(m=0;m<n;m++)if(m!=t)
		{
			if((a[t]&a[m])==a[m]&&(b[t]&b[m])==b[m])
			{printf("NO\n");goto con;}
		}
		printf("YES\n");
		con:;
	}
	return 0;
}