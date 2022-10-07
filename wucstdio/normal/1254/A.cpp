#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[105][105];
int T,n,m,k,num,ans[105][105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		num=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			  if(s[i][j]=='R')num++;
		}
		int x=num/k,y=k-num%k;
		int nowx=1,nowy=1,now=0;
		while(nowx<=n)
		{
			if(s[nowx][nowy]=='R'&&!x)
			{
				now++;
				if(now<y)x=num/k;
				else x=num/k+1;
			}
			ans[nowx][nowy]=now;
			if(s[nowx][nowy]=='R')x--;
			if(nowx&1)
			{
				if(nowy==m)nowx++;
				else nowy++;
			}
			else
			{
				if(nowy==1)nowx++;
				else nowy--;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ans[i][j]<10)printf("%d",ans[i][j]);
				else if(ans[i][j]<36)printf("%c",ans[i][j]-10+'a');
				else printf("%c",ans[i][j]-36+'A');
			}
			printf("\n");
		}
	}
	return 0;
}