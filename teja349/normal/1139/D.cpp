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
int powe(int a,int b){
	int res=1;
	while(b){
		if(b%2){
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return res;
}
int dp[123456],wow[123456];
vector<vi> facto(123456);

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int m;
  	cin>>m;
  	dp[1]=0;
  	int i,j;
  	int k;
  	for(i=1;i<m+10;i++){
  		for(j=i;j<=m+10;j+=i){
  			facto[j].pb(i);
  		}
  	}
  	f(i,2,m+2){
  		fd(j,facto[i].size()-1,0){
  			wow[j]=m/facto[i][j];
  			f(k,j+1,facto[i].size()){
  				if(facto[i][k]%facto[i][j]==0){
  					wow[j]-=wow[k];
  				}
  			}  		
  		}
  		dp[i]=m;
  		rep(j,facto[i].size()-1){
  			dp[i]+=wow[j]*dp[facto[i][j]];
  			dp[i]%=mod;
  		}
  		dp[i]*=powe(m-m/i,mod-2);
  		dp[i]%=mod;
  	}
  	ll ans=m;
  	f(i,1,m+1){
  		ans+=dp[i];
  		ans%=mod;
  	}
  	ans*=powe(m,mod-2);
  	ans%=mod;
  	cout<<ans<<endl;
    return 0;   
}