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
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<string> s;
void init()
{

}

void work()
{
	int n,m;
	cin>>n>>m;
	vector<int> sum;
	sum.resize(m+1,0);
	s.resize(n);
	for (int i=0;i<n;i++)
		cin>>s[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{

			if (i && j &&s[i-1][j]=='X' && s[i][j-1]=='X')
			{
				//cout<<i<<' '<<j<<endl;
				sum[j]++;
			}
		}
	for (int i=1;i<=m;i++)
	{
		sum[i]+=sum[i-1];
		//cout<<i<<' '<<sum[i]<<endl;
	}
	int q,l,r;
	cin>>q;
	//WRT(q)
	while (q--)
	{
		scanf("%d%d",&l,&r);
		if (l==r)
		{
			printf("YES\n");
			continue;
		}
		//cout<<l<<' '<<r<<totum[r]-sum[l-1]>0)
		if (sum[r-1]-sum[l-1]>0)
			printf("NO\n");
		else
			printf("YES\n");
	}

}

int main()
{
	init();
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:\n",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}