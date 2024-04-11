#include<iostream>
#include<cstdio>
#define int long long
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
char s[200005];
bool check(int k)
{
	if(k<=0)return false;
	if(s[k]=='a'&&s[k+1]=='b'&&s[k+2]=='c')return true;
	return false;
}
char ch[10];
signed main()
{
	int t,n,q,ans=0,x;
	n=read();
	q=read();
	scanf("%s",s+1);
	//printf("%d\n",s[1]);
	for(int i=1;i<=n-2;i++)
	{
		if(check(i))ans++;
	}
	for(int i=1;i<=q;i++)
	{
		x=read();
		scanf("%s",ch+1);
		if(check(x-2))ans--;
		if(check(x-1))ans--;
		if(check(x))ans--;
		s[x]=ch[1];
		if(check(x-2))ans++;
		if(check(x-1))ans++;
		if(check(x))ans++;
		printf("%d\n",ans);
	}
	return 0;
}