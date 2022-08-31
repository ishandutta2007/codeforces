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

string s[123],ans[123];
string  getreverse(string s){
	string an="";
	int i,n=s.length();
	fd(i,n-1,0)
		an+=s[i];
	return an;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int r,c,k;
    	vector<char> vec;
    	cin>>r>>c>>k;
    	int i,cnt=0,j;
    	rep(i,r){
    		cin>>s[i];
    		rep(j,c){
    			if(s[i][j]=='R')
    				cnt++;
    		}
    	}
    	//cout<<cnt<<endl;
    	rep(i,26){
    		vec.pb((char)('a'+i));
    		vec.pb((char)('A'+i));
    	}
    	rep(i,10){
    		vec.pb((char)('0'+i));
    	}
    	int val,extra;
    	val=cnt/k;
    	extra=cnt%k;
    	int gg=0,eat=val;
    	if(gg<extra)
    		eat++;
    	rep(i,r){
    		ans[i]="";
    		rep(j,c){
    			ans[i]+='a';
    		}
    		
    		if(i%2==0){
    			rep(j,c){
	    			if(s[i][j]=='R'){
	    				eat--;
	    			}
	    			if(eat==-1){
	    				gg++;
	    				eat+=val;
	    				if(gg<extra)
	    					eat++;
	    			}
	    			ans[i][j]=vec[gg];
	    		}
    		}
    		else{
    			fd(j,c-1,0){
	    			if(s[i][j]=='R'){
	    				eat--;
	    			}
	    			if(eat==-1){
	    				gg++;
	    				eat+=val;
	    				if(gg<extra)
	    					eat++;
	    			}
	    			ans[i][j]=vec[gg];
	    		}
    		}
    		
    	}
    	rep(i,r){
    		cout<<ans[i]<<endl;
    	}
    }
    
    return 0;   
}