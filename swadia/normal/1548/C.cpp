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

#define MAXN 3010000
#define MAXM 2010000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL mpow(LL x,LL n)
{
	LL ans=1;
	while (n)
	{
		if (n&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return ans;
} 



LL inv(LL x)
{
	return mpow(x,MOD-2);
}
LL fac[MAXN+3];
LL invfac[MAXN+3];
void fac_init(int n=MAXN)
{
	n--;
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	invfac[n]=inv(fac[n]);
	for (int i=n;i;i--)
		invfac[i-1]=invfac[i]*i%MOD;
}


LL getC(int n,int x)
{
	if (x>n)
		return 0;
	return fac[n]*invfac[x]%MOD*invfac[n-x]%MOD;
}

LL f[MAXN][3];
LL n,q;
void init()
{
	fac_init();
	cin>>n>>q;
	for (int j=0;j<3;j++)
	{
		for (int i=1;i<=n;i++)
			f[3*n][j]+=getC(3*i+j,3*n);
		f[3*n][j]%=MOD;
		WRT(f[3*n][j])
	}
	for (int i=3*n-1;i>=0;i--)
	{
		f[i][0]=((-f[i+1][0]+f[i+1][1])%MOD+MOD)%MOD;
		f[i][1]=((-f[i+1][1]+f[i+1][2])%MOD+MOD)%MOD;
		f[i][2]=((-f[i+1][2]+f[i+1][0]+getC(3*n+3,i+1)-getC(3,i+1))%MOD+MOD)%MOD;
	}
}
int x;
void work()
{
	scanf("%d",&x);
	printf("%lld\n",f[x][0]);
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	init();
	int casenum=q;
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