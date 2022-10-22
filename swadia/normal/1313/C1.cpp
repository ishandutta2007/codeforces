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
int n;
LL sum1[MAXN],sum2[MAXN];
int mx[MAXN];
LL ansv;
int pos=0;
int ans[MAXN];

int main()
{
	int lst;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n==1)
	{
		cout<<a[1];
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		lst=a[i];
		sum1[i]+=lst;
		for (int j=i+1;j<=n;j++)
		{
			lst=min(lst,a[j]);
			sum1[i]+=lst;
		}
	}
	for (int i=1;i<=n;i++)
	{
		lst=a[i];
		sum2[i]+=lst;
		for (int j=i-1;j>=1;j--)
		{
			lst=min(lst,a[j]);
			sum2[i]+=lst;
		}
	}
	for (int i=0;i<=n;i++)
		if (sum1[i+1]+sum2[i]>ansv)
		{
			ansv=sum1[i+1]+sum2[i];
			pos=i;
		}
	lst=a[pos+1];
	ans[pos+1]=lst;
	for (int j=pos+2;j<=n;j++)
	{
		lst=min(lst,a[j]);
		ans[j]=lst;
	}
	lst=a[pos];
	ans[pos]=lst;
	for (int j=pos-1;j>=1;j--)
	{
		lst=min(lst,a[j]);
		ans[j]=lst;
		
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return ~~(0^_^0);
}