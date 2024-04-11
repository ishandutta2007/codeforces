#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[15][5];
bool flag[15],c[15];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			c[i]=0;
			for(int j=1;j<i;j++)
			  if(s[i][1]==s[j][1]&&s[i][2]==s[j][2]&&s[i][3]==s[j][3]&&s[i][4]==s[j][4])
			    c[i]=1;
			if(c[i])ans++;
		}
		printf("%d\n",ans);
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++)
		  if(!c[i])
		    flag[s[i][4]-'0']=1;
		for(int i=1;i<=n;i++)
		{
			if(c[i])
			{
				if(flag[s[i][4]-'0'])
				{
					for(int d=0;d<10;d++)
					{
						if(!flag[d])
						{
							s[i][4]=char('0'+d);
							break;
						}
					}
				}
			}
			printf("%s\n",s[i]+1);
			flag[s[i][4]-'0']=1;
		}
	}
	return 0;
}