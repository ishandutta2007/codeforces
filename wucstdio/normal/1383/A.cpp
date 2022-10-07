#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,out[25];
char s[100005],t[100005];
int calc(int s)
{
	int ans=0;
	while(s)
	{
		ans+=s&1;
		s>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(out,0,sizeof(out));
		scanf("%s%s",s+1,t+1);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]>t[i])
			{
				flag=0;
				break;
			}
			if(s[i]<t[i])out[s[i]-'a']|=1<<(t[i]-'a');
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<=20;i++)
		{
			if(!out[i])continue;
			int j=0;
			while(!((1<<j)&out[i]))j++;
			ans++;
			out[j]|=out[i]^(1<<j);
		}
		printf("%d\n",ans);
	}
	return 0;
}