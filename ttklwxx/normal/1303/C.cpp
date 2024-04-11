#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int ans[27],vis[27];
int lt[27][27],rd[27],cnt;
char str[1001];
bool dfs(int x)
{
	if(rd[x]>=2)return false;
	vis[x]=true;
	ans[++cnt]=x;
	for(int i=1;i<=26;i++)
	{
		if(lt[x][i]==1&&!vis[i])
		{
			rd[i]--;
			if(!dfs(i))return false;
			return true;
		}
	}
	return true;
}
signed main()
{
    int t,n,x;
    bool flag;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	scanf("%s",str+1);
    	n=strlen(str+1);
    	for(int j=1;j<=n-1;j++)
    	{
    		if(!lt[str[j]-'a'+1][str[j+1]-'a'+1])
    		{
    			lt[str[j]-'a'+1][str[j+1]-'a'+1]=1;
    			lt[str[j+1]-'a'+1][str[j]-'a'+1]=1;
    			rd[str[j]-'a'+1]++;
				rd[str[j+1]-'a'+1]++; 
			}
		}
		flag=false;
		for(int j=1;j<=26;j++)
		{
			if(rd[j]<=1&&!vis[j])
			{
				if(!dfs(j))
				{
					flag=true;
					printf("NO\n");
					break;
				}
			}
		}
		if(flag==false)
		{
			if(cnt!=26)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
				for(int i=1;i<=26;i++)printf("%c",'a'+ans[i]-1);
				printf("\n");
			}
		}
		cnt=0;
		for(int i=1;i<=26;i++)
		{
			vis[i]=false;
			ans[i]=0;
			rd[i]=0;
			for(int j=1;j<=26;j++)lt[i][j]=0;
		}
	}
    return 0;
}