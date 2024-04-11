#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,k,ans;
char s[100005];
int len[100005],num;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		ans=0;
		num=0;
		int cur=0;
		int st=1;
		while(s[st]=='L')st++;
		for(int i=st;i<=n;i++)
		{
			if(s[i]=='W')
			{
				if(cur)
				{
					len[++num]=cur;
					cur=0;
				}
				if(s[i-1]=='W')ans+=2;
				else ans++;
			}
			else cur++;
		}
		st--;
		if(!ans)
		{
			if(k==0)printf("0\n");
			else printf("%d\n",k*2-1);
			continue;
		}
		sort(len+1,len+num+1);
		for(int i=1;i<=num;i++)
		{
			if(k>=len[i])
			{
				k-=len[i];
				ans+=len[i]*2+1;
			}
			else
			{
				ans+=k*2;
				k=0;
				break;
			}
		}
		if(k)ans+=min(st+cur,k)*2;
		printf("%d\n",ans);
	}
	return 0;
}