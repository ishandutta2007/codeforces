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

#define MAXN 100
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n,m;
typedef pair<int,int> pii;
vector<pii> v;
int main()
{
	cin>>n>>m;
	RPT(i,1,n+1)
		RPT(j,1,m+1)
			scanf("%d",&a[i][j]);
	RPT(i,1,n+1)
		RPT(j,1,m+1)
		{
			if (b[i][j]==0 && a[i][j]==1)
			{
				if (i==n || j==m)
				{
					cout<<-1;
					return 0;
				}
				v.push_back({i,j});
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
			}
			else if (b[i][j]==1 && a[i][j]==0)
			{
				cout<<-1;
				return 0;
			}
			else if (i!=n && j!=m && b[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1)
			{
				v.push_back({i,j});
				b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
			}
		}
	cout<<v.size()<<endl;;
	for (auto p:v)
		cout<<p.first<<' '<<p.second<<endl;
	return ~~(0^_^0);
}