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

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN],b[MAXN];
int n,m;
int mp[MAXN];
int main()
{
	cin>>n;
	RPT(i,0,n)
	{
		cin>>a[i];
		mp[a[i]]=1;
	}
	cin>>m;
	RPT(i,0,m)
	{
		cin>>b[i];
		mp[b[i]]=1;
	}
	RPT(i,0,n)
		RPT(j,0,m)
			if (mp[a[i]+b[j]]==0)
			{
				cout<<a[i]<<' '<<b[j];
				return 0;
			}
	return ~~(0^_^0);
}