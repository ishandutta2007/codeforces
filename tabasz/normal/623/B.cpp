#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

vector<pair<PII, LL> > P;
vector<int> V;
vector<LL> A[1000005];
int n, a, b, T[1000005], two;
LL res=1e18;

void add(int i, int val)
{
	if(i!=2 || !two)
	{
		P.PB(MP(MP(i, -1), val));
		V.PB(i);
	}
	if(i==2)
		two=1;
}

void fun(int x, int val)
{
	for(int i=2; i*i<=x; i++)
	{
		if(x%i==0)
		{
			add(i, val);
			while(x%i==0)
				x/=i;
		}
	}
	if(x!=1)
		add(x, val);
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d", &n, &a, &b);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	fun(T[1], 0);
	fun(T[1]-1, b);
	fun(T[1]+1, b);
	//for(int i=0; i<(int)P.size(); i++)
	//	printf("%d %d\n", P[i].F, P[i].S);
	sort(V.begin(), V.end());
	for(int i=1; i<=n+1; i++)
		A[i].resize(V.size());
	for(int i=0; i<(int)V.size(); i++)
		for(int j=0; j<(int)P.size(); j++)
			if(P[j].F.F==V[i])
				P[j].F.S=i;
	for(int i=0; i<(int)P.size(); i++)
		A[1][P[i].F.S]=a;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<(int)P.size(); j++)
			A[i][P[j].F.S]=min(A[i][P[j].F.S], (LL)P[j].S);
		for(int j=0; j<(int)V.size(); j++)
			A[i+1][j]=A[i][j]+(LL)a;
		vector<pair<PII, LL> > X;
		for(int j=0; j<(int)P.size(); j++)
		{
			if(T[i+1]%P[j].F.F==0)
				X.PB(P[j]);
			if((T[i+1]-1)%P[j].F.F==0 || (T[i+1]+1)%P[j].F.F==0)
				X.PB(MP(P[j].F, P[j].S+(LL)b));
		}
		P=X;
		//for(int j=0; j<(int)V.size(); j++)
		//	printf("%d %d %lld\n", i, V[j], m[i][V[j]]);
		if(i==n)
			for(int j=0; j<(int)V.size(); j++)
				res=min(res, A[i][j]);
	}
	P.clear();
	two=0;
	for(int j=T[n]-1; j<=T[n]+1; j++)
	{
		int x=j;
		for(int i=2; i*i<=x; i++)
		{
			if(x%i==0)
			{
				if(i!=2 || !two)
				{
					P.PB(MP(MP(i, -1), 0));
					if(j!=T[n])
						P[P.size()-1].S+=b;
				}
				if(i==2)
					two=1;
				while(x%i==0)
					x/=i;
			}
		}
		if(x!=1)
		{
			if(x!=2 || !two)
			{
				P.PB(MP(MP(x, -1), 0));
				if(j!=T[n])
					P[P.size()-1].S+=b;
			}
			if(x==2)
				two=1;
		}
	}
	for(int i=0; i<(int)V.size(); i++)
		for(int j=0; j<(int)P.size(); j++)
			if(P[j].F.F==V[i])
				P[j].F.S=i;
	for(int i=n; i>0; i--)
	{
		for(int j=0; j<(int)P.size(); j++)
		{
			LL x=(LL)(i-1)*a;
			if(i>1 && P[j].F.S!=-1)
				x=min(x, A[i-1][P[j].F.S]);
			res=min(res, x+P[j].S);
		}
		vector<pair<PII, LL> > X;
		if(i==1)
			break;
		for(int j=0; j<(int)P.size(); j++)
		{
			if(T[i-1]%P[j].F.F==0)
				X.PB(P[j]);
			if((T[i-1]-1)%P[j].F.F==0 || (T[i-1]+1)%P[j].F.F==0)
				X.PB(MP(P[j].F, P[j].S+b));
		}
		P=X;
	}
	printf("%lld\n", res);
	return 0;
}