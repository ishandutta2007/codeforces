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

LL x[MAXN],y[MAXN]; 
LL ax[MAXN],ay[MAXN];
int main()
{
	int n;
	cin>>n;
	if (n&1)
	{
		cout<<"No";
		return 0;
	}
	for (int i=0;i<n;i++)
		scanf("%lld%lld",&ax[i],&ay[i]);
	int ansx,ansy;
	ansx=ax[0]+ax[n/2];
	ansy=ay[0]+ay[n/2]; 
	for (int i=0;i<n/2;i++)
		if (ax[i]+ax[i+n/2]!=ansx || ay[i]+ay[i+n/2]!=ansy)
		{
			cout<<"No"; 
			return 0;
		} 
	cout<<"Yes";
	return ~~(0^_^0);
}