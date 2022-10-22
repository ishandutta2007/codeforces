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

#define MAXN 1100000
#define MAXM 1100000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
int main()
{
	cin>>n;
	if (n&1)
	{
		for (int i=0;i<n;i++)
		{
			a[2*i]=2*i+1;
			a[(2*i+n)%(2*n)]=2*i+2;
		}
		cout<<"YES"<<endl;
		RPT(i,0,2*n)
			printf("%d ",a[i]);
	}
	else
		cout<<"NO"<<endl;
	return ~~(0^_^0);
}