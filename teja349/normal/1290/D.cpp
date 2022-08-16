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

vi vec;
int n,k;
int arr[12345];
int ask(int i){
	i++;
	cout<<"? "<<i<<endl;
	string s;
	cin>>s;
	if(s[0]=='Y')
		return 1;
	return 0;
}
int clearque(){
	cout<<"R"<<endl;
}
int printans(int ans){
	cout<<"! "<<ans<<endl;
	return 0;
}
int solveall(int n){
	int i,j,val;
	rep(i,n){
		rep(j,i){
			ask(j);
			val=ask(i);
			clearque();
			if(val==1){
				arr[i]=0;
			}
		}
	}
	int sumi=0;
	rep(i,n){
		sumi+=arr[i];
	}
	printans(sumi);
	return 0;
}
int solve(){
	int i;
	vi vec1;
	int j,val;
	vec1.clear();
	rep(i,vec.size()){
		rep(j,k){
			vec1.pb(vec[i]*k+j);
		}
	}
	ask(vec1[0]);
	f(i,1,vec1.size()){
		val=ask(vec1[i]);
		if(val==1){
			arr[vec1[i]]=0;
		}
	}
	clearque();
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n>>k;
    int i;
    rep(i,n){
    	arr[i]=1;
    }
    if(k==1){
    	solveall(n);
    	return 0;
    }
    int diff,val,j;
    k/=2;
    f(diff,1,n/k+10){	
    	rep(i,diff){
    		vec.clear();
    		val=i;
    		//vec.pb(val);
    		while(val<n/k){
    			vec.pb(val);
    			val+=diff;
    		}
    		if(vec.size()>1)
    			solve();
    	}
    }
    int sumi=0;
    rep(i,n){
		sumi+=arr[i];
	}
	printans(sumi);
	return 0;

    return 0;   
}