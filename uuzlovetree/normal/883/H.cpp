#include<bits/stdc++.h>
#define maxn 400005
using namespace std;
int n;
char s[maxn],tmp[maxn];
int c[205];
char core[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)c[s[i]]++;
	int num=0;
	for(int i=1;i<=200;++i)if(c[i]&1)num++;
	if(!num)
	{
		printf("1\n");
		for(int k=1;k<=200;++k)
		{
			for(int j=1;j<=c[k]/2;++j)printf("%c",k);
		}
		for(int k=200;k>=1;--k)
		{
			for(int j=1;j<=c[k]/2;++j)printf("%c",k);
		}
	}
	else
	{
		int ans=0;
		for(int i=num;i<=n;i+=2)if(n%i==0&&(n/i-1)%2==0){ans=i;break;}
		printf("%d\n",ans);
		int cnt=0;
		for(int i=1;i<=200;++i)if(c[i]&1)
		{
			core[++cnt]=i;
			c[i]--;
		}
		for(int i=1;i<=200;++i)
		{
			while(cnt<ans&&c[i]>0)core[++cnt]=i,core[++cnt]=i,c[i]-=2;
		}
		int N=0;
		for(int i=1;i<=200;++i)
		{
			for(int j=1;j<=c[i]/2;++j)tmp[++N]=i;
		}
		for(int i=1;i<=ans;++i)
		{
			for(int j=(i-1)*(n/ans-1)/2+1;j<=(i-1)*(n/ans-1)/2+(n/ans-1)/2;++j)printf("%c",tmp[j]);
			printf("%c",core[i]);
			for(int j=(i-1)*(n/ans-1)/2+(n/ans-1)/2;j>=(i-1)*(n/ans-1)/2+1;--j)printf("%c",tmp[j]);
			printf(" ");
		}
	}
}