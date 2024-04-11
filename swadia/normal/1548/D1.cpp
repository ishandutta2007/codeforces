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

LL buc[2][2];
int n,x,y;
void init()
{

}

void work()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		x/=2,y/=2;
		buc[x&1][y&1]++;
	}
	LL ans=0;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		{
			LL C=0;
			if (buc[i][j]>=3)
				ans+=buc[i][j]*(buc[i][j]-1)*(buc[i][j]-2)/6;
			if (buc[i][j]>=2)
				C=buc[i][j]*(buc[i][j]-1)/2;
			for (int ii=0;ii<2;ii++)
				for (int jj=0;jj<2;jj++)
					if (i!=ii || j!=jj)
						ans+=C*buc[ii][jj];
			
		}
	cout<<ans<<endl;
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