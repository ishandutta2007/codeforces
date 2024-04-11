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
int a[MAXN];
int pos[MAXN];
typedef pair<int,int> pii;
int lst[MAXN],nxt[MAXN];
vector<int> g[MAXN];
int diff[MAXN];
LL sum[MAXN];
int wid[MAXN];
void work()
{
	cin>>n;
	set<int> st;
	for (int i=1;i<=n;i++)
	{
		pos[i]=0;
		diff[i]=0;
		sum[i]=0;
		wid[i]=0;
		g[i].clear();
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[a[i]].push_back(i);
	}
	st.insert(0);
	for (int i=1;i<=n;i++)
	{
		vector<pii> v;
		for (auto q:g[i])
		{
			st.insert(q);
			auto p=(--st.find(q));
			lst[i]=*p;
			p=(++st.find(q));
			if (p==st.end())
				nxt[i]=n+1;
			else
				nxt[i]=*p;
			wid[i]=max(wid[i],nxt[i]-lst[i]-1);
				/*
			diff[1]++;
			diff[nxt[i]-q+1]--;
			diff[q-lst[i]+1]--;
			diff[nxt[i]-lst[i]+1]++;
			v.push_back({1,1});
			v.psuh_back({nxt[i]-q+1,-1});
			v.push_back({q-lst[i]+1,-1});
			v.push_back({nxt[i]-lst[i]+1,1});
			if (nxt[i]-lst[i]-1<n+1-i)
			{
				sum[nxt[i]-lst[i]+1]+=10;
				sum[n+1-i+1]-=10;
			}
			if (nxt[i]-lst[i]>n+1-i)
			{
				sum[nxt[i]-lst[i]+1]+=10;
				sum[n+1-i]-=10;
			}
			WRT(lst[i])
			cout<<1<<' '<<nxt[i]-q+1<<' '<<q-lst[i]+1<<' '<<nxt[i]-lst[i]+1<<endl;
			//wid[i]=max(mid[i],nxt[i]-lst[i]-1);
			*/
		}
		//WRT(wid[i])
		//WRT(n+1-i);
		if (wid[i]<n+1-i)
		{
			sum[wid[i]+1]++;
			sum[n+1-i+1]--;
		}
		if (wid[i]>n+1-i)
		{
			sum[n+1-i+1]++;
			sum[wid[i]+1]--;
		}
	}
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i]+sum[i-1];
		if (sum[i])
			putchar('0');
		else
			putchar('1');
	}
	putchar('\n');
	//MRK();
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}