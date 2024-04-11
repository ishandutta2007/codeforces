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

char s[MAXN];
int num[MAXN];
int n,m;
int buc[MAXN][5];
int main()
{
	cin>>n>>m;
		//MST(buc,0);
	RPT(i,0,n)
	{
		cin>>s;
		RPT(j,0,m)
			buc[j][s[j]-'A']++;
	}
	RPT(i,0,m)
	{
		num[i]=max(max(max(buc[i][0],buc[i][1]),max(buc[i][2],buc[i][3])),buc[i][4]);
		//WRT(num[i]);
	}
	LL sum=0;
	int x;
	RPT(i,0,m)
	{
		cin>>x;
		sum+=x*num[i];
	}
	cout<<sum;
	return ~~(0^_^0);
}