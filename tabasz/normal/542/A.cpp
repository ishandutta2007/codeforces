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
#define int LL
const int M=1024*1024;


struct event
{
	int coo, ind;
	int b;
};

struct prze
{
	int p,  k,  c, ind;
};

int n, m, res;
vector<event> X;
vector<int> V;
int T[400005];
PII A[400005], B[400005];
PII D[2*M], R;
map<int, int> Ma;
vector<prze> Q;

bool cmp(event a, event b)
{
	if(a.coo==b.coo)
	{
		if(b.b==1) return true;
		return !a.b;
	}
	return a.coo<b.coo;
}

bool cmp1(prze a, prze b)
{
	if(a.p==b.p) return a.c<b.c;
	return a.p<b.p;
}

bool cmp2(prze a, prze b)
{
	if(a.k==b.k) return a.c<b.c;
	return a.k>b.k;
}

void add(int v, int w, int x)
{
	v+=M;
	D[v]=max(D[v], MP(w, x));
	while(v>1)
	{
		v/=2;
		D[v]=max(D[2*v], D[2*v+1]);
	}
}

PII maxi(int p, int k)
{
	p+=M;
	k+=M;
	PII r=max(D[p], D[k]);
	while(p/2!=k/2)
	{
		if(p%2==0) r=max(r, D[p+1]);
		if(k%2==1) r=max(r, D[k-1]);
		p/=2;
		k/=2;
	}
	return r;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> m;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>> a >> b;
		V.PB(a);
		V.PB(b);
		A[i]=MP(a, b);
		event x;
		x.coo=b;
		x.ind=a;
		x.b=-(i+1);
		X.PB(x);
		prze qwe;
		qwe.p=a;
		qwe.k=b;
		qwe.c=0;
		qwe.ind=i+1;
		Q.PB(qwe);
	}
	for(int i=1; i<=m; i++)
	{
		int a, b, c;
		cin>> a >> b >> c;
		V.PB(a);
		V.PB(b);
		B[i]=MP(a, b);
		T[i]=c;
		event x;
		x.coo=b;
		x.ind=a;
		x.b=i;
		X.PB(x);
		prze qwe;
		qwe.p=a;
		qwe.k=b;
		qwe.c=c;
		qwe.ind=i;
		Q.PB(qwe);
	}
	sort(Q.begin(), Q.end(), cmp1);
	int asd=0, rty=-1;
	for(int i=0; i<(int)Q.size(); i++)
	{
		if(Q[i].c==0)
		{
			if(asd<Q[i].k)
			{
				asd=Q[i].k;
				rty=Q[i].ind;
			}
		}
		else
		{
			int zxc=(min(Q[i].k, asd)-Q[i].p)*Q[i].c;
			if(zxc>res)
			{
				res=zxc;
				R=MP(rty, Q[i].ind);
			}
			//res=max(res, (min(Q[i].k, asd)-Q[i].p)*Q[i].c);
		}
	}
	sort(Q.begin(), Q.end(), cmp2);
	asd=1000000001;
	rty=-1;
	for(int i=0; i<(int)Q.size(); i++)
	{
		if(Q[i].c==0)
		{
			if(asd>Q[i].p)
			{
				rty=Q[i].ind;
				asd=Q[i].p;
			}
		}
		else
		{
			int zxc=(Q[i].k-max(Q[i].p, asd))*Q[i].c;
			if(res<zxc)
			{
				res=zxc;
				R=MP(rty, Q[i].ind);
			}
			//res=max(res, (Q[i].k-max(Q[i].p, asd))*Q[i].c);
		}
	}
	sort(V.begin(), V.end());
	int prev=-1, tmp=-1;
	for(int i=0; i<(int)V.size(); i++)
	{
		if(V[i]!=prev)
		{
			prev=V[i];
			tmp++;
		}
		Ma[prev]=tmp;
	}
	sort(X.begin(), X.end(), cmp);
	for(int i=0; i<(int)X.size(); i++)
	{
		if(X[i].b<0) add(Ma[X[i].ind], X[i].coo-X[i].ind, -X[i].b);
		else
		{
			int zxc=maxi(Ma[X[i].ind], Ma[X[i].coo]).F*T[X[i].b];
			if(res<zxc)
			{
				res=zxc;
				R=MP(maxi(Ma[X[i].ind], Ma[X[i].coo]).S, X[i].b);
			}
			//res=max(res, maxi(Ma[X[i].ind], Ma[X[i].coo])*T[X[i].b]);
		}
	}
	
	cout<< res << '\n';
	if(res>0) cout<< R.F << ' ' << R.S << '\n';
	return 0;
}