#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;
const int N=1000050;
const int M=10*N;
int x[M],ls[M],rs[M],clock,root[N];
int A[N+1];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=A[ss];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]^x[rs[c]];
}
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	x[c]^=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock;ls[c]=ls[p];rs[c]=rs[p];x[c]=x[p]^val;
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
	return Get(ls[c],ss,mid,qs,qe)^Get(rs[c],mid+1,se,qs,qe);
}
unordered_map<int,int> P,PP;
int cnt,L[N],R[N],ans[N];
vector< pair<int,int> > Q[N];
int main()
{
	int n,i,q,l,r,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&A[i]);//,Set(root[0],1,N,i,A[i]);
	Build(root[0],1,N);
	/*for(i=n;i;i--)
	{
		cnt++;
		if(PP[A[i]]) cnt++;
		PP[A[i]]=i;
	}*/
	//if(n==1000000) return printf("%i\n",cnt),0;
	scanf("%i",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&L[i],&R[i]);
		ans[i]=Get(root[0],1,N,L[i],R[i]);
		Q[L[i]].push_back(make_pair(R[i],i));
		//printf("%i\n",Get(root[0],1,N,l,r)^Get(root[l],1,N,l,r));
	}
	for(i=n;i;i--)
	{
		Set(root[1],1,N,i,A[i]);
		if(P[A[i]]) Set(root[1],1,N,P[A[i]],A[i]);
		P[A[i]]=i;
		for(j=0;j<Q[i].size();j++)
		{
			ans[Q[i][j].second]^=Get(root[1],1,N,i,Q[i][j].first);
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}