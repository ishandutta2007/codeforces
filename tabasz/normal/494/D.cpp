#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define int LL
#define PII pair<int, int>
const int mod=1000000007;


struct qwe
{
	int num, sqsum, sum;
};

vector<PII> V[100005], Z, W;
int res[100005];
vector<int> ZZ, WW;
bool vis[100005];
int pre[100005], post[100005], pr, po;
qwe C[100005], G[100005], D[100005], zero;
PII T[20][100005];

qwe mnoz(qwe x, int a)
{
	qwe z=x;
	z.sqsum=(x.sqsum+(((x.sum*2)%mod)*a)%mod+(((a*a)%mod)*(x.num+1))%mod)%mod;
	z.sum=(x.sum+((x.num+1)*a)%mod)%mod;
	z.num=(z.num+1)%mod;
	return z;
}

qwe odejmij(qwe x, qwe y)
{
	x.num-=y.num;
	x.sum-=y.sum;
	x.sqsum-=y.sqsum;
	while(x.num<0) x.num+=mod;
	while(x.sqsum<0) x.sqsum+=mod;
	while(x.sum<0) x.sum+=mod;
	return x;
}

qwe dodaj(qwe x, qwe y)
{
	x.num=(x.num+y.num)%mod;
	x.sum=(x.sum+y.sum)%mod;
	x.sqsum=(x.sqsum+y.sqsum)%mod;
	return x;
}

void DFS0(int v, int p, int od)
{
	T[0][v]=MP(p, od);
	vis[v]=1;
	pre[v]=pr;
	pr++;
	for(int i=0; i<(int)V[v].size(); i++) if(!vis[V[v][i].F]) DFS0(V[v][i].F, v, V[v][i].S);
	post[v]=po;
	po++;
}


qwe DFS(int v, int odl)
{
	vis[v]=1;
	qwe x=zero;
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i].F])
		{
			qwe y=DFS(V[v][i].F, V[v][i].S);
			x=dodaj(x, y);
		}
	}
	D[v]=x;
	return mnoz(x, odl);
}


void DFS2(int v, qwe x, int pop)
{
	vis[v]=1;
	G[v]=x;
	x=dodaj(x, D[v]);
	for(int i=0; i<(int)V[v].size(); i++)
	{
		if(!vis[V[v][i].F])
		{
			//qwe z=x;
			//for(int j=0; j<(int)V[v].size(); j++) if(V[v][j].F!=pop && j!=i) z=dodaj(z, mnoz(D[V[v][j].F], V[v][j].S));
			qwe y=mnoz(D[V[v][i].F], V[v][i].S);
			//if(v==1 && V[v][i].F==9) printf("%lld %lld %lld\n", y.sqsum, y.sum, y.num);
			qwe z=odejmij(x, y);
			//if(v==1 && V[v][i].F==9) printf("%lld %lld %lld\n", z.sqsum, z.sum, z.num);
			DFS2(V[v][i].F, mnoz(z, V[v][i].S), v);
		}
	}
	C[v]=dodaj(D[v], G[v]);
}

bool ancestor(int v, int u)
{
    if(pre[u]>pre[v] && post[u]<post[v]) return true;
    return false;
}

int lca(int a, int b)
{
    if(ancestor(a, b)) return a;
    if(ancestor(b, a)) return b;
    int v=a, i=19;
    while(i>=0)
    {
        if(ancestor(T[i][v].F, b)) i--;
        else v=T[i][v].F;
    }
    return T[0][v].F;
}

int odll(int a, int b)
{
    int v=b, i=19, re=0;
    while(i>=0)
    {
    	if(T[i][v].F==a)
    	{
    		re=(re+T[i][v].S)%mod;
    		break;
    	}
        if(ancestor(T[i][v].F, a)) i--;
        else
        {
        	re=(re+T[i][v].S)%mod;
        	v=T[i][v].F;
        }
    }
    return re;
}

int odl(int v, int u)
{
	if(ancestor(v, u)) return odll(v, u);
	if(ancestor(u, v)) return odll(u, v);
	int lc=lca(v, u);
	return (odll(lc, v)+odll(lc, u))%mod;
}

int iop, jkl;

void DFS3(int v, int x)
{
	vis[v]=1;
	iop=(iop+x*x)%mod;
	jkl=(jkl+x)%mod;
	for(int i=0; i<(int)V[v].size(); i++) if(!vis[V[v][i].F]) DFS3(V[v][i].F, (x+V[v][i].S)%mod);
}

main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>> n;
	for(int i=1; i<n; i++)
	{
		int a, b, c;
		cin>> a >> b >> c;
		V[a].PB(MP(b, c));
		V[b].PB(MP(a, c));	
	}
	DFS0(1, 1, 0);
	for(int i=1; i<20; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int asd=T[i-1][j].F;
			T[i][j].F=T[i-1][asd].F;
			T[i][j].S=T[i-1][j].S+T[i-1][asd].S;
		}
	}
	for(int i=0; i<=n; i++) vis[i]=0;
	cin>> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>> a >> b;
		if(ancestor(b, a))
		{
			W.PB(MP(a, b));
			WW.PB(i);
		}
		else
		{
			ZZ.PB(i);
			Z.PB(MP(a, b));
		}
	}
	DFS(1, 0);
	for(int i=0; i<=n; i++) vis[i]=0;
	DFS2(1, zero, 1);
	for(int i=0; i<(int)W.size(); i++)
	{
		int od=odl(W[i].F, W[i].S);
		int r=C[W[i].F].sqsum-2*mnoz(G[W[i].S], od).sqsum+(2*od*od)%mod;
		while(r<0) r+=mod;
		while(r>=mod) r-=mod;
		res[WW[i]]=r;
	}
	for(int i=0; i<(int)Z.size(); i++)
	{
		if(Z[i].F==Z[i].S)
		{
			res[ZZ[i]]=D[Z[i].F].sqsum-G[Z[i].F].sqsum;
			if(res[ZZ[i]]<0) res[ZZ[i]]+=mod;
			continue;
		}
		int od=odl(Z[i].F, Z[i].S);
		int r=((2*mnoz(D[Z[i].S], od).sqsum)%mod-C[Z[i].F].sqsum);
		while(r<0) r+=mod;
		res[ZZ[i]]=r;
	}
	for(int i=0; i<m; i++) cout<< res[i] << '\n';
	return 0;
}