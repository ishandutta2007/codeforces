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

#define MAXN 61000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int q;
int n,m;
int col[MAXN],row[MAXN];
char c[802000];
int main()
{
	cin>>q;
	while (q--)
	{
		cin>>n>>m;
		RPT(i,0,n)
			RPT(j,0,m)
			{
				cin>>c[i*m+j];
				if (c[i*m+j]=='*')
				{
					row[i]++;
					col[j]++;
				}
			}
		int ans=INF;
		RPT(i,0,n)
			RPT(j,0,m)
				if (c[i*m+j]=='*')
					ans=min(ans,n+m-row[i]-col[j]);
				else
					ans=min(ans,n+m-row[i]-col[j]-1);
		cout<<ans<<endl;
		RPT(i,0,n)
			row[i]=0;
		RPT(j,0,m)
			col[j]=0;
	}
	return ~~(0^_^0);
}