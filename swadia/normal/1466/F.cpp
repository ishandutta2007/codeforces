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
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;


/*  									*/ 

//Union_Find_Set  
//union_find_set(int set_size=MAXN)		 
//void init(int n) 						 
//void merge(int x,int y) 				 
//bool query(int x,int y) 				 

class Union_Find_Set 
{
	int *pa;
	int n;
	
public:
	int Getpa(int x)
	{
		return pa[x]==x ? x:(pa[x]=Getpa(pa[x]));
	}
	
	int operator[](int x)
	{
		return Getpa(x);
	}
	
	Union_Find_Set(int _size=MAXN)
	{
		n=_size;
		pa=new int[_size+2];
		Init(_size);
	}
	
	~Union_Find_Set()
	{
		delete pa;
	}
	
	void Init(int n)
	{
		for (int i=0;i<=n;i++)
			pa[i]=i;
	}
	
	void Merge(int x,int y)
	{
		pa[Getpa(x)]=Getpa(y);
	}
	
	bool Query(int x,int y)
	{
		return Getpa(x)==Getpa(y);
	}
	
	int Size()
	{
		return n;
	}
};
typedef Union_Find_Set UFS;

/*  									*/ 


typedef pair<int,pair<int,int> > pip;

int n,m;

void work()
{
	vector<pip> v; 
	cin>>m>>n;
	UFS ufs(n+2);
	pip tmp;
	int k,x,y;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&k,&x);
		//WRT(x);
		if (k==2)
		{
			scanf("%d",&y);
			v.push_back({i,{x,y}});
		}
		else
		{
			v.push_back({i,{x,n+1}});
		}
			
	}
	LL t=1;
	vector<int> ans;
	sort(v.begin(),v.end());
	for (auto p:v)
	{
		//cout<<p.second.first<<" - "<<p.second.second<<endl;
		if (!ufs.Query(p.second.first,p.second.second))
		{
			ufs.Merge(p.second.first,p.second.second);
			ans.push_back(p.first);
			t=t*2%MOD;
		}
	}
	printf("%lld %d\n",t,(int)ans.size());
	for (auto p:ans)
		printf("%d ",p);
	putchar('\n');
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
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