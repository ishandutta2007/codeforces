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

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

typedef pair<int,int> pii;
pii d[MAXN];
int s[2*MAXN];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&d[i].first);
		d[i].second=i;
	}
	sort(d+1,d+n+1,greater<pii>());
	for (int i=1;i<=n;i++)
	{
		//cout<<d[i].first<<' '<<d[i].second<<endl;
		if (i!=n)
			cout<<2*d[i].second<<' '<<2*d[i+1].second<<endl;
		s[i]=2*d[i].second;
	}
	//MRK();
	int cnt=n;
	for (int i=1;i<=n;i++)
		if (cnt-i==d[i].first-1)
		{
			cnt++;
			s[cnt]=2*d[i].second-1;
			cout<<s[cnt-1]<<' '<<s[cnt]<<endl;
		}
		else
		{
			cout<<2*d[i].second-1<<' '<<s[i+d[i].first-1]<<endl;
		}
	return ~~(0^_^0);
}