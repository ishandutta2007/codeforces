#include<bits/stdc++.h>
using namespace std;
const int N=25005;
int n,q,s,p[N],a[N],l1[N],l2[N],r1[N],r2[N];
void la(int x,int y){r2[x]=y,l1[y]=x,s++;}
void lb(int x,int y){r1[x]=y,l2[y]=x,s++;}
void ca(int x,int y){s-=(r2[x]==y&&l1[y]==x);}
void cb(int x,int y){s-=(r1[x]==y&&l2[y]==x);}
void sol(int x,int y)
{
	if(p[x]<p[y]){if(p[x]>p[l1[y]])ca(x,r2[x]),ca(l1[y],y),la(x,y);}
	else{if(p[y]>p[r1[x]])cb(x,r1[x]),cb(l2[y],y),lb(x,y);}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),a[i]=i;
	while(q--)
	{
		int l,r,i;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
		{
			while(a[i]>l)
			{
				a[i]--;
				sol(a[i],i);
			}
		}
		printf("%d\n",s);
	}
	return 0;
}