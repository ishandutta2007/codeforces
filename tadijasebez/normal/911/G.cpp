#include <stdio.h>
const int N=400050;
const int M=105;
int max(int a, int b){ return a>b?a:b;}
int x[N][M],y[N][M],ls[N],rs[N],clock,root,a[N],m,i;
bool done[N];
void Propagate(int c, int ss, int se)
{
	if(done[c]) return;
	if(ss!=se)
	{
		for(i=1;i<=m;i++) x[c][i]=y[c][x[c][i]],y[ls[c]][i]=y[c][y[ls[c]][i]],y[rs[c]][i]=y[c][y[rs[c]][i]];
		done[ls[c]]=0;
		done[rs[c]]=0;
	}
	else for(i=1;i<=m;i++) x[c][i]=y[c][x[c][i]];
	for(i=1;i<=m;i++) y[c][i]=i;
	done[c]=1;
}
void Build(int &c, int ss, int se)
{
	c=++clock;
	done[c]=1;
	for(i=1;i<=m;i++) y[c][i]=i,x[c][i]=i;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qs, int qe, int X, int Y)
{
	//printf("%i %i\n",ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		for(i=1;i<=m;i++) if(y[c][i]==X) y[c][i]=Y;
		done[c]=0;
		return;
	}
	Propagate(c,ss,se);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,X,Y);
	Set(rs[c],mid+1,se,qs,qe,X,Y);
}
void Solve(int c, int ss, int se)
{
	Propagate(c,ss,se);
	if(ss==se)
	{
		printf("%i ",x[c][a[ss]]);
		return;
	}
	int mid=ss+se>>1;
	Solve(ls[c],ss,mid);
	Solve(rs[c],mid+1,se);
}
int main()
{
	int n,q,l,r,x,y,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),m=max(m,a[i]);
	Build(root,1,n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i %i",&l,&r,&x,&y);
		Set(root,1,n,l,r,x,y);
	}
	Solve(root,1,n);
	return 0;
}