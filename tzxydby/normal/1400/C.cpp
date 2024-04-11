#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,x;
char s[N],a[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",s+1,&x);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			a[i]='1';
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				if(i>x)
					a[i-x]='0';
				if(i+x<=n)
					a[i+x]='0';
			}
		}
		int zh=1;
		for(int i=1;i<=n;i++)
		{
			int fl=0;
			if(i>x&&a[i-x]=='1')
				fl=1;
			if(i+x<=n&&a[i+x]=='1')
				fl=1;
			if(s[i]=='1'&&!fl)
				zh=0;
		}
		if(!zh)
		{
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++)
			printf("%c",a[i]);
		puts("");
	}
	return 0;
}