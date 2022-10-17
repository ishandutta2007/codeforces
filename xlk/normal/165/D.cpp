#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<int> vi;
int n;
int a[400020][3],tot;
int h[400020];
int pl[400020];
int pp[400020];
int in[400020];
int w[400020];
int s[400020],ss;
int bl;
int r[400020];
int l[400020];
int c[400020];
inline void R(int x,const int y)
{
	for(;x<=ss;x+=x&-x)
		c[x]+=y;
}
inline int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void dfs(int x,int y)
{
	s[++ss]=x;
	pp[x]=ss;
	l[x]=bl;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
		{
			pl[a[i][2]]=ss+1;
			dfs(a[i][1],x);	
		}
	return;
}
int main()
{
	int i,x,y,st;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y,i);
		add(y,x,i);
		in[x]++;
		in[y]++;
	}	
	st=1;
	fo(i,n)
		if(in[i]>2)
		{
			st=i;
			break;
		}
	for(i=h[st];i;i=a[i][0])
	{
		bl++;
		r[bl]=ss;
		pl[a[i][2]]=ss+1;
		dfs(a[i][1],st);
	}
	int q;
	for(i=1;i<=ss;i++)
		R(i,1),w[i]=1;
	scanf("%d",&q);
	while(q--)
	{
		int x,y,z;
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&y);
			if(!w[pl[y]])
			{
				w[pl[y]]=1;
				R(pl[y],1);
			}
		}
		else if(x==2)
		{
			scanf("%d",&y);
			if(w[pl[y]])
			{
				w[pl[y]]=0;
				R(pl[y],-1);
			}
		}
		else
		{
			scanf("%d %d",&y,&z);
			if(r[l[y]]!=r[l[z]])
			{
				if(G(pp[y])-G(r[l[y]])+G(pp[z])-G(r[l[z]])==pp[y]-r[l[y]]+pp[z]-r[l[z]])
					printf("%d\n",pp[y]-r[l[y]]+pp[z]-r[l[z]]);
				else
					puts("-1");
			}
			else
			{
				if(pp[y]<pp[z])
					swap(y,z);
				if(G(pp[y])-G(pp[z])==pp[y]-pp[z])
					printf("%d\n",pp[y]-pp[z]);
				else
					puts("-1");
			}
		}
	}
	return 0;
}