#include <stdio.h>
const int N=200050;
const int M=4*N;
int x[M],ls[M],rs[M],clock,root1,root2;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int min(int a, int b){ return a>b?b:a;}
int C[N],a,b;
void Update(int x, int y)
{
	Set(root1,1,N,x,-min(C[x],b));
	Set(root2,1,N,x,-min(C[x],a));
	C[x]+=y;
	Set(root1,1,N,x,min(C[x],b));
	Set(root2,1,N,x,min(C[x],a));
}
int main()
{
	int n,q,k,i,t,x,y,p;
	scanf("%i %i %i %i %i",&n,&k,&a,&b,&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i %i",&x,&y),Update(x,y);
		else scanf("%i",&p),printf("%i\n",Get(root1,1,N,1,p-1)+Get(root2,1,N,p+k,n));
	}
	return 0;
}