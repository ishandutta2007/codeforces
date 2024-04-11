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

#define MAXN 1001000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a[MAXN];
LL diff[MAXN];
int n;
LL st[MAXN][20];

LL gcd(LL x,LL y)
{
	if (x<y)
		swap(x,y); 
	if (y==0)
		return x;
	return gcd(y,x%y);
}

LL Log2[MAXN];
void init()
{
	Log2[1]=0;
	for (int i=2;i<MAXN;i++)
		Log2[i]=Log2[i/2]+1;
}

LL query(LL x,LL y)
{
	if (y==n)
		return 1;
	LL t=Log2[y-x+1];
	return gcd(st[x][t],st[y-(1<<t)+1][t]); 
}

void work()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if (n==1)
	{
		cout<<1<<'\n';
		return;
	}
	for (int i=1;i<n;i++)
	{
		diff[i]=a[i+1]-a[i];
		if (diff[i]<0)
			diff[i]=-diff[i];
		st[i][0]=diff[i];
	}
	for (int k=0;k<18;k++)
		for (int i=1;i<n;i++) 
			st[i][k+1]=gcd(st[i][k],st[i+(1<<k)][k]);
	//MRK();
	int ans=0;
	for (int i=1;i<n;i++)
	{
		int l=i,r=n;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (query(i,mid)>1)
				l=mid+1;
			else
				r=mid;
		}
		//WRT(l);
		//WRT(i);
		ans=max(ans,l-i+1);
	}
	cout<<ans<<'\n';
	for (int i=1;i<n;i++)
		for (int k=0;k<=19;k++)
			st[i][k]=0;
			
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