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

int n;

int query(int x)
{
	if (n-x==0)
		return 0;
	cout<<"? ";
	for (int i=1;i<n;i++)
		cout<<n<<' ';
	cout<<n-x<<endl;
	cin>>x;
	return x;
}

int query2(int x)
{
	cout<<"? ";
	for (int i=1;i<n;i++)
		cout<<1<<' ';
	cout<<1+x<<endl;
	cin>>x;
	return x;
}

void init()
{

}

int a[MAXN];
void work()
{
	cin>>n;
	int lst=0;
	for (lst=1;;lst++)
	{
		int fxxk=query(lst);
		if (fxxk==0)
			break;
		a[fxxk]=-lst;
	}
	a[n]=lst;
	for (int i=1;i<n;i++)
	{
		if (a[i])
			a[i]+=lst;
	}
	for (int i=1;i<=n-lst;i++)
	{
		int fxxk=query2(i);
		a[fxxk]=lst+i;
	}
	cout<<"! ";
	for (int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
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