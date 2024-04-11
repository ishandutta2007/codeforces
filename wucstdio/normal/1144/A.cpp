#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[1000005];
bool flag[26];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(flag,0,sizeof(flag));
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			if(flag[s[i]-'a'])
			{
				printf("No\n");
				f=0;
				break;
			}
			flag[s[i]-'a']=1;
		}
		if(f==0)continue;
		int num=0;
		for(int i=0;i<26;i++)
		  if(flag[i]&&(i==0||!flag[i-1]))
			num++;
		if(num==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}