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


int n,m,q;
int cnt[MAXN];
int sum;
void init()
{

}

void work()
{
	int op,x,y;
	cin>>n>>m;
	sum=n;
	while (m--)
	{
		scanf("%d%d",&x,&y);
		if (x>y)
			swap(x,y);
		if (cnt[x]==0)
			sum--;
		cnt[x]++;
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&op);
		if (op==3)
		{
			printf("%d\n",sum);
			continue;
		}
		scanf("%d%d",&x,&y);
		if (x>y)
			swap(x,y);
		if (op==1)
		{
			if (cnt[x]==0)
				sum--;
			cnt[x]++;
		}
		else
		{
			cnt[x]--;
			if (cnt[x]==0)
				sum++;
			
		}
	}
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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