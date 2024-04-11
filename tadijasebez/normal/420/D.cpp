#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int ls[N],rs[N],tsz,root,val[N],sz[N],h[N],f[N];
void Pull(int c){ if(c) sz[c]=sz[ls[c]]+sz[rs[c]]+1;}
void RotR(int &c)
{
	int a=ls[c],b=rs[a];
	ls[c]=b;
	rs[a]=c;
	Pull(c);Pull(a);
	c=a;
}
void RotL(int &c)
{
	int a=rs[c],b=ls[a];
	rs[c]=b;
	ls[a]=c;
	Pull(c);Pull(a);
	c=a;
}
void Insert(int &c, int f)
{
	if(!c){ c=f;Pull(c);return;}
	Insert(ls[c],f);
	if(h[ls[c]]>h[c]) RotR(c);
	else Pull(c);
}
int ans;
void Del(int &c, int k)
{
	if(sz[ls[c]]+1==k || c==ans)
	{
		ans=c;
		if(!ls[c]) c=rs[c];
		else if(!rs[c]) c=ls[c];
		else
		{
			if(h[ls[c]]<h[rs[c]])
			{
				RotR(c);
				Del(rs[c],0);
				if(rs[c] && h[rs[c]]>h[c]) RotL(c);
				else Pull(c);
			}
			else
			{
				RotL(c);
				Del(ls[c],0);
				if(ls[c] && h[ls[c]]>h[c]) RotR(c);
				else Pull(c);
			}
		}
	}
	else if(sz[ls[c]]+1<k)
	{
		Del(rs[c],k-sz[ls[c]]-1);
		if(rs[c] && h[rs[c]]>h[c]) RotL(c);
		else Pull(c);
	}
	else
	{
		Del(ls[c],k);
		if(ls[c] && h[ls[c]]>h[c]) RotR(c);
		else Pull(c);
	}
}
int main()
{
	srand(time(0));
	int n,m,i,x,y;
	scanf("%i %i",&n,&m);
	for(i=n;i>=1;i--) h[i]=rand()<<15|rand(),Insert(root,i);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&x,&y);
		ans=-1;
		Del(root,y);
		if((val[ans] && val[ans]!=x) || (f[x] && f[x]!=ans)) return 0*printf("-1\n");
		val[ans]=x;f[x]=ans;
		ls[ans]=rs[ans]=0;
		Insert(root,ans);
	}
	queue<int> wait;
	for(i=1;i<=n;i++) if(!f[i]) wait.push(i);
	for(i=1;i<=n;i++) if(!val[i]) val[i]=wait.front(),wait.pop();
	for(i=1;i<=n;i++) printf("%i ",val[i]);
	return 0;
}