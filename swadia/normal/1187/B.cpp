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

#define MAXN 201000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN],str[MAXN];
int num[30][MAXN];
int nu[30];
int cnt[30];
int main()
{
	int n,m;
	cin>>n;
	cin>>str;
	RPT(i,0,30)
		cnt[i]=1;
	RPT(i,0,n)
		num[str[i]-'a'][cnt[str[i]-'a']++]=i+1;
	cin>>m;
	while (m--)
	{
		cin>>s;
		int len=strlen(s);
		MST(nu,0);
		RPT(i,0,len)
			nu[s[i]-'a']++;
		int ans=0;
		RPT(i,0,26)
		{
			ans=max(ans,num[i][nu[i]]);
		}
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}