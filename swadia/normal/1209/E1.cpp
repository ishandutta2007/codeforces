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

int a[5][2010];
int n,m;

int tmp[2010];

void Rotate(int x,int v)
{
	RPT(j,0,n)
		if (j+v>=n)
			tmp[j+v-n]=a[j][x];
		else
			tmp[j+v]=a[j][x];
	RPT(j,0,n)
		a[j][x]=tmp[j];
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		//vector<int> v;
		cin>>n>>m;
		RPT(i,0,n)
			RPT(j,0,m)
				cin>>a[i][j];
		int ans=0;
		RPT(k,0,1000)
		{
			RPT(i,0,m)
				Rotate(i,rand()%n);
			int sum=0;
			RPT(i,0,n)
			{
				int mx=-INF;
				RPT(j,0,m)
					mx=max(mx,a[i][j]);
				sum+=mx;
			}
			//WRT(sum);
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}