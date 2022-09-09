#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
const int N=210;
const ll inf=3e18;
ll max(ll a, ll b){ return a>b?a:b;}
struct Matrix
{
	ll a[N][N];
	Matrix(){ for(int i=0;i<N;i++) for(int j=0;j<N;j++) a[i][j]=-inf;}
	void id(){ Matrix();for(int i=0;i<N;i++) a[i][i]=0;}
	Matrix operator * (Matrix b) const
	{
		Matrix c;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)
				{
					c.a[i][j]=max(c.a[i][j],a[i][k]+b.a[k][j]);
				}
			}
		}
		return c;
	}
	void Print(int sz)
	{
		for(int i=1;i<=sz;i++)
		{
			for(int j=1;j<=sz;j++)
			{
				printf("%lld ",a[i][j]);
			}
			printf("\n");
		}
	}
} f;
Matrix pow(Matrix x, ll k)
{
	Matrix ret;ret.id();
	for(;k;k>>=1,x=x*x) if(k&1) ret=ret*x;
	return ret;
}
int go[N][26],root,tsz,x[N],link[N];
char s[N];
void Set(int &c, int lvl, int sz, int val)
{
	if(!c) c=++tsz;
	if(lvl>=sz){ x[c]+=val;return;}
	Set(go[c][s[lvl]-'a'],lvl+1,sz,val);
}
vector<int> E[N];
void DFS(int u, int sum){ x[u]+=sum;for(int i=0;i<E[u].size();i++) DFS(E[u][i],x[u]);}
void Build()
{
	queue<int> q;
	int i,j;link[1]=1;
	for(i=0;i<26;i++)
	{
		if(go[1][i])
		{
			link[go[1][i]]=1;
			q.push(go[1][i]);
		}
		else go[1][i]=1;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<26;i++)
		{
			if(go[u][i])
			{
				link[go[u][i]]=go[link[u]][i];
				q.push(go[u][i]);
			}
			else go[u][i]=go[link[u]][i];
		}
	}
	for(i=2;i<=tsz;i++) E[link[i]].pb(i);
	DFS(1,0);
	for(i=1;i<=tsz;i++)
	{
		for(j=0;j<26;j++)
		{
			f.a[i][go[i][j]]=x[go[i][j]];
		}
	}
}
int a[N];
int main()
{
	int n,i,j;ll l;
	scanf("%i %lld",&n,&l);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		Set(root,0,strlen(s),a[i]);
	}
	Build();
	f=pow(f,l);
	//f.Print(tsz);
	ll ans=0;
	for(i=1;i<=tsz;i++) ans=max(ans,f.a[1][i]);
	printf("%lld\n",ans);
	return 0;
}