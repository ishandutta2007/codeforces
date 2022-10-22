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

#define MAXN 1010
#define MAXM 510000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int re[MAXN][MAXN];
int a[MAXM];
int q;
int main()
{
	int op,x,y;
	cin>>q;
	while (q--)
	{
		scanf("%d%d%d",&op,&x,&y);
		if (op==1)
		{
			for (int i=1;i<=800;i++)
				re[i][x%i]+=y;
			a[x]+=y;
		}
		else
		{
			if (x<=800)
				cout<<re[x][y]<<endl;
			else
			{
				int ans=0;
				for (int i=y;i<=500000;i+=x)
					ans+=a[i];
				cout<<ans<<endl;
			}
		}
	}
	return ~~(0^_^0);
}