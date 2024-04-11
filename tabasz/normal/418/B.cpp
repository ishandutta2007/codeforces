#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double
const LL inf=3000000000000000000LL;

struct cos
{
	int mask;
	LL c, m;
};

int P[25];
LL dp[1024*1024+10];
vector<cos> V;

bool cmp(cos a, cos b)
{
	return a.m<b.m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	P[0]=1;
	for(int i=1; i<=21; i++) P[i]=P[i-1]*2;
	int n, m;
	LL b;
	cin>> n >> m >> b;
	for(int i=0; i<n; i++)
	{
		cos x;
		int a, mask=0;
		cin>> x.c >> x.m >> a;
		for(int j=0; j<a; j++)
		{
			int b;
			cin>> b;
			mask+=P[b-1];
		}
		x.mask=mask;
		V.PB(x);
	}
	sort(V.begin(), V.end(), cmp);
	for(int i=1; i<P[m]; i++) dp[i]=inf;
	LL res=inf;
	for(int i=0; i<V.size(); i++)
	{
		if(i!=0 && V[i].m!=V[i-1].m) res=min(res, dp[P[m]-1]+V[i-1].m*b);
		for(int j=1; j<P[m]; j++)
		{
			int x=j|V[i].mask;
			dp[j]=min(dp[j], dp[x-V[i].mask]+V[i].c);
		}
	}
	res=min(res, dp[P[m]-1]+V[V.size()-1].m*b);
	if(res<inf) cout<< res << "\n";
	else cout<< "-1\n";
	return 0;
}