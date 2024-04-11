
// Problem : ABBB
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1428/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
ll n,m,i,j,u,t,k,v,arr[100001];
vector<ll> lis;
set<ll> pa,pb;
int main()
{
	cin>>t;
	for (int t1=0;t1<t;t1++)
	{
		string s;
		cin>>s;
		n=s.length();
		pa.clear();
		pb.clear();
		v=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='A') pa.insert(i);
			else pb.insert(i);
		}
		while(true)
		{
			if (pa.size()==0) break;
			else
			{
				auto it=pa.end();
				it--;
				auto it2=pb.lower_bound((*it));
				if (it2==pb.end())
				{
					v++;
				}
				else
				{
					pb.erase(it2);
				}
				pa.erase(it);
			}
		}
			cout<<v+(pb.size()%2)<<endl;
	}
}