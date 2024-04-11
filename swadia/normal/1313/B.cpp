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

LL n,x,y;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>x>>y;
		int ans1=2*n-x-y;
		int t1=max(min(y-1,(n-x)-1),(LL)0);
		int t2=max(min(x-1,(n-y)-1),(LL)0);
		ans1=max(y-1-t1,x-1-t2)+1;
		int ans2;
		if (x+y>=1+n)
			ans2=n;
		else
			ans2=x+y-1;
		cout<<ans1<<' '<<ans2<<endl;
	}
	return ~~(0^_^0);
}