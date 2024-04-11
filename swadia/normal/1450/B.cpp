#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,k;
int x[MAXN],y[MAXN];

void work()
{
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	bool f=false;
	for (int i=0;i<n;i++)
	{
		bool f=true;
		for (int j=0;j<n;j++)
			if (abs(x[i]-x[j])+abs(y[i]-y[j])>k)
			{
				f=false;
				break;
			}
		if (f)
		{
			cout<<1<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}