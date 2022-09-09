#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=100050;
const int M=4*N;
const int S=317;
const ll inf=1e17;//1e9+7;
ll max(ll a, ll b){ return a>b?a:b;}
int max(int a, int b){ return a>b?a:b;}
ll BlockBest[N],BL[N],BR[N],OL[N],OR[N];
/*pair<ll,int> max(pair<ll,int> a, pair<ll,int> b)
{
	if(a.first>b.first) return a;
	return b;
}
ll x[M];
int id[N],ls[M],rs[M],clock,root1,root2;
void Build(int &c, int ss, int se)
{
	c=++clock;
	x[c]=-inf;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Set(int c, int ss, int se, int qi, ll X)
{
	//if(!c) c=++clock;
	if(ss==se)
	{
		x[c]=X;
		id[c]=qi;
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,X);
	else Set(rs[c],mid+1,se,qi,X);
	x[c]=max(x[ls[c]],x[rs[c]]);
	if(x[rs[c]]==x[c]) id[c]=id[rs[c]];
	else id[c]=id[ls[c]];
}
pair<ll,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return make_pair(-inf,0);
	if(qs<=ss && qe>=se) return make_pair(x[c],id[c]);
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}*/
ll sz[N],dist[N],U1[N],U2[N],V1[N],V2[N];
int main()
{
	int n,q,l,r,i,x,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&x),dist[i]=x; 
	for(i=1;i<=n;i++) scanf("%i",&x),sz[i]=x,sz[i]<<=1;
	//Build(root1,1,n);
	//Build(root2,1,n);
	for(i=0;i<=n;i++) BL[i]=-inf,BR[i]=-inf,BlockBest[i]=-inf;
	ll best=0;
	ll path=0;
	for(i=1;i<=n;i++)
	{
		U1[i]=max(U1[i-1],sz[i]+path);
		V1[i]=max(V1[i-1],sz[i]+path+best);
		BL[i/S]=max(BL[i/S],sz[i]-path);
		BR[i/S]=max(BR[i/S],sz[i]+path);
		OL[i]=sz[i]-path;
		OR[i]=sz[i]+path;
		//Set(root1,1,n,i,sz[i]-path);
		//Set(root2,1,n,i,sz[i]+path);
		best=max(best,sz[i]-path);
		path+=dist[i];
	}
	best=0;
	path=0;
	for(i=n;i;i--)
	{
		U2[i]=max(U2[i+1],sz[i]+path);
		V2[i]=max(V2[i+1],sz[i]+path+best);
		//Set(root3,1,n,sz[i]-path);
		//Set(root4,1,n,sz[i]+path);
		best=max(best,sz[i]-path);
		path+=dist[i-1];
	}
	for(i=0;i<=n;i++)
	{
		best=-inf;
		for(j=max(S*i,1);j<(i+1)*S && j<=n;j++)
		{
			BlockBest[i]=max(BlockBest[i],OR[j]+best);
			best=max(best,OL[j]);
		}
	}
	while(q--)
	{
		scanf("%i %i",&l,&r);
		if(l<=r)
		{
			//if(n==100000) printf(":D ");
			ll sol=V1[l-1];
			sol=max(sol,V2[r+1]);
			if(r!=n && l!=1) sol=max(sol,U1[l-1]+U2[r+1]+dist[n]);
			printf("%lld\n",sol);
		}
		else
		{
			int L=(r+1)/S;
			int R=(l-1)/S;
			ll sol=-inf;
			if(L==R)
			{
				best=-inf;
				for(i=r+1;i<=l-1;i++)
				{
					sol=max(sol,OR[i]+best);
					best=max(best,OL[i]);
				}
			}
			else
			{
				best=-inf;
				for(i=r+1;i<(L+1)*S;i++)
				{
					sol=max(sol,OR[i]+best);
					best=max(best,OL[i]);
				}
				for(i=L+1;i<R;i++)
				{
					sol=max(sol,BlockBest[i]);
					sol=max(sol,BR[i]+best);
					best=max(best,BL[i]);
				}
				for(i=R*S;i<=l-1;i++)
				{
					sol=max(sol,OR[i]+best);
					best=max(best,OL[i]);
				}
			}
			printf("%lld\n",sol);
			//printf(":D ");
			//int id=Get(root2,1,n,r+1,l-1).second;
			//int id2=Get(root1,1,n,r+1,l-1).second;
			//printf("%i %i %i\n",id,id2,Get(root1,1,n,r+1,l-1).first);
			//if(n==100000) printf("%i %i\n",id,id2);
			//ll sol=-1;
			//if(id>r+1) sol=max(sol,Get(root2,1,n,r+1,l-1).first+Get(root1,1,n,r+1,id-1).first);
			//if(id2<l-1) sol=max(sol,Get(root2,1,n,id2+1,l-1).first+Get(root1,1,n,r+1,l-1).first);
			//printf("%lld\n",sol);
		}
	}
	return 0;
}