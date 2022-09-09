#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=1005;
const int K=2*N;
int a[N],lid[N],rid[N],tid,nod[N],n,m;
vector<int> E[N];
void DFS(int u, int p){ lid[u]=++tid;nod[tid]=u;for(int v:E[u]) if(v!=p) DFS(v,u);rid[u]=tid;}
int ls[K],rs[K],tsz,root,lzy[K];
bitset<M> node[K];
void Build(int &c, int ss, int se)
{
	c=++tsz;
	if(ss==se){ node[c].set(a[nod[ss]]);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]|node[rs[c]];
}
void Push(int c)
{
	if(!lzy[c]) return;
	node[ls[c]]=(node[ls[c]]<<lzy[c])|(node[ls[c]]>>(m-lzy[c]));
	node[rs[c]]=(node[rs[c]]<<lzy[c])|(node[rs[c]]>>(m-lzy[c]));
	lzy[ls[c]]=(lzy[ls[c]]+lzy[c])%m;
	lzy[rs[c]]=(lzy[rs[c]]+lzy[c])%m;
	lzy[c]=0;
}
void Inc(int c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se)
	{
		node[c]=(node[c]<<f)|(node[c]>>(m-f));
		lzy[c]=(lzy[c]+f)%m;
		return;
	}
	int mid=ss+se>>1;
	Push(c);
	Inc(ls[c],ss,mid,qs,qe,f);
	Inc(rs[c],mid+1,se,qs,qe,f);
	node[c]=node[ls[c]]|node[rs[c]];
}
bitset<M> ans;
void Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ ans|=node[c];return;}
	int mid=ss+se>>1;
	Push(c);
	Get(ls[c],ss,mid,qs,qe);
	Get(rs[c],mid+1,se,qs,qe);
}
int main()
{
	int q,i,j,u,v,x,t;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]%=m;
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	Build(root,1,n);
	bitset<M> prime;
	for(i=2;i<m;i++)
	{
		bool ok=1;
		for(j=2;j*j<=i;j++) if(i%j==0) ok=0;
		if(ok) prime.set(i);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&t,&u);
		if(t==1)
		{
			scanf("%i",&x);
			Inc(root,1,n,lid[u],rid[u],x%m);
		}
		else
		{
			ans=0;
			Get(root,1,n,lid[u],rid[u]);
			printf("%i\n",(ans&prime).count());
		}
	}
	return 0;
}