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

#define MAXN 201000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

template <class DataType> 
class BinaryIndexTree
{
public:
	vector<DataType> bit;
	
	BinaryIndexTree(int _size=MAXN)
	{
		bit.resize(_size+2);
	}
	
	int lowbit(int x)
	{
		return x&-x;
	}
	
	void add(int x,DataType a)
	{
		for (;x<bit.size();x+=lowbit(x))
			bit[x]+=a;
	}
	
	DataType query(int x)
	{
		DataType ans=0;
		for (;x;x-=lowbit(x))
			ans+=bit[x];
		return ans;
	}
	
	DataType query(int x,int y)
	{
		return query(y)-query(x-1);
	}
};
#define BIT BinaryIndexTree

BIT<LL> bit(MAXN);
int s[MAXN];
int t[MAXN];
int n,m;
LL fac[MAXN];
void init()
{
	fac[0]=1;
	for (int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*i%MOD;
}

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

LL C(int n,int k)
{
	return fac[n]*inv(fac[k])%MOD*inv(fac[n-k])%MOD;
}

int cnt[MAXN];
void work()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		bit.add(s[i],1);
		cnt[s[i]]++;
	}
	LL ans=0;
	LL sum=1;
	int N=n;
	for (int i=1;i<MAXN;i++)
	{
		sum=sum*C(N,cnt[i])%MOD;
		N-=cnt[i];
	}
	WRT(sum)
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&t[i]);
		ans+=1ll*bit.query(t[i]-1)*inv(n-i+1)%MOD*sum%MOD;
		if (cnt[t[i]]==0)
			break;
		sum=sum*inv(C(n-i+1,cnt[t[i]]))%MOD;
		//WRT(sum)
		cnt[t[i]]--;
		bit.add(t[i],-1);
		sum=sum*C(n-i,cnt[t[i]])%MOD;
		//WRT(sum)
		if (i==n && n<m)
		{
			ans++;
			break;
		}
	}
	cout<<ans%MOD<<endl;

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