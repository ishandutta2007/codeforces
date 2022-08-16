//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
using namespace std;
using namespace __gnu_pbds;
 
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int visit[102][61234],dp[102][61234];
vii vec1;
int a[112],b[112];
int compute(int pos,int rat){
	if(pos==vec1.size()){
		return 0;
	}
	if(visit[pos][rat])
		return dp[pos][rat];
	visit[pos][rat]=1;
	dp[pos][rat]=compute(pos+1,rat);
	if(rat>=a[vec1[pos].ss] &&  b[vec1[pos].ss]<=rat){
		dp[pos][rat]=max(dp[pos][rat],1+compute(pos+1,rat-b[vec1[pos].ss]));
	}
	return dp[pos][rat];

}
vii vec;
main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,r;
	cin>>n>>r;
	int i;
	rep(i,n){
		cin>>a[i]>>b[i];
		if(b[i]>=0){
			vec.pb(mp(a[i],i));
		}
		else{
			b[i]*=-1;
			vec1.pb(mp(b[i]-a[i],i));
		}
	}
	sort(all(vec));
	sort(all(vec1));
	int cnt=0;
	rep(i,vec.size()){
		if(vec[i].ff<=r){
			r+=b[vec[i].ss];
			cnt++;
		}
	}
	//cout<<vec1[0].ss<<endl;
	cnt+=compute(0,r);
	// if(cnt==n){
	// 	cout<<"YES"<<endl;
	// }
	// else{
	// 	cout<<"NO"<<endl;
	// }
	cout<<cnt<<endl;
}