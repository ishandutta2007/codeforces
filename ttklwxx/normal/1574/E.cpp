#include<iostream>
#include<cstdio>
#include<map>
#define mod 998244353
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
int n,m,q,a[1000005][2],b[1000005][2],c[2],pw[2000005];
int s1,t1,s2,t2;
map<int,int>mp[1000005];
void cal(int x,int y,int z)
{
	if(a[y][0])c[y&1]+=z;
	if(a[y][1])c[(y&1)^1]+=z;
	if(a[y][0]&&a[y][1]) t1+=z;
	if(!a[y][0]&&!a[y][1]) s1+=z;
	if(b[x][0]&&b[x][1]) t2+=z;
	if(!b[x][0]&&!b[x][1]) s2+=z;
}
void del(int x,int y,int z)
{
	a[y][(x&1)^z]--;
	b[x][(y&1)^z]--;
	mp[x][y]=0;
}
void ins(int x,int y,int z)
{
	a[y][(x&1)^z]++;
	b[x][(y&1)^z]++;
	mp[x][y]=z+1;
}
int main()
{
	pw[0]=1;
	for(int i=1;i<1000005;i++)pw[i]=(pw[i-1]<<1)%mod;
	n=read();
	m=read();
	q=read();
	s1=m; s2=n;
	for(int greg=1;greg<=q;greg++)
	{
		int x,y,t;
		x=read();
		y=read();
		t=read();
		cal(x,y,-1);
		if(mp[x][y])del(x,y,mp[x][y]-1);
		if(~t) ins(x,y,t);
		cal(x,y,1);
		int ans=(pw[s1]*(!t1)+pw[s2]*(!t2))%mod;
		if(!c[0]) ans--;
		if(!c[1]) ans--;
		ans=(ans+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}