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

#define MAXN 1100000
#define MAXM 1100000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
LL cnt,f,s;
int main()
{
	s=0;
	cnt=0;
	f=0;
	cin>>n;
	RPT(i,0,n)
	{
		cin>>a[i];
		if (a[i]>0)
		{
			cnt+=a[i]-1;
		}
		else if (a[i]<0)
		{
			cnt+=-1-a[i];
			f++;
		}
		else s++;
	}
	//WRT(f);
	if ((f&1)==0 || s>0)
		cout<<cnt+s;
	else
		cout<<cnt+2;
	return ~~(0^_^0);
}