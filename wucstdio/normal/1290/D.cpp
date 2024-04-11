#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
bool f[10005];
char s[3];
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			puts("R");
			printf("? %d\n",i);
			fflush(stdout);
			scanf("%s",s);
			printf("? %d\n",j);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[j]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		  if(!f[i])ans++;
		printf("! %d\n",ans);
	}
	for(int i=0;i<n/k;i++)
	{
		for(int x=0;x<k;x++)
		{
			printf("? %d\n",i*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[i*k+x]=1;
		}
	}
	for(int i=0;i<n/k;i++)
	for(int j=i+1;j<n/k;j++)
	{
		puts("R");
		for(int x=0;x<k/2;x++)
		{
			if(f[i*k+x])continue;
			printf("? %d\n",i*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[i*k+x]=1;
		}
		for(int x=0;x<k/2;x++)
		{
			if(f[j*k+x])continue;
			printf("? %d\n",j*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[j*k+x]=1;
		}
		for(int x=k/2;x<k;x++)
		{
			if(f[i*k+x])continue;
			printf("? %d\n",i*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[i*k+x]=1;
		}
		puts("R");
		for(int x=0;x<k/2;x++)
		{
			if(f[i*k+x])continue;
			printf("? %d\n",i*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[i*k+x]=1;
		}
		for(int x=k/2;x<k;x++)
		{
			if(f[j*k+x])continue;
			printf("? %d\n",j*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[j*k+x]=1;
		}
		for(int x=k/2;x<k;x++)
		{
			if(f[i*k+x])continue;
			printf("? %d\n",i*k+x+1);
			fflush(stdout);
			scanf("%s",s);
			if(s[0]=='Y')f[i*k+x]=1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	  if(!f[i])ans++;
	printf("! %d\n",ans);
	return 0;
}