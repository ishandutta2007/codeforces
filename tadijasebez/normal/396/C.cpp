#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=300050;
const int M=2*N;
struct Node
{
	int A,B;
	Node(){ A=0,B=0;}
	Node(int a, int b){ A=a,B=b;}
	Node operator + (Node b) const
	{
		Node c;
		c.A=(A+b.A)%mod;
		c.B=(B+b.B)%mod;
		return c;
	}
} x[M];
int ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qs, int qe, Node val)
{
	if(ss>qe || qs>se) return;
	if(!c) c=++clock;
	if(qs<=ss && qe>=se){ x[c]=x[c]+val;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
}
Node Get(int c, int ss, int se, int qi)
{
	if(ss==se) return x[c];
	int mid=ss+se>>1;
	if(qi<=mid) return x[c]+Get(ls[c],ss,mid,qi);
	else return x[c]+Get(rs[c],mid+1,se,qi);
}
vector<int> E[N];
int b[N],e[N],time,Depth[N];
void DFS(int c, int p, int d)
{
	Depth[c]=d;
	b[c]=++time;
	for(int i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p) DFS(v,c,d+1);
	}
	e[c]=time;
}
int main()
{
	int n,q,x,k,u,i,t;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&u),E[u].push_back(i);
	DFS(1,0,0);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&u,&x,&k);
			int A=(x+(ll)k*Depth[u]%mod)%mod;
			int B=k;
			Set(root,1,N,b[u],e[u],Node(A,B));
		}
		else
		{
			scanf("%i",&u);
			Node tmp=Get(root,1,N,b[u]);
			int ans=(tmp.A-(ll)tmp.B*Depth[u]%mod)%mod;
			ans=(ans+mod)%mod;
			printf("%i\n",ans);
		}
	}
	return 0;
}