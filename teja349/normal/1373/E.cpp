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

int dp[1234][12];
int getsum(int val){
	int ans=0;
	while(val>0){
		ans+=val%10;
		val/=10;
	}
	return ans;
}
int digsum(int val){
	while(val>=10){
		val=getsum(val);
	}
	return val;
}
int checkposi(int n,int k){
	n=digsum(n);
	int val=k*(k+1)/2;
	int i;
	f(i,1,10){
		if(digsum(i*(k+1)+val)==n)
			return 1;
	}
	return 0;
}
ll solve0(int n){
	ll ans=0,i;
	ll digs=(n+8)/9;
	ans=ans*10+n-9*(digs-1);
	rep(i,digs-1){
		ans=ans*10+9;
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int i,j,k,val;
    rep(i,1234567){
    	val=0;
    	rep(k,10){
    		val+=getsum(i+k);
    		if(val<=150){
    			if(dp[val][k]==0)
    				dp[val][k]=i+1;
    		}
    		else{
    			break;
    		}
    	}
    }
    int t=0;
    cin>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	if(checkposi(n,k)==0 || i<k*(k+1)/2){
    		cout<<-1<<endl;
    		continue;
    	}
    	if(dp[n][k]>0){
    		cout<<dp[n][k]-1<<endl;
    		continue;
    	}	
    	if(k==0){
    		cout<<solve0(n)<<endl;
    		continue;
    	}
    	if(k>=3){
    		cout<<-1<<endl;
    		continue;
    	}
    	if(k==1){
    		if(n<100){
    			cout<<-1<<endl;
    			continue;
    		}
    		if(n%2){
    			int last=8;
    			n-=8;
    			n-=9;
    			n/=2;
    			cout<<solve0(n)<<8<<endl;
    		}
    		else{
    			int last=89;
    			n-=8+9;
    			n-=9;
    			n/=2;
    			cout<<solve0(n)<<89<<endl;
    		}
    	}
    }
    // f(k,1,2){
    // 	rep(i,151){
    // 		if(dp[i][k]>0 && i>=k*(k+1)/2 && checkposi(i,k)){
    // 			cout<<k<<" "<<i<<" "<<dp[i][k]-1<<endl;
    // 			// cout<<
    // 		}
    // 	}
    // }
    return 0;   
}