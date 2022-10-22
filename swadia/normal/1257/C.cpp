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

int a[MAXN];
int lst[MAXN];
int n;

int main()
{
	int t;
	cin>>t;
	for (int i=0;i<MAXN;i++)
		lst[i]=-INF;
	while (t--)
	{
		int ans=INF;
		cin>>n;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			ans=min(ans,i-lst[a[i]]+1);
			lst[a[i]]=i;
		}
		if (ans==INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
		for (int i=0;i<n;i++)
			lst[a[i]]=-INF;
		
	}
	return ~~(0^_^0);
}