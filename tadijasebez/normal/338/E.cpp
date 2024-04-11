#include <bits/stdc++.h>
using namespace std;
const int N=150050;
const int M=2*N;
int ls[M],rs[M],mn[M],lzy[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=mn[c]=0;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ mn[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
}
int b[N],a[N],c[N];
int main()
{
	int n,m,h,i;
	scanf("%i %i %i",&n,&m,&h);
	for(i=1;i<=m;i++) scanf("%i",&b[i]);sort(b+1,b+1+m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		int top=m,bot=1,mid,ans=m+1;
		while(top>=bot)
		{
            mid=top+bot>>1;
            if(b[mid]+a[i]>=h) ans=mid,top=mid-1;
            else bot=mid+1;
		}
		c[i]=ans;
	}
	Build(root,1,m);
	for(i=1;i<=m;i++) Add(root,1,m,i,i,-i);
	int sol=0;
	for(i=1;i<=n;i++)
	{
		Add(root,1,m,c[i],m,1);
		if(i>=m)
		{
			if(mn[root]>=0) sol++;
			Add(root,1,m,c[i-m+1],m,-1);
		}
	}
	printf("%i\n",sol);
	return 0;
}