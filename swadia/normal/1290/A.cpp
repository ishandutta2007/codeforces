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

int t,n,m,k;
int a[MAXN];
int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>k;
		for (int i=0;i<n;i++)
			cin>>a[i];
		if (k>=m-1)
			k=m-1;
		int f=m-1-k;
		int ans=-INF;
		for (int i=0;i<=k;i++)
		{
			int l=i,r=n-1-k+i;
			//cout<<l<<'-'<<r<<endl;
			int mi=INF;
			for (int j=0;j<=f;j++)
			{
				mi=min(mi,max(a[l+j],a[r-f+j]));
				//cout<<a[l+j]<<' '<<a[r-f+j]<<'!'<<endl;
			}
			ans=max(ans,mi);
		}
		cout<<ans<<endl;
		continue;
	}
	return ~~(0^_^0);
}