#include <stdio.h>
#include <vector>
using namespace std;
const int N=300050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],y[M],id[M],ls[M],rs[M],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;x[c]=0;y[c]=0;id[c]=ss;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qs, int qe, int val)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ x[c]+=val;y[c]+=val;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=max(x[ls[c]],x[rs[c]])+y[c];
	if(x[ls[c]]>x[rs[c]]) id[c]=id[ls[c]];
	else id[c]=id[rs[c]];
}
struct Event
{
	int l,r,val;
	Event(int a, int b, int c){ l=a,r=b,val=c;}
};
vector<Event> E[N];
int sol,ans,taj;
int l[N],r[N],v[N];
int main()
{
	int i,j,n;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&l[i],&v[i],&r[i]);
		E[l[i]].push_back(Event(v[i],r[i],1));
		E[v[i]+1].push_back(Event(v[i],r[i],-1));
	}
	Build(root,1,N);
	for(i=1;i<N;i++)
	{
		for(j=0;j<E[i].size();j++) Set(root,1,N,E[i][j].l,E[i][j].r,E[i][j].val);
		if(sol<x[root])
		{
			sol=x[root];
			ans=i;
			taj=id[root];
		}
	}
	printf("%i\n",sol);
	for(i=1;i<=n;i++) if(ans<=v[i] && ans>=l[i] && taj<=r[i] && taj>=v[i]) printf("%i ",i);
	printf("\n");
	return 0;
}