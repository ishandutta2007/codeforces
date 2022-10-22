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

int a[2];
int n;
char s[410000];
int col[410000];

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		cin>>s;
		bool f=false;
		RPT(k,'0','9'+1)
		{
			f=true;
			RPT(i,0,n)
				col[i]=0;
			a[0]=k;
			RPT(i,0,n)
				if (s[i]>=a[0])
				{
					a[0]=s[i];
					col[i]=2;
				}
			a[1]=0;
			RPT(i,0,n)
				if (col[i]==0)
				{
					if (s[i]>=a[1] && s[i]<=k)
					{
						a[1]=s[i];
						col[i]=1;
					}
					else
						f=false;
				}
			if (f)
				break;
		}
		if (!f)
			printf("-");
		else
			RPT(i,0,n)
				printf("%d",col[i]);
		printf("\n");
	}
	return ~~(0^_^0);
}