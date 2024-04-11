#include<iostream>
#include<cstdio>
#include<algorithm>
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
struct tree
{
	int l,r,d[4][4];
}a[800004];
void pushup(int k)
{
	for(int i=1;i<=3;i++)
	{
		for(int j=i;j<=3;j++)
		{
			a[k].d[i][j]=1000000000;
			for(int sth=i;sth<=j;sth++)
			{
				a[k].d[i][j]=min(a[k].d[i][j],a[k<<1].d[i][sth]+a[k<<1|1].d[sth][j]);
			}
		}
	}
	return;
}
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r)
	{
		a[k].d[s[l]-'a'+1][s[l]-'a'+1]++;
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	pushup(k);
	//printf("%d %d %d %d %d\n",l,r,a[k].d[1][1],a[k].d[1][2],a[k].d[1][3]);
}
void change(int x,int k)
{
	if(a[k].l==a[k].r)
	{
		a[k].d[1][1]=a[k].d[2][2]=a[k].d[3][3]=0;
		a[k].d[s[x]-'a'+1][s[x]-'a'+1]++;
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1);
	else change(x,k<<1|1);
	pushup(k);
}
signed main()
{
	int n,q,x;
	n=read();
	q=read();
	scanf("%s",s+1);
	build(1,n,1);
	char ch[10];
	for(int i=1;i<=q;i++)
	{
		x=read();
		scanf("%s",ch+1);
		s[x]=ch[1];
		change(x,1);
		printf("%d\n",a[1].d[1][3]);
	}
	return 0;
}