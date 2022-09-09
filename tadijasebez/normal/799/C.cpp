#include <stdio.h>
const int N=100050;
const int M=4*N;
const int inf=1e9;
int x[M],ls[M],rs[M],clock,root1,root2;
int max(int a, int b){ return a>b?a:b;}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]=max(x[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return -inf;
	if(ss>qe || qs>se) return -inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int tmp,n,b,p,c,d,sol;
char t;
int main()
{
	scanf("%i %i %i",&n,&c,&d);
	x[0]=-inf;
	while(n--)
	{
		scanf("%i %i %c",&b,&p,&t);
		if(t=='C' && p<=c)
		{
			tmp=max(Get(root1,1,N,1,c-p),Get(root2,1,N,1,d))+b;
			sol=max(sol,tmp);
			Set(root1,1,N,p,b);
		}
		if(t=='D' && p<=d)
		{
			tmp=max(Get(root1,1,N,1,c),Get(root2,1,N,1,d-p))+b;
			sol=max(sol,tmp);
			Set(root2,1,N,p,b);
		}
	}
	printf("%i\n",sol);
	return 0;
}