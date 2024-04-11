#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int N=400050;
const int M=2*N;
const int L=60;
ll x[M];
int ls[M],rs[M],Lazy[M],clock,root,Node[N+1],a[N+1];
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se)
	{
		x[c]=(ll)1<<a[Node[ss]];
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]|x[rs[c]];
}
void Set(int c, int ss, int se, int qs, int qe, int val)
{
	if(Lazy[c]>0)
	{
		x[c]=(ll)1<<Lazy[c];
		if(ss!=se)
		{
			Lazy[ls[c]]=Lazy[c];
			Lazy[rs[c]]=Lazy[c];
		}
		Lazy[c]=0;
	}
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		x[c]=(ll)1<<val;
		//printf("%i %i %i %i\n",ss,se,qs,qe);
		if(ss!=se)
		{
			Lazy[ls[c]]=val;
			Lazy[rs[c]]=val;
		}
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=x[ls[c]]|x[rs[c]];
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(Lazy[c]>0)
	{
		x[c]=(ll)1<<Lazy[c];
		if(ss!=se)
		{
			Lazy[ls[c]]=Lazy[c];
			Lazy[rs[c]]=Lazy[c];
		}
		Lazy[c]=0;
	}
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)|Get(rs[c],mid+1,se,qs,qe);
}
vector<int> E[N];
int b[N],e[N],time;
void DFS(int c, int p)
{
	b[c]=++time;
	//printf("%i %i\n",c,p);
	Node[time]=c;
	int i;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p) DFS(v,c);
	}
	e[c]=time;
}
int main()
{
	int n,q,i,u,v,t;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	Build(root,1,n);
	//for(i=1;i<=n;i++) printf("%i ",b[i]);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&u,&v);
			Set(root,1,n,b[u],e[u],v);
		}
		else
		{
			scanf("%i",&u);
			ll tmp=Get(root,1,n,b[u],e[u]);
			int sol=0;
			for(i=1;i<=L;i++)
			{
				//if((tmp>>i)&1) printf("%i ",i);
				sol+=(tmp>>i)&1;
			}
			//printf("-> ");
			printf("%i\n",sol);
		}
	}
	return 0;
}