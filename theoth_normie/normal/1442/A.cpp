
// Problem : Extreme Subtraction
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1442/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
ll n,m,i,j,u,t,t1,k,v,arr[100001],pref[100001],suff[100001];
vector<ll> lis;
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>arr[i];
			pref[i]=0;
			suff[i]=0;
		}
		for (i=1;i<n;i++)
		{
			if (arr[i]<arr[i+1])
			{
				suff[i+1]=arr[i+1]-arr[i];
			}
			else pref[i]=arr[i]-arr[i+1];
		}
		u=0;
		for (i=1;i<=n;i++)
		{
			u+=suff[i];
			arr[i]-=u;
		}
		u=0;
		for (i=n;i>=1;i--)
		{
			u+=pref[i];
			arr[i]-=u;
		}
		if (arr[1]>=0) cout<<"YES"; else cout<<"NO";
		cout<<endl;
	}
}