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
#define mod (998244353)
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
int a[212345];

int dp[312345][3];
int precomp(int k){
	dp[0][0]=1;
	dp[0][1]=0;
	dp[0][2]=0;
	int i,j;
	f(i,1,223456){
		dp[i][0]=dp[i-1][1]+dp[i-1][2];
		dp[i][1]=dp[i-1][0]+dp[i-1][2];
		dp[i][2]=(dp[i-1][0]+dp[i-1][1])*(k-2);
		dp[i][2]+=dp[i-1][2]*(k-3);
		rep(j,3){
			dp[i][j]%=mod;
		}
	}

}
int res[12];
int solve(int val){
	int i;
	rep(i,3){
		res[i]=dp[val][i];
	}
	return 0;
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,k;
  	cin>>n>>k;
  	int i;
  	//cout<<k*(k-1)*(k-1)%mod<<endl;
  	vector<vi> vec(4);
  	rep(i,n){
  		cin>>a[i];
  		vec[i%2].pb(a[i]);
  	}
  	precomp(k);
  	int j=0;
  	int st=-1,en,ans=1;
  	int flag;
  	rep(i,2){
  		flag=0;
  		rep(j,vec[i].size()){
  			if(vec[i][j]!=-1){
  				flag=1;
  				break;
  			}
  		}
  		if(!flag){
  			rep(j,vec[i].size()-1){
  				ans*=(k-1);
  				ans%=mod;
  			}
  			ans*=k;
  			ans%=mod;
  			//cout<<"da"<<endl;
  			continue;
  		}
  		st=j;
  		rep(j,st){
  			ans*=(k-1);
  			ans%=mod;
  			//cout<<"Das"<<endl;
  		}
  		
  		fd(j,vec[i].size()-1,0){
  			if(vec[i][j]!=-1)
  				break;
  		}
  		en=j;
  		fd(j,vec[i].size()-1,en+1){
  			ans*=(k-1);
  			//cout<<"dsa"<<endl;
  			ans%=mod;
  		}
  		j=st+1;
  		while(j<=en){
  			if(vec[i][j]!=-1){
  				solve(j-st);
  				if(vec[i][j]==vec[i][st]){
  					ans*=res[0];
  				}
  				else{
  					ans*=res[1];
  				}
  				ans%=mod;
  				st=j;
  			}
  			j++;
  		}
  	}
  	ans%=mod;
  	cout<<ans<<endl;
    return 0;   
}