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
#define sz(a) a.size()
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
#define int ll
int inv(int val1,int val2){
	int gg=val2-2;
	int ans=1;
	while(gg>0){
		if(gg%2){
			ans*=val1;
			ans%=val2;
		}
		val1*=val1;
		val1%=val2;
		gg/=2;
	}
	return ans;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int val=n;
  	int i;
  	vi vec;
  	for(i=2;i<123456;i++){
  		if(val%i==0)
  			vec.pb(i);
  		while(val%i==0){
  			val/=i;
  		}
  	}
  	//cout<<val<<endl;
  	if(val!=1)
  		vec.pb(val);
  	cerr<<vec.size()<<endl;
  	if(vec.size()==1){
  		cout<<"NO"<<endl;
  		return 0;
  	}
  	cout<<"YES"<<endl;
  	int val1,val2;
  	val1=vec[0];
  	val2=vec[1];
  	int corr1,corr2;
  	corr1=n/val1;
  	corr2=n/val2;
  	int reqd;
  	reqd=n-1;
  	reqd%=val2;
  	reqd*=inv(val1,val2);
  	reqd%=val2;
  	int left;
  	left=n-1-val1*(reqd);
  	left/=val2;
  	vii ans;
  	while(reqd>0){
  		if(reqd<corr1){
  			ans.pb(mp(reqd,corr1));
  			reqd=0;
  		}
  		else{
  			ans.pb(mp(corr1-1,corr1));
  			reqd-=corr1-1;
  		}
  	}

  	reqd=left;
  	corr1=corr2;
  	while(reqd>0){
  		if(reqd<corr1){
  			ans.pb(mp(reqd,corr1));
  			reqd=0;
  		}
  		else{
  			ans.pb(mp(corr1-1,corr1));
  			reqd-=corr1-1;
  		}
  	}
  	cout<<ans.size()<<endl;
  	assert(ans.size()<=100000);
  	rep(i,ans.size()){
  		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
  	}

    return 0;   
}