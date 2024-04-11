#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 210000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int pa[MAXN];

int n,m;

int getpa(int x)
{
	return pa[x]==x ? x:pa[x]=getpa(pa[x]);
}

bool query(int x,int y)
{
	return getpa(x)==getpa(y);
}

void merge(int x,int y)
{
	pa[getpa(x)]=getpa(y);
}

int main()
{
	cin>>n>>m;
	RPT(i,1,n+1)
		pa[i]=i;
	int x,y;
	int cnt=0;
	RPT(i,0,m)
	{
		cin>>x>>y;
		if (query(x,y))
			cnt++;
		else
			merge(x,y);
	}
	cout<<cnt;
	return ~~(0^_^0);
}