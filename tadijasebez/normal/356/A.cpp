#include <stdio.h>
const int inf=1e9;
const int N=300050;
const int M=2*N;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],clock,root;
void init(){for(int i=0;i<M;i++)x[i]=inf;}
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se){x[c]=min(x[c],val);return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
void Set(int &c, int qs, int qe, int val){Set(c,1,N,qs,qe,val);}
int A;
void Get(int c, int ss, int se, int qi)
{
	A=min(A,x[c]);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Get(ls[c],ss,mid,qi);
	else Get(rs[c],mid+1,se,qi);
}
int Get(int c, int qi){A=inf;Get(c,1,N,qi);return A;}
int X[N];
int main()
{
	int n,m,i,l,r;
	init();
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&l,&r,&X[i]);
		if(X[i]>l) Set(root,l,X[i]-1,i);
		if(X[i]<r) Set(root,X[i]+1,r,i);
	}
	for(i=1;i<=n;i++)
	{
		int y=Get(root,i);
		if(y==inf) printf("0 ");
		else printf("%i ",X[y]);
	}
	printf("\n");
	return 0;
}