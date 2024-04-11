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

int pow3[MAXN];
void init()
{
	pow3[0]=1;
	for (int i=1;i<=10;i++)
		pow3[i]=pow3[i-1]*3;
}

void work()
{
	int n;
	cin>>n;
	int a[10];
	int p[10];
	int b[10];
	for (int i=0;i<n;i++)
		cin>>a[i];
	for (int mask=1;mask<pow3[n]-1;mask++)
	{
		for (int i=0;i<n;i++)
		{
			p[i]=(mask/pow3[i]+1)%3-1;
			//cout<<p[i]<<' ';
		}
		//cout<<endl;
		int sum=0;
		for (int i=0;i<n;i++)
			sum+=p[i]*a[i];
		if (sum==0)
		{
			if (sum==0)
			{
				cout<<"YES"<<endl;
				return ;
			}
			
			/*
			int pos=0;
			for (;p[pos]==0;pos++);
			if (p[pos]<0)
				for (int i=0;i<n;i++)
					p[i]=-p[i];
			for (int i=0;i<n;i++)
				if (i!=pos)
				{
					if (p[i]==0)
					{
						b[++cnt]=a[i];
					}
					else
					{
						b[++cnt]=lst+p[i]*a[i];
						lst=b[++cnt];
					}
				}
			for (int i=0;i<n;i++)
				cout<<b[i]<<' ';
			cout<<endl;
			*/
		}
	}
	
				cout<<"NO"<<endl;
				return ;
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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