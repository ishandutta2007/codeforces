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

LL n,m;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		LL p=n-m;
		if (m==0)
		{
			cout<<0<<endl;
			continue;
		}
		LL x1=p/(m+1);
		LL x2=p-x1*(m+1);
		LL x3=(m+1)-x2;
		LL ans=(LL)n*(n+1)/2;
		ans=ans-x2*((LL)(x1+1)*(x1+2)/2)-x3*((LL)x1*(x1+1)/2);
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}