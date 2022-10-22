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

char s[10][10];
int cnt[10];
int main()
{
	cin>>s[1]>>s[2]>>s[3];
	RPT(i,1,4)
		if (s[i][1]=='m')
			cnt[i]=s[i][0]-'0'+0;
		else if (s[i][1]=='p')
			cnt[i]=s[i][0]-'0'+20;
		else if (s[i][1]=='s')
			cnt[i]=s[i][0]-'0'+40;
	sort(cnt+1,cnt+4);
	if (cnt[1]==cnt[2] && cnt[2]==cnt[3])
	{
		cout<<0;
		return 0;
	}
	if (cnt[1]==cnt[2]-1 && cnt[2]==cnt[3]-1)
	{
		cout<<0;
		return 0;
	}
	if (cnt[1]==cnt[2] || cnt[2]==cnt[3])
	{
		cout<<1;
		return 0;
	}
	if (cnt[1]==cnt[2]-1 || cnt[2]==cnt[3]-1)
	{
		cout<<1;
		return 0;
	}
	if (cnt[1]==cnt[2]-2 || cnt[2]==cnt[3]-2)
	{
		cout<<1;
		return 0;
	}
	cout<<2;
	return ~~(0^_^0);
}