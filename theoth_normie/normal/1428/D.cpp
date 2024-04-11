
// Problem : Bouncing Boomerangs
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1428/problem/D
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
ll n,m,i,j,u,t,k,v,arr[100001];
vector<ll> lis;
vector<ll> buc[100001];
deque<ll> l,r,r3;
vector<pii(ll)> res;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>arr[i];
	for (i=1;i<=n;i++)
	{
		l.push_back(i);
	}
	for (i=n;i>=1;i--)
	{
		if (arr[i]==1)
		{
			if (l.size())
			{
				res.push_back({l.back(),i});
				buc[l.back()].push_back(i);
				r.push_front(l.back());
				l.pop_back();
			}
			else return cout<<-1,0;
		}
		else if (arr[i]==2)
		{
			
			if (r.size())
			{
				res.push_back({r.front(),i});
				r3.push_back(r.front());
				buc[r.front()].push_back(i);
				r.pop_front();
			}
			else return cout<<-1,0;
		}
		else if (arr[i]==3)
		{
			if ((l.size())and(r3.size()))
			{
				res.push_back({l.back(),i});
				res.push_back({l.back(),buc[r3.front()][1]});
				buc[l.back()].push_back(i);
				buc[l.back()].push_back(i);
				r3.push_back(l.back());
				r3.pop_front();
				l.pop_back();
			}
			else if ((l.size())and(r.size()))
			{
				res.push_back({l.back(),i});
				res.push_back({l.back(),buc[r.front()][0]});
				buc[l.back()].push_back(i);
				buc[l.back()].push_back(i);
				r3.push_back(l.back());
				r.pop_front();
				l.pop_back();
			}
			else return cout<<-1,0;
		}
	}	
	cout<<res.size()<<endl;
	for (pii(ll) pp : res) cout<<pp.fi<<' '<<pp.se<<endl;
}