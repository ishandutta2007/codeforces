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

#define MAXN 101000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a[MAXN];
LL n;
int main()
{
	cin>>n;
	RPT(i,0,n)
		scanf("%d",&a[i]);
	if (n==1)
	{
		if (a[0]%2==1)
			cout<<"sjfnb";
		else
			cout<<"cslnb";
		return 0;
	}
	sort(a,a+n);
	if (a[0]==0 && a[1]==0)
	{
		cout<<"cslnb";
		return 0;
	}
	int cnt=0;
	RPT(i,0,n-1)
		if (a[i]==a[i+1])
		{
			cnt++;
			if (i!=0)
			{
				if (a[i]-1==a[i-1])
				{
					cout<<"cslnb";
					return 0;
				}
			}
			if (cnt>=2)
			{
				cout<<"cslnb";
				return 0;
			}
		}
	LL sum=0;
	RPT(i,0,n)
	{
		sum+=a[i];
		sum-=i;
	}
	if (sum%2==1)
		cout<<"sjfnb";
	else
		cout<<"cslnb";
		
	return ~~(0^_^0);
}