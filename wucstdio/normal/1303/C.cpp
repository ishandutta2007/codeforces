#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int t,n,edgenum,d[27],head[27],xx[27],top;
char s[100005],ans[27];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=(int)strlen(s+1);
		memset(head,0,sizeof(head));
		edgenum=0;
		for(int i=1;i<n;i++)
		{
			add(s[i]-'a',s[i+1]-'a');
			add(s[i+1]-'a',s[i]-'a');
		}
		bool flag=1;
		int num=0,c=0;
		for(int i=0;i<26;i++)
		{
			int a=-1,b=-1;
			for(int hd=head[i];hd;hd=e[hd].nxt)
			{
				int to=e[hd].to;
				if(a==to||b==to)continue;
				if(a==-1)a=to;
				else if(b==-1)b=to;
				else
				{
					flag=0;
					break;
				}
			}
			if(flag==0)break;
			if(a!=-1&&b==-1)num++;
			if(a!=-1)c++;
			if(a==-1)xx[i]=0;
			else if(b==-1)xx[i]=1;
			else xx[i]=2;
		}
		if(c>=2&&num!=2)flag=0;
		if(!flag)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=0;i<26;i++)
		  if(!xx[i])printf("%c",i+'a');
		for(int i=0;i<26;i++)
		{
			if(xx[i]==1)
			{
				int x=i,pre=-1;
				while(1)
				{
					int y=x;
					printf("%c",x+'a');
					for(int hd=head[x];hd;hd=e[hd].nxt)
					{
						int to=e[hd].to;
						if(to!=pre)
						{
							pre=x;
							x=to;
							break;
						}
					}
					if(x==y)break;
				}
				break;
			}
		}
		printf("\n");
	}
	return 0;
}