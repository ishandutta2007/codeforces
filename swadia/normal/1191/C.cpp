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

#define MAXN 110000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n,m,k;
LL p[MAXN];
int main()
{
	cin>>n>>m>>k;
	RPT(i,0,m)
		cin>>p[i];
	LL st=1;
	LL ed=k;
	LL pos=0;
	LL cnt=0;
	while (pos<m)
	{
		if (p[pos]>ed)
		{
			st=ed+1;
			ed=ed+k;
			if (p[pos]>ed)
			{
				st+=((p[pos]-ed-1)/k+1)*k;
				ed=st+k-1;
			}
		}
		//cout<<st<<' '<<ed<<endl;
		LL* pp=upper_bound(p,p+m,ed);
		//WRT(pp-p);
		ed+=(pp-p)-pos;
		pos=pp-p;
		cnt++;
	}
	cout<<cnt;
	return ~~(0^_^0);
}