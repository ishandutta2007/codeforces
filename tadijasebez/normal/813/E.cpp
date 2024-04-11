#include <stdio.h>
#include <queue>
using namespace std;
const int N=100050;
const int M=50*N;
int x[M],ls[M],rs[M],clock,root[N];
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]+val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
queue<int> q[N];
int main()
{
	int n,k,i,u;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		Set(root[i],root[i],1,n,i,1);
		scanf("%i",&u);
		q[u].push(i);
		while(q[u].size()>k) Set(root[i],root[i],1,n,q[u].front(),-1),q[u].pop();
	}
	int q,l,r;
	scanf("%i",&q);
	int last=0;
	while(q--)
	{
		scanf("%i %i",&l,&r);
		l=(l+last)%n+1;
		r=(r+last)%n+1;
		if(l>r){ int tmp=l;l=r;r=tmp;}
		last=Get(root[r],1,n,l,r);
		printf("%i\n",last);
	}
	return 0;
}