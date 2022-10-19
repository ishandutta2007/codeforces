#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,v[N],tr[N],c[N][2],f[N],q[N],tag[N],tp,tg[N],h[N],th[N],z[N];
inline int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
inline void pushup(int x)
{
	tr[x]=(tr[c[x][0]]^tr[c[x][1]]^v[x]);
	th[x]=(th[c[x][0]]|th[c[x][1]]|h[x]);
	z[x]=(z[c[x][0]]|z[c[x][1]]|(x>n));
}
inline void pushdown(int x)
{
	if(tag[x])
	{
		tag[c[x][0]]^=1;
		tag[c[x][1]]^=1;
		swap(c[x][0],c[x][1]);
		tag[x]=0;
	}
	if(tg[x])
	{	
		tg[c[x][0]]=1;
		th[c[x][0]]=z[c[x][0]];
		tg[c[x][1]]=1;
		th[c[x][1]]=z[c[x][1]];
		h[x]=(x>n);
		th[x]=z[x];
		tg[x]=0;
	}
}
inline int isrt(int x){return c[f[x]][0]!=x&&c[f[x]][1]!=x;}
inline void rotate(int x)
{
	int y=f[x],z=f[y],l=c[y][1]==x,r=l^1;
	if(!isrt(y))
		c[z][c[z][1]==y]=x;
	f[x]=z,c[y][l]=c[x][r],f[c[x][r]]=y;
	c[x][r]=y,f[y]=x;
	pushup(y),pushup(x);
}
inline void splay(int x)
{
	tp=1,q[tp]=x;
	for(int i=x;!isrt(i);i=f[i])
		q[++tp]=f[i];
	for(int i=tp;i;i--)
		pushdown(q[i]);
	while(!isrt(x))
	{
		int y=f[x],z=f[y];
		if(!isrt(y))
			rotate(((c[y][0]==x)^(c[z][0]==y))?x:y);
		rotate(x);
	}
}
void access(int x){for(int t=0;x;t=x,x=f[x]){splay(x);c[x][1]=t;pushup(x);}}
void makeroot(int x){access(x);splay(x);tag[x]^=1;}
int find(int x){access(x);splay(x);while(c[x][0])x=c[x][0];return x;}
void split(int x,int y){makeroot(x);access(y);splay(y);}
void cut(int x,int y){split(x,y);if(c[y][0]==x&&c[x][1]==0){c[y][0]=0;f[x]=0;}}
void link(int x,int y){makeroot(x);f[x]=y;}
int main()
{
	n=rd(),m=rd();
	for(int i=1;i<=m;i++)
	{
		int x=rd(),y=rd(),w=rd();
		v[n+i]=w;
		if(find(x)!=find(y))
		{
			link(x,n+i);
			link(y,n+i);
			puts("YES");
		}
		else
		{
			split(x,y);
			if(!(tr[y]^w)||th[y])
				puts("NO");
			else
			{
				tg[y]=1;
				puts("YES");
			}
		}
	}
	return 0;
}