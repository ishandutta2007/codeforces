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
int gg=1,ff=3;
int cnt=0;
int solve();
int ask(int a,int b){
	cout<<"? "<<a<<" "<<b<<endl;
	fflush(stdout);
	int val;
	// a^=gg;
	// b^=ff;
	// cnt++;
	// if(a<b){
	// 	return -1;
	// }
	// else if(a>b){
	// 	return 1;
	// }
	// else{
	// 	return 0;
	// }
	cin>>val;
	return val;
}
int reporter(int a,int b){
	cout<<"! "<<a<<" "<<b<<endl;
	assert(cnt<=62);
	// if(a==gg && b==ff){

	// }
	// else{
	// 	cout<<gg<<" "<<ff<<"  "<<a<<"  "<<b<<endl;
	// 	exit(0);
	// }
	//cerr<<"count "<<cnt<<endl;
	//solve();
	exit(0);
}
int retreive(int pos,int a,int b){
	int i,ans,val;
	fd(i,pos,0){
		val=(1<<i);
		ans=ask(a+val,b);
		if(ans==-1){
			b+=val;
			a+=val;
		}	
	}
	reporter(a,b);
	return 0;
}

int iter=0;
int solve(){
	iter++;
	int N=30;
	if(iter==10000)
		return 0;
	gg=rng()%(1<<N);
	ff=rng()%(1<<N);
	gg+=(1<<N);
	ff+=(1<<N);
	gg%=(1<<N);
	ff%=(1<<N);
	//gg=2;
	//ff=3;
    //std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int a=0;
  	int b=0;
  	cnt=0;
  	int sofar,rem,ans,ans1,val,i;
  	sofar=0;
  	ans=ask(a,b);
  	if(ans==0){
  		retreive(29,a,b);
  		return 0;
  	}
  	val=(1<<29);
  	ans1=ask(a+val,b+val);
  	rem=ans1;
  	sofar=0;
  	if(ans!=ans1){
  		if(ans==-1){
  			b+=val;
  		}
  		else{
  			a+=val;
  		}
  		sofar=0;
  		rem=ask(a,b);
  	}
  	else{
  		ans=ask(a+val,b);
  		if(ans==-1){
  			b+=val;
  			a+=val;
  		}
  	}
  	ans=rem;
  	fd(i,28,0){
  		val=(1<<i);
  		if(sofar==1)
  			ans1=ask(a,b);
  		else
  			ans1=ask(a+val,b+val);

  		rem=ans1;
  		
  		if(sofar==1)
  			swap(ans,ans1);
  		sofar=0;
  		if(rem==0){
  			retreive(i,a,b);
  		}
  		if(ans!=ans1){
	  		if(ans==-1){
	  			b+=val;
	  		}
	  		else{
	  			a+=val;
	  		}
	  		sofar=0;
  			rem=ask(a,b);
	  	}
	  	else{
	  		ans=ask(a+val,b);
	  		// if(i==2){
  			// 	cout<<ans<<" "<<ans1<<endl;
  			// }
	  		if(ans==-1){
	  			a+=val;
	  			b+=val;
	  		}
	  		
	  	}
	  	ans=rem;
  	}
  	reporter(a,b);

    return 0;   
}

int main(){
	solve();
}