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

int b,p,f,h,c;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>b>>p>>f>>h>>c;
		int p1,p2;
		if (f*2>=b)
			p1=b/2*c;
		else
			p1=f*c+min((b-2*f)/2,p)*h;
		if (p*2>=b)
			p2=b/2*h;
		else
			p2=p*h+min((b-2*p)/2,f)*c;
		cout<<max(p1,p2)<<endl;
	}
	
	return ~~(0^_^0);
}