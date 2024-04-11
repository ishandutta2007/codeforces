
#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 99991  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

string s,t;
int n;

void init()
{
	
}

void work()
{
	cin>>n>>s>>t;
	for (auto &p:s)
		p-='0';
	for (auto &p:t)
		p-='0';
	int bit1=0,bit2=0;
	for (int i=0;i<n;i++)
	{
		bit1+=(s[i]==1 && t[i]==0);
		bit2+=(s[i]==0 && t[i]==1);
	}
	///swap(bit1,bit2);
	//cout<<bit1<<' '<<bit2<<endl;
	int ans=INF;
	if ((bit1+bit2)%2==0 && (bit1==bit2+1 || bit1==bit2))
	{
		ans=min(ans,bit1+bit2);
	}
	if ((n-bit1-bit2)%2==1)
	{
		int tmp=bit1+bit2;
		bit1=0;
		bit2=0;
		for (int i=0;i<n;i++)
		{
			bit1+=(s[i]==1 && t[i]==1);
			bit2+=(s[i]==0 && t[i]==0);
		}
		if ((bit1==bit2+1 || bit1==bit2))
			ans=min(ans,bit1+bit2);
	}
	if (ans==INF)
		ans=-1;
	printf("%d\n", ans);
}

signed main()
{
	init();
	int casenum=1;
	scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}