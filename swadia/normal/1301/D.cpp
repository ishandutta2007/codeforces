#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,m,k;
typedef pair<int,char> pic;
vector<pic> v;

void output()
{
	printf("%d\n",v.size());
	for (auto p:v)
		printf("%d %c\n",p.first,p.second);
	exit(0);
}

void ty(int x,char c)
{
	if (x==0)
		return;
	if (k<=x)
	{
		v.push_back({k,c});
		output();
	}
	else
	{
		v.push_back({x,c});
		k-=x;
	}
}

int main()
{
	cin>>n>>m>>k;
	if (k>4*n*m-2*n-2*m)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	ty(m-1,'R');
	ty(n-1,'D');
	for (int i=0;i<n-1;i++)
	{
		ty(m-1,'L');
		ty(m-1,'R');
		ty(1,'U');
	}
	for (int i=0;i<m-1;i++)
	{
		ty(1,'L');
		ty(n-1,'D');
		ty(n-1,'U');
	}
	output();
	return ~~(0^_^0);
}