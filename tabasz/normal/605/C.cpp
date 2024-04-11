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
#define PLLI pair<PLL, int> 
#define D double

int n;
LL px, py, mx, my;
double rx, ry;
vector<PLL> V;
vector<int> X;
set<PLL> Se;

LL il(PLL x, PLL y, PLL z)
{
	return (x.F-z.F)*(y.S-z.S)-(x.S-z.S)*(y.F-z.F);
}

bool cmp(PLL x, PLL y)
{
	if(il(x, y, V[0])==0)
		return x.F<y.F;
	return il(x, y, V[0])>0;
}

D ilD(pair<D, D> x, pair<D, D> y)
{
	return x.F*y.S-x.S*y.F;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	V.PB(MP(0, 0));
	scanf("%d%lld%lld", &n, &px, &py);
	for(int i=0; i<n; i++)
	{
		LL a, b;
		scanf("%lld%lld", &a, &b);
		if(Se.find(MP(a, b))!=Se.end())
			continue;
		Se.insert(MP(a, b));
		V.PB(MP((LL)a, (LL)b));
		mx=max(mx, a);
		my=max(my, b);
	}
	V.PB(MP((LL)mx, 0));
	V.PB(MP(0, (LL)my));
	sort(V.begin()+1, V.end(), cmp);
	//for(int i=0; i<(int)V.size(); i++)
	//	printf("%lld %lld\n", V[i].F, V[i].S);
	X.PB(0);
	X.PB(1);
	for(int i=2; i<(int)V.size(); i++)
	{
		while(X.size()>2 && il(V[X[X.size()-1]], V[i], V[X[X.size()-2]])<0)
			X.pb();
		X.PB(i);
	}
//	for(int i=0; i<(int)X.size(); i++)
//		printf(" %d\n", X[i]);
	int tmp=1;
	while(tmp<(int)X.size()-1 && il(V[X[tmp+1]], MP(px, py), V[0])>0)
		tmp++;
	//printf("%d\n", tmp);
	if(il(V[X[tmp+1]], MP(px, py), V[0])==0)
	{
		rx=V[X[tmp+1]].F;
		ry=V[X[tmp+1]].S;
	}
	else
	{
		pair<D, D> st=MP((D)V[X[tmp]].F, (D)V[X[tmp]].S), en=MP((D)V[X[tmp+1]].F, (D)V[X[tmp+1]].S);
		pair<D, D> mid=MP((st.F+en.F)/2, (st.S+en.S)/2), to=MP((D)px, (D)py);
		//printf("%lf %lf\n", st.F, st.S);
		//printf("%lf %lf\n", en.F, en.S);
		for(int i=0; i<50; i++)
		{
			//printf("%.9lf %.9lf\n", mid.F, mid.S);
			if(ilD(mid, to)==0)
				break;
			if(ilD(mid, to)>0)
				st=mid;
			else
				en=mid;
			mid=MP((st.F+en.F)/2, (st.S+en.S)/2);	
		}
		rx=mid.F;
		//printf("%lf %lf\n", mid.F, mid.S);
	}
	printf("%.7lf\n", (double)px/rx);
	return 0;
}