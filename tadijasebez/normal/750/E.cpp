#include <stdio.h>
const int inf=1e9+7;
const int N=200050;
const int M=2*N;
int min(int a, int b){ return a>b?b:a;}
struct Matrix
{
	int a[5][5];
	Matrix(){ for(int i=0;i<5;i++) for(int j=0;j<5;j++) a[i][j]=inf;}
	void id(){ for(int i=0;i<5;i++) a[i][i]=0;}
	Matrix operator * (Matrix b) const
	{
		Matrix c;
		for(int i=0;i<5;i++) for(int j=0;j<5;j++) for(int k=0;k<5;k++) c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
		return c;
	}
} node[M],ID;
char s[N];
int ls[M],rs[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se)
	{
		node[c].id();
		if(s[ss]=='2') node[c].a[0][0]=1,node[c].a[0][1]=0;
		if(s[ss]=='0') node[c].a[1][1]=1,node[c].a[1][2]=0;
		if(s[ss]=='1') node[c].a[2][2]=1,node[c].a[2][3]=0;
		if(s[ss]=='7') node[c].a[3][3]=1,node[c].a[3][4]=0;
		if(s[ss]=='6') node[c].a[3][3]=1,node[c].a[4][4]=1;
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]*node[rs[c]];
}
Matrix Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return ID;
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)*Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	ID.id();
	int n,q,i,l,r;
	scanf("%i %i",&n,&q);
	scanf("%s",s+1);
	Build(root,1,n);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		int ans=Get(root,1,n,l,r).a[0][4];
		if(ans>=inf) printf("-1\n");
		else printf("%i\n",ans);
	}
	return 0;
}