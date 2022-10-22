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
 
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for (int i=0;i<31;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)
			if (a[j] & (1<<i))
				cnt++;
		if (cnt==1)
			ans|=(1<<i);
	}
	//WRT(ans);
	int t=0;
	int mx=-INF;
	for (int i=1;i<=n;i++)
		if ((ans & a[i])>mx)
		{
			mx=(ans & a[i]);
			t=i;
		}
	cout<<a[t]<<' ';
	for (int i=1;i<=n;i++)
		if (i!=t)
			printf("%d ",a[i]);
	return ~~(0^_^0);
}