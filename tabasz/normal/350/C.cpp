#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back

struct qwe
{
	int b;
	char c;
};

vector<pair<int, qwe> > W;
vector<pair<int, int> > V[2], U[2];
qwe X;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.S>b.S;
}

bool cmp1(pair<int, int> a, pair<int, int> b)
{
	if(a.S>b.S) return true;
	if(a.S<b.S) return false;
	return a.F<b.F;
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
	if(a.S>b.S) return true;
	if(a.S<b.S) return false;
	return a.F>b.F;
}

void add(int a, int b)
{
	qwe R, U, L, D;
	R.b=abs(a);
	L.b=abs(a);
	U.b=abs(b);
	D.b=abs(b);
	R.c='R';
	L.c='L';
	U.c='U';
	D.c='D';
	if(b<0) W.PB(MP(1, D));
	if(b>0) W.PB(MP(1, U));
	/////////////
	if(a<0) W.PB(MP(1, L));
	if(a>0) W.PB(MP(1, R));
	W.PB(MP(2, X));
	if(a<0) W.PB(MP(1, R));
	if(a>0) W.PB(MP(1, L));
	/////////////////
	if(b<0) W.PB(MP(1, U));
	if(b>0) W.PB(MP(1, D));
	W.PB(MP(3, X));
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==0)
		{
			if(b>0) V[0].PB(MP(a, b));
			else V[1].PB(MP(a, b));
		}
		if(a>0) U[0].PB(MP(a, b));
		if(a<0) U[1].PB(MP(a, b));
	}
	sort(V[0].begin(), V[0].end());
	sort(V[1].begin(), V[1].end(), cmp);
	sort(U[0].begin(), U[0].end(), cmp1);
	sort(U[1].begin(), U[1].end(), cmp2);
	for(int i=0; i<V[0].size(); i++) add(V[0][i].F, V[0][i].S);
	for(int i=0; i<V[1].size(); i++) add(V[1][i].F, V[1][i].S);
	for(int i=0; i<U[0].size(); i++) add(U[0][i].F, U[0][i].S);
	for(int i=0; i<U[1].size(); i++) add(U[1][i].F, U[1][i].S);
	printf("%d\n", W.size());
	for(int i=0; i<W.size(); i++)
	{
		printf("%d ", W[i].F);
		if(W[i].F==1)
		{
			printf("%d %c", W[i].S.b, W[i].S.c);
		}
		printf("\n");
	}
	return 0;
}