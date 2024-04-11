#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const int M=1024*512;

struct vec
{
	int a, b, c, d, ind;
};

int n, w, perv;
vector<vec> T;
set<PII > D[2*M];
queue<int> Q;
int vis[M];
vector<int> R;
vector<int> V;
map<int, int> S;

void add(int ind, int v)
{
	v+=M;
	while(v>=1)
	{
		D[v].insert(MP(T[ind].b, ind));
		v/=2;
	}
}

void remove(int v)
{
	set<PII >::iterator it=D[v].begin();
	while(it!=D[v].end() && it->F<=w)
	{
		if(vis[it->S]==-1)
		{
			vis[it->S]=perv;
			Q.push(it->S);
		}
		D[v].erase(it);
		it=D[v].begin();
	}
}

void querry(int v, int vp, int vk, int p, int k)
{
	if(vp>k || vk<p)
		return;
	if(vp>=p && vk<=k)
	{
		remove(v);
		return;
	}
	int mid=(vp+vk)/2;
	querry(2*v, vp, mid, p, k);
	querry(2*v+1, mid+1, vk, p, k);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		vis[i]=-1;
	vec x;
	T.PB(x);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d%d%d", &x.a, &x.b, &x.c, &x.d);
		V.PB(x.a);
		V.PB(x.b);
		V.PB(x.c);
		V.PB(x.d);
		x.ind=i;
		T.PB(x);
		if(x.a==0 && x.b==0)
		{
			vis[i]=0;
			Q.push(i);
		}
	}
	sort(V.begin(), V.end());
	int tmp=-1, pr=-1;
	for(int i=0; i<(int)V.size(); i++)
	{
		if(V[i]!=pr)
		{
			tmp++;
			pr=V[i];
			S[pr]=tmp;
		}
	}
	for(int i=1; i<=n; i++)
	{
		T[i].a=S[T[i].a];
		T[i].b=S[T[i].b];
		T[i].c=S[T[i].c];
		T[i].d=S[T[i].d];
	}
	for(int i=1; i<=n; i++)
		if(vis[T[i].ind]==-1)
			add(T[i].ind, T[i].a);
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		w=T[v].d;
		perv=v;
		querry(1, 0, M-1, 0, T[v].c);
	}
	if(vis[n]==-1)
		printf("-1\n");
	else
	{
		int v=n;
		while(v!=0)
		{
			R.PB(v);
			v=vis[v];
		}
		printf("%d\n", (int)R.size());
		for(int i=(int)R.size()-1; i>=0; i--)
			printf("%d ", R[i]);
		printf("\n");
	}
	return 0;
}