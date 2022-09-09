#include <stdio.h>
const int N=100050;
const int M=N*200;//*17;
int x[M],ls[M],rs[M],clock,root[N];
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock;
	x[c]++;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int n,x,i,j,k,y;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x,&y);
		int sol=0;
		for(j=1;j*j<=x;j++)
		{
			if(x%j==0)
			{
				k=x/j;
				if(k==j)
				{
					if(Get(root[j],1,n,i-y,i)==0) sol++;
					Set(root[j],1,n,i);
				}
				else
				{
					if(Get(root[j],1,n,i-y,i)==0) sol++;
					Set(root[j],1,n,i);
					if(Get(root[k],1,n,i-y,i)==0) sol++;
					Set(root[k],1,n,i);
				}
			}
		}
		printf("%i\n",sol);
	}
	return 0;
}