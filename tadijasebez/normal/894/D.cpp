#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1000500;
const int M=20*N;
/*pair<ll,int> x[M];
int ls[M],rs[M],root[N],clock;
void Set(int &c, int ss, int se, int qi, ll val)
{
	if(!c) c=++clock;
	x[c].first+=val;
	x[c].second++;
	//printf("%i %i\n",ss,se);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
pair<ll,int> Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return x[0];
	if(ss>qe || qs>se) return x[0];
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	pair<ll,int> u=Get(ls[c],ss,mid,qs,qe);
	pair<ll,int> v=Get(rs[c],mid+1,se,qs,qe);
	u.first+=v.first;
	u.second+=v.second;
	return u;
}*/
int l[N],r[N],par[N],w[N];
int Dist[N],S[N];
vector<int> index[N];
vector<ll> dp[N];
void Prepare1(int c, int u);
//void Prepare2(int c, int u);
void DFS(int c, int d)
{
	d+=w[c];
	Dist[c]=d;
	if(l[c]) DFS(l[c],d);
	if(r[c]) DFS(r[c],d);
	Prepare1(c,c);
	sort(index[c].begin(),index[c].end());
	//index[c].erase(unique(index[c].begin(),index[c].end()),index[c].end());
	S[c]=index[c].size();
	//Prepare2(c,c);
	ll tmp=0;
	dp[c].push_back(0);
	for(int i=0;i<S[c];i++) tmp+=index[c][i],dp[c].push_back(tmp);
}
void Prepare1(int c, int u)
{
	index[u].push_back(Dist[c]);
	if(l[c]) Prepare1(l[c],u);
	if(r[c]) Prepare1(r[c],u);
}
int FindIndex(int x, int u){ return lower_bound(index[u].begin(),index[u].end(),x)-index[u].begin()+1;}
int FindUpper(int x, int u){ return upper_bound(index[u].begin(),index[u].end(),x)-index[u].begin();}
/*void Prepare2(int c, int u)
{
	Set(root[u],1,S[u],FindIndex(Dist[c],u),Dist[c]);
	//printf("%i\n",c);
	if(l[c]) Prepare2(l[c],u);
	if(r[c]) Prepare2(r[c],u);
}*/
int main()
{
	int n,m,i,j,u,H;
	scanf("%i %i",&n,&m);
	for(i=2;i<=n;i++)
	{
		scanf("%i",&w[i]);
		j=i/2;
		par[i]=j;
		if(l[j]) r[j]=i;
		else l[j]=i;
	}
	DFS(1,0);
	while(m--)
	{
		scanf("%i %i",&u,&H);
		ll ans=0,sum=0,edge=0;
		int cnt=0;
		j=u;
		while(u)
		{
			if(u!=j)
			{
				if(edge<H) sum+=edge,cnt++;
			}
			if(j)
			{
				//printf("%i %i\n",u,j);
				int id=FindUpper(Dist[u]+H-edge,j);
				//pair<ll,int> tmp=Get(root[j],1,S[j],1,id);
				cnt+=id;//tmp.second;
				//printf("%lld %i\n",tmp.A,tmp.B);
				//ll tr=tmp.first-(ll)(Dist[u]-edge)*tmp.second;
				ll tr=dp[j][id]-(ll)(Dist[u]-edge)*id;
				sum+=tr;	
			}
			edge+=w[u];
			if(l[par[u]]==u) j=r[par[u]];
			else j=l[par[u]];
			u=par[u];
		}
		ans=(ll)cnt*H-sum;
		printf("%lld\n",ans);
	}
	return 0;
}