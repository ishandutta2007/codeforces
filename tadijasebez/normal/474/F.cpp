#include <stdio.h>
#include <map>
using namespace std;
const int N=100050;
const int M=20*N;
int x[M],ls[M],rs[M],clock;
map<int,int> root;
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
int gcd(int x, int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int logs[N],Table[N][20],A[N];
void Preprocess()
{
	int k=0,i;
	for(i=0;i<N;i++)
	{
		if(i==1<<(k+1)) k++;
		logs[i]=k;
	}
}
void BuildSparseTable(int n)
{
	Preprocess();
	int i,j;
	for(i=1;i<=n;i++) Table[i][0]=A[i];
	for(j=1;j<20;j++)
	{
		for(i=1;i<=n-(1<<j)+1;i++)
		{
			Table[i][j]=gcd(Table[i][j-1],Table[i+(1<<(j-1))][j-1]);
		}

	}
}
int Query(int l, int r)
{
	int k=logs[r-l+1];
	return gcd(Table[l][k],Table[r-(1<<k)+1][k]);
}
int main()
{
	int n,q,i,l,r;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&A[i]),Set(root[A[i]],1,N,i);
	BuildSparseTable(n);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		printf("%i\n",r-l+1-Get(root[Query(l,r)],1,N,l,r));
	}
	return 0;
}