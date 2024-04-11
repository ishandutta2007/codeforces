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

LL n,m,q;
LL x1,x2,y1,y2;

LL gcd(LL a,LL b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	cin>>n>>m>>q;
	LL gc=gcd(n,m);
	//MRK();
	while (q--)
	{
		cin>>x1>>y1>>x2>>y2;
		y1--;
		y2--;
		LL t1,t2;
		
		if (x1==1)
			t1=y1/(n/gc);
		else
			t1=y1/(m/gc);
		if (x2==1)
			t2=y2/(n/gc);
		else
			t2=y2/(m/gc);
		//cout<<t1<<' '<<t2<<endl;
		if (t1==t2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return ~~(0^_^0);
}