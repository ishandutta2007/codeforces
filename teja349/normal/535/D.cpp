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

int z[1234567];

int z_algo_construct(string s){
	int l=0,r=0;
	int i,n=s.length();
	

	f(i,1,s.length()){
		if(i>r){
			l=r=i;
			while (r < n && s[r-l] == s[r]) r++;
   			z[i] = r-l; r--;   			
		}
		else{
			int k=i-l;
			if(z[k]<r-i+1) z[i] = z[k];	
			else{
				l=i;
				while(r < n && s[r-l]==s[r])r++;
				z[i] = r-l; r--;
			}		
		}

	}
	return 0;
	
}

int seen[1234567];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,m;
  	cin>>n>>m;
  	string p;
  	cin>>p;
  	int i,val;
  	rep(i,m){
  		cin>>val;
  		val--;
  		seen[val]=1;
  	}
  	int len=p.length();
  	int lef=0;
  	ll ans=1;
  	z_algo_construct(p);
  	rep(i,n){
  		if(seen[i]){
  			if(lef!=0 && z[len-lef]!=lef){
  				ans=0;
  			}
  			lef=len;
  			
  		}
  		if(lef){
  			seen[i]=1;
  			lef--;
  		}
  	}
  	
  	rep(i,n){
  		if(seen[i])
  			continue;
  		ans*=26;
  		ans%=mod;
  	}
  	cout<<ans<<endl;
    return 0;   
}