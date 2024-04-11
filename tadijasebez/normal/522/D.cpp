#include <stdio.h>
#include <map>
using namespace std;
const int N=500050;
const int M=20*N;
const int inf=1e9;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],root[M],clock;
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock;ls[c]=ls[p],rs[c]=rs[p],x[c]=min(x[p],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int A[N];
map<int,int> P;
int main()
{
	int n,q,i,l,r;
	x[0]=inf;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);
	for(i=n;i;i--)
	{
		root[i]=root[i+1];
		if(P[A[i]]) Set(root[i],root[i],1,N,P[A[i]],P[A[i]]-i);
		P[A[i]]=i;
	}
	while(q--){
		scanf("%i %i",&l,&r);
		int tmp=Get(root[l],1,N,l,r);
		if(tmp<inf) printf("%i\n",tmp);
		else printf("-1\n");
	}
	return 0;
}