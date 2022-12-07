/*
	Normie's Template v2.0
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//Constants.
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;

//---------END-------//
ll n,m,i,j,u,t,t1,k,v;
ll arr[101][101];
vector<vector<ll>> res;
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		res.clear();
		for (i=1;i<=n;i++) for (j=1;j<=m;j++)
		{
		char c;
		cin>>c;
		arr[i][j]=c-48;
		}
		for (i=1;i<n;i++) for (j=1;j<m;j++)
		if (!((i==n-1)and(j==m-1)))
		{
			if (arr[i][j])
			{
				res.push_back({i,j,i+1,j,i,j+1});
				arr[i][j]^=1;
				arr[i+1][j]^=1;
				arr[i][j+1]^=1;
			}
		}
		for (i=1;i<n-1;i++)
		{
			if (arr[i][m])
			{
				if (arr[i][m-1])
				{
				res.push_back({i,m,i,m-1,i+1,m});
				arr[i][m]^=1;
				arr[i][m-1]^=1;
				arr[i+1][m]^=1;
				}
				else
				{
				res.push_back({i,m,i+1,m,i+1,m-1});
				arr[i][m]^=1;
				arr[i+1][m]^=1;
				arr[i+1][m-1]^=1;
				}
			}
			else
			{
				if (arr[i][m-1])
				{
				res.push_back({i,m-1,i+1,m-1,i+1,m});
				arr[i][m-1]^=1;
				arr[i+1][m-1]^=1;
				arr[i+1][m]^=1;
				}
				else
				{
				}
			}
		}
		for (j=1;j<m-1;j++)
		{
			if (arr[n][j])
			{
				if (arr[n-1][j])
				{
				res.push_back({n,j,n-1,j,n,j+1});
				arr[n][j]^=1;
				arr[n-1][j]^=1;
				arr[n][j+1]^=1;
				}
				else
				{
				res.push_back({n,j,n,j+1,n-1,j+1});
				arr[n][j]^=1;
				arr[n][j+1]^=1;
				arr[n-1][j+1]^=1;
				}
			}
			else
			{
				if (arr[n-1][j])
				{
				res.push_back({n-1,j,n-1,j+1,n,j+1});
				arr[n-1][j]^=1;
				arr[n-1][j+1]^=1;
				arr[n][j+1]^=1;
				}
				else
				{
				}
			}
		}
		int cnt=arr[n-1][m-1]+arr[n-1][m]+arr[n][m-1]+arr[n][m];
		if (cnt%2==0)
		{
			if (arr[n-1][m-1]) res.push_back({n-1,m,n,m,n,m-1});
			if (arr[n-1][m]) res.push_back({n-1,m-1,n,m,n,m-1});
			if (arr[n][m-1]) res.push_back({n-1,m,n,m,n-1,m-1});
			if (arr[n][m]) res.push_back({n-1,m,n-1,m-1,n,m-1});
		}
		else
		{
			if (!arr[n-1][m-1]) res.push_back({n-1,m,n,m,n,m-1});
			if (!arr[n-1][m]) res.push_back({n-1,m-1,n,m,n,m-1});
			if (!arr[n][m-1]) res.push_back({n-1,m,n,m,n-1,m-1});
			if (!arr[n][m]) res.push_back({n-1,m,n-1,m-1,n,m-1});
		}
		cout<<res.size()<<endl;
		for (vector<ll> g : res)
		{
			for (ll gg : g) cout<<gg<<' ';
			cout<<endl;
		}
	}
}