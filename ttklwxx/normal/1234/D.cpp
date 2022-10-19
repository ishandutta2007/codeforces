#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[27][100001];
int n;
void insert(int wz,int x,int k)
{
	while(x<=n)
	{
		f[wz][x]+=k;
		x+=((x)&(-x));
	}
}
int query(int wz,int x)
{
	int ans=0;
	while(x)
	{
		ans+=f[wz][x];
		x-=((x)&(-x));
	}
	return ans;
}
char a[100001];
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
int main()
{
	int m,opt,x,y,ans;
	char c;
	scanf("%s",a+1);
	n=strlen(a+1);
	m=read();
	for(int i=1;i<=n;i++)insert(a[i]-'a'+1,i,1);
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)
		{
			x=read();
			c=getchar();
			while(c<'a'||c>'z')c=getchar();
			insert(a[x]-'a'+1,x,-1);
			insert(c-'a'+1,x,1);
			a[x]=c;
		}
		else
		{
			x=read();
			y=read();
			ans=0;
			for(int j=1;j<=26;j++)
			{
				if(query(j,y)-query(j,x-1)>0)ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}