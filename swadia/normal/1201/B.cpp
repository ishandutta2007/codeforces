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

#define MAXN 201000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN];
int n;
LL sum=0;
int mx=-INF;

int main()
{
	cin>>n;
	RPT(i,0,n)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if (sum&1)
	{
		cout<<"NO";
		return 0;
	}
	if (mx*2>sum)
	{
		cout<<"NO";
		return 0;
	}
	
	cout<<"YES";
	return ~~(0^_^0);
}