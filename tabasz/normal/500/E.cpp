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
#define PII pair<int, int>
const int M=262144;

struct querry
{
	int p, k, i;
};

int n, m;
vector<PII> V, W;
int R[200005], T[200005], A[200005], D[2*M];
vector<querry> Q;

bool cmp(querry a, querry b)
{
	return a.p>b.p;
}

int find(int a)
{
	if(T[a]==a) return a;
	return T[a]=find(T[a]);
}

void onion(int a, int b)
{
	a=find(a);
	b=find(b);
	T[b]=a;
}

void addtree(int v, int w)
{
	v+=M;
	D[v]=w;
	while(v>1)
	{
		v/=2;
		D[v]=D[2*v]+D[2*v+1];
	}
}

void add(int x)
{
	while(!W.empty() && W[W.size()-1].S<=V[x].S)
	{
		onion(x, W[W.size()-1].F);
		addtree(W.size()-1, 0);
		W.pop_back();
	}
	int l=0;
	W.PB(MP(x, V[x].S));
	if(W.size()>1)
	{
		int pp=V[W[W.size()-2].F].F, kk=V[x].S;
		l=max(l, pp-kk);
	}
	addtree(W.size()-1, l);
	A[x]=W.size()-1;
}

int sum(int p, int k)
{
	if(k<p) return 0;
	p+=M;
	k+=M;
	int re=D[p];
	if(p!=k) re+=D[k];
	while(p/2!=k/2)
	{
		if(p%2==0) re+=D[p+1];
		if(k%2==1) re+=D[k-1];
		p/=2;
		k/=2;
	}
	return re;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		T[i]=i;
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(MP(a, a+b));
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		querry q;
		scanf("%d%d", &q.p, &q.k);
		q.p--;
		q.k--;
		q.i=i;
		Q.PB(q);
	}
	sort(Q.begin(), Q.end(), cmp);
	int tmp=n-1;
	for(int i=0; i<m; i++)
	{
		while(tmp>=Q[i].p)
		{
			add(tmp);
			tmp--;
		}
		int kk=find(Q[i].k);
		R[Q[i].i]=sum(A[kk]+1, M-1);
	}
	for(int i=0; i<m; i++) printf("%d\n", R[i]);
	return 0;
}