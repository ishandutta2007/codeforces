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
#define EPS 1e-8

#define _ 0
using namespace std;

typedef pair<int,int> pii;
vector<pii> v(10);
template<typename T>
struct SparseTable
{
	vector<vector<T> > sum;
	vector<int> log2;
	int n,m;
	function<T (T,T)> op;
	SparseTable(function<T (T,T)> _op)
	{

	}

	SparseTable(vector<T> &v,function<T (T,T)> _op)
	{
		Build(v,_op);
	}

	void Build(vector<T> &v,function<T (T,T)> _op)
	{
		op=_op;
		if (v.size()==0)
			return;
		n=v.size();

		log2.resize(n+1);
		log2[0]=log2[1]=0;
		for (int i=2;i<=n;i++)
			log2[i]=log2[i/2]+1;

		m=ceil(log(n)/log(2))+1;
		sum.resize(m);
		for (auto &p:sum)
			p.resize(n);

		sum[0]=v;
		for (int i=1;i<m;i++)
			for (int j=0;j<n;j++)
			{
				if (j+(1<<(i-1))<n)
					sum[i][j]=op(sum[i-1][j],sum[i-1][j+(1<<(i-1))]);
				else
					sum[i][j]=sum[i-1][j];
			}
	}

	T query(int l,int r)
	{
		int i=log2[r-l+1];
		return op(sum[i][l],sum[i][r-(1<<i)+1]);
	}

};
#define ST SparseTable
int n;

void init()
{

}
auto Min=[](pii a,pii b) {return min(a,b);};
auto Max=[](pii a,pii b) {return max(a,b);};
ST<pii> minst(v,Min);
ST<pii> maxst(v,Max);

int calc(int l,int r)
{
	if (r==l)
		return 0;
	if (r-l<=1)
		return 1;
	int m1=minst.query(l,r).second;
	int m2=maxst.query(l,r).second;
	//cout<<l<<' '<<r<<' '<<m1<<' '<<m2<<endl;
	if (m1>m2)
		swap(m1,m2);
	if (m1==l && m2==r)
		return 1;
	if (m1==l)
		return calc(l,m2)+calc(m2,r);
	if (m2==r)
		return calc(l,m1)+calc(m1,r);
	return calc(l,m1)+1+calc(m2,r);
}

void work()
{
	cin>>n;
	v.clear();
	v.resize(n+1);
	for (int i=1;i<=n;i++)
	{
		cin>>v[i].first;
		v[i].second=i;
	}
	minst.Build(v,Min);
	maxst.Build(v,Max);
	cout<<calc(1,n)<<'\n';
}

int main()
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