#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

LL res;
pair<int, int> T[1001];
int A[1001];
bool B[1001];
vector<int> V[1001];

int main()
{
	int n, m;
	cin>> n >>  m;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>> a;
		T[i]=MP(a, i);
		A[i]=a;
	}
	sort(T, T+n);
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>> a >> b;
		a--;
		b--;
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i=n-1; i>=0; i--)
	{
		for(int j=0; j<V[T[i].S].size(); j++) if(!B[V[T[i].S][j]]) res+=A[V[T[i].S][j]];
		B[T[i].S]=1;
	}
	cout<< res << "\n";
	return 0;
}