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

int n, k, x;
LL res, r2;
vector<LL> V, V2;
LL P[2][200002];

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n >> k >> x;
	LL a=1;
	for(int i=0; i<k; i++)
		a*=x;
	for(int i=0; i<n; i++)
	{
		int b;
		cin>> b;
		V.PB(b);
		V2.PB(b*a);
	}
	//sort(V.begin(), V.end());
	//sort(V2.begin(), V2.end());
	//res=(LL)V[V.size()-1]*a;
	for(int i=0; i<(int)V.size(); i++)
	{
		res|=V[i];
		P[0][i]=res;
	}
	res=0;
	for(int i=(int)V.size()-1; i>=0; i--)
	{
		res|=V[i];
		P[1][i]=res;
	}
	for(int i=0; i<(int)V.size(); i++)
	{
		LL tmp;
		if(i==0)
			tmp=V2[i]|P[1][i+1];
		else
			tmp=(P[0][i-1]|V2[i])|P[1][i+1];
		if(tmp>r2)
			r2=tmp;
	}
	cout<< r2 << '\n';
	return 0;
}