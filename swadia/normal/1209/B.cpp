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

char s[110];
int n;
int a[MAXN],b[MAXN];

int main()
{
	cin>>n;
	cin>>s;
	RPT(i,0,n)
		cin>>a[i]>>b[i];
	int sum=0;
	RPT(i,0,n)
	{
		s[i]-='0';
		if (s[i])
			sum++;
	}
	int mx=sum;
	RPT(t,1,10000)
	{
		//WRT(t);
		//for (int i=0;i<n;i++)
		//	putchar(s[i]+'0');
		//cout<<endl;
		RPT(i,0,n)
			if (t>=b[i] && (t-b[i])%a[i]==0)
			{
				s[i]^=1;
				if (s[i]==1)
					sum++;
				else
					sum--;
			}
		mx=max(mx,sum);
	}
	cout<<mx;
	return ~~(0^_^0);
}