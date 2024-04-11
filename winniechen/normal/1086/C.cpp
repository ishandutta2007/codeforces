#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define N 1000005
char a[N],b[N],s[N];
int k,T,tmp[27],vis[27],p,n,tt[27],vv[27];
bool check(int x,int cas)
{
	memcpy(tt,tmp,sizeof(tt));
	memcpy(vv,vis,sizeof(vv));
	if(cas==1)
	{
		for(int i=x;i<=n;i++)
		{
			if(tt[s[i]-'a']!=-1)
			{
				if(tt[s[i]-'a']>a[i])return 1;
				if(tt[s[i]-'a']<a[i])return 0;
				continue;
			}
			for(int j=a[i]+1;j<=k+'a'-1;j++)if(!vv[j-'a'])return 1;
			if(!vv[a[i]-'a'])vv[a[i]-'a']=1,tt[s[i]-'a']=a[i];
			else return 0;
		}
		return 1;
	}else
	{
		for(int i=x;i<=n;i++)
		{
			if(tt[s[i]-'a']!=-1)
			{
				if(tt[s[i]-'a']>b[i])return 0;
				if(tt[s[i]-'a']<b[i])return 1;
				continue;
			}
			for(int j='a';j<b[i];j++)if(!vv[j-'a'])return 1;
			if(!vv[b[i]-'a'])vv[b[i]-'a']=1,tt[s[i]-'a']=b[i];
			else return 0;
		}
		return 1;
	}
}
void solve()
{
	scanf("%d%s%s%s",&k,s+1,a+1,b+1);
	n=strlen(s+1);
	memset(tmp,-1,sizeof(tmp));p=n+1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(a[i]==b[i])
		{
			if(tmp[s[i]-'a']==a[i])continue;
			if(tmp[s[i]-'a']==-1&&!vis[a[i]-'a'])tmp[s[i]-'a']=a[i],vis[a[i]-'a']=1;
			else{puts("NO");return ;}
		}else{p=i;break;}
	int flag=0;
	for(int i=p;i<=n;i++)
	{
		if(!flag&&a[i]>b[i]){puts("NO");return ;}
		if(tmp[s[i]-'a']!=-1)
		{
			if((((flag&2)==0)&&tmp[s[i]-'a']<a[i])||(((flag&4)==0)&&tmp[s[i]-'a']>b[i])){puts("NO");return ;}
			if((flag&2)==0&&tmp[s[i]-'a']>a[i])flag|=2;
			if((flag&4)==0&&tmp[s[i]-'a']<b[i])flag|=4;
		}else if((flag&6)==0)
		{
			bool used=0;
			for(int j=a[i]+1;j<b[i];j++)
				if(!vis[j-'a'])
				{
					tmp[s[i]-'a']=j;
					vis[j-'a']=1;
					flag|=6;
					used=1;
					break;
				}
			if(!used)
			{
				if(!used&&!vis[b[i]-'a'])
				{
					vis[b[i]-'a']=1,tmp[s[i]-'a']=b[i];
					if(!check(i+1,2))vis[b[i]-'a']=0,tmp[s[i]-'a']=-1;
					else flag|=2,used=1;
				}
				if(!used&&!vis[a[i]-'a'])
				{
					vis[a[i]-'a']=1,tmp[s[i]-'a']=a[i];
					if(check(i+1,1))flag|=4,used=1;
				}
				if(!used){puts("NO");return ;}
			}
		}else if((flag&2)==0)
		{
			bool used=0;
			for(int j=a[i]+1;j<=k+'a'-1;j++)
				if(!vis[j-'a'])
				{
					tmp[s[i]-'a']=j;
					vis[j-'a']=1;
					flag|=2;
					used=1;
					break;
				}
			if(!used)
			{
				if(!vis[a[i]-'a'])vis[a[i]-'a']=1,tmp[s[i]-'a']=a[i];
				else{puts("NO");return ;}
			}
		}else if((flag&4)==0)
		{
			bool used=0;
			for(int j='a';j<b[i];j++)
				if(!vis[j-'a'])
				{
					tmp[s[i]-'a']=j;
					vis[j-'a']=1;
					flag|=4;
					used=1;
					break;
				}
			if(!used)
			{
				if(!vis[b[i]-'a'])vis[b[i]-'a']=1,tmp[s[i]-'a']=b[i];
				else{puts("NO");return ;}
			}
		}
		flag|=1;
		if(flag==7)break;
	}
	puts("YES");
	int now=0;
	while(vis[now])now++;
	for(int i=0;i<k;i++)
		if(tmp[i]==-1){tmp[i]='a'+now;vis[now]=1;while(vis[now])now++;}
	for(int i=0;i<k;i++)printf("%c",tmp[i]);puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
}