#include <stdio.h>
const int NN=100050;
const int M=4*NN;
int x[M],ls[M],rs[M],clock,root1,root2;//1 -> positive, 2 -> negative
void Set(int &c, int ss, int se, int qs, int qe)
{
	if(qe<qs) return;
	if(!c) c=++clock;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ x[c]++;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
}
int Get(int c, int ss, int se, int qi)
{//printf("%i %i\n",ss,se);
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return x[c]+Get(ls[c],ss,mid,qi);
	else return x[c]+Get(rs[c],mid+1,se,qi);
}
int CP[NN],CN[NN],P,N;
int A[NN],cnt;
int main()
{
	char t;
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("\n%c%i",&t,&A[i]);
		if(t=='-') N++,CN[A[i]]++,A[i]*=-1;
		else P++,CP[A[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		int tmp=0;
		tmp+=CP[i];
		tmp+=N-CN[i];
		if(tmp==m)
		{
			cnt++;
			Set(root1,1,NN,1,i-1);
			Set(root1,1,NN,i+1,n);
			Set(root2,1,NN,i,i);
		}
	}
	if(cnt==0)
	{
		for(i=1;i<=n;i++) printf("Not defined\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		int tmp;
		if(A[i]>0) tmp=Get(root1,1,NN,A[i]);
		else tmp=Get(root2,1,NN,-A[i]);
		if(tmp==cnt) printf("Lie\n");
		else if(tmp==0) printf("Truth\n");
		else printf("Not defined\n");
	}
	return 0;
}