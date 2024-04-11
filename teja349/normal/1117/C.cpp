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
string s;
int x[3],y[3];
int up[123456],rig[123456];
int check(int steps){
	int n=s.length();
	int lol,haha,val=steps/n;
	lol=x[0]+val*rig[n-1];
	haha=y[0]+val*up[n-1];
	if(steps%n){
		val=steps%n;
		val--;
		lol+=rig[val];
		haha+=up[val];
	}
	if(abs(x[1]-lol)+abs(y[1]-haha)<=steps)
		return 1;
	return 0;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int i;
  	rep(i,2){
  		cin>>x[i]>>y[i];
  	}
  	int n;
  	cin>>n;
  	cin>>s;
  	rep(i,s.length()){
		if(s[i]=='U'){
			up[i]=1;
		}
		else if(s[i]=='D'){
			up[i]=-1;	
		}
		else if(s[i]=='R'){
			rig[i]=1;
		}
		else{
			rig[i]=-1;
		}
		if(i!=0){
			up[i]+=up[i-1];
			rig[i]+=rig[i-1];
		}
  	}
  	int low=0;
  	int high=inf,mid,ans=-1;
  	high*=inf;
  	high/=4;
  	while(low<=high){
  		mid=(low+high)/2;
  		if(check(mid)){
  			ans=mid;
  			high=mid-1;
  		}
  		else{
  			low=mid+1;
  		}
  	}
  	cout<<ans<<endl;
    return 0;   
}