#include <stdio.h>
const int N=200050;
const int M=2*30*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],clock,root1,root2;
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(qs>qe) return;
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se){ x[c]=max(x[c],val);return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return max(x[c],Get(ls[c],ss,mid,qi));
	else return max(x[c],Get(rs[c],mid+1,se,qi));
}
int main()
{
	char t;
	int n,q,x,y,i;
	scanf("%i %i",&n,&q);
	while(q --> 0)
	{
		scanf("%i %i %c",&y,&x,&t);
		if(t=='L')
		{
			int k=Get(root1,1,n,x);
			printf("%i\n",y-k);
			Set(root1,1,n,x,x,y);
			Set(root2,1,n,k+1,y,x);
		}
		else
		{
			int k=Get(root2,1,n,y);
			printf("%i\n",x-k);
			Set(root2,1,n,y,y,x);
			Set(root1,1,n,k+1,x,y);
		}
	}
	return 0;
}