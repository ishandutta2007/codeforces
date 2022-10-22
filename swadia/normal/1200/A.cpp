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

bool visit[20];
char s[MAXN];
int n;
int main()
{
	cin>>n>>s;
	RPT(i,0,n)
	{
		if (s[i]=='L')
		{
			RPT(j,0,10)
				if (!visit[j])
				{
					visit[j]=1;
					break;
				}
		}
		else if (s[i]=='R')
		{
			DRPT(j,9,-1)
				if (!visit[j])
				{
					visit[j]=1;
					break;
				}
		}
		else visit[s[i]-'0']=0;
	}
	RPT(i,0,10)
		cout<<visit[i];
	return ~~(0^_^0);
}