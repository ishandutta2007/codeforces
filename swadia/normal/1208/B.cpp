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

int x[MAXN];
int n;
int main()
{
	cin>>n;
	RPT(i,1,n+1)
		cin>>x[i];
	int ans=INF;
	RPT(i,1,n+1)
	{
		map<int,int> mp;
		bool f=true;
		RPT(j,1,i)
		{
			if (mp[x[j]])
			{
				f=false;
				break;
			}
			mp[x[j]]++;
		}
		if (!f)
			continue;
		int j=n;
		for (;j>=i;j--)
		{
			
			if (mp[x[j]])
				break;
			mp[x[j]]++;
		}
		ans=min(ans,j-i+1);
	}
	cout<<ans;
	return ~~(0^_^0);
}