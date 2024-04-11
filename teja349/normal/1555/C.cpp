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
int foo,m;
int dp[2][123456];
int a[2][123456];
// int solve(int sumi,int pos1,int pos2){
// 	if(visit[sumi][pos1][pos2]==foo){
// 		return dp[sumi][pos1][pos2];
// 	}
// 	visit[sumi][pos1][pos2]=foo;
// 	dp[sumi][pos1][pos2]=0;
// 	if(pos1!=pos2){
// 		//cout<<pos2<<" "<<sumi-pos2<<endl;
// 		dp[sumi][pos1][pos2]+=a[pos2][sumi-pos2];
// 	}
// 	if(sumi==m){
// 		return 0;
// 	}
// 	if(sumi==m-1){
// 		dp[sumi][pos1][pos2]+=solve(sumi+1,1,1);
		
// 		return dp[sumi][pos1][pos2];
// 	}

// 	if(pos1==1){
// 		int val=solve(sumi+1,pos1,pos2);
// 		if(pos2==0){
// 			val=max(solve(sumi+1,pos1,1),val);
// 		}
// 		dp[sumi][pos1][pos2]+=val;
// 	}
// 	else{
// 		int val=solve(sumi+1,pos1,pos2);
// 		if(pos2==0){
// 			val=max(solve(sumi+1,pos1,1),val);
// 		}
// 		int val1=solve(sumi+1,1,pos2);
// 		if(pos2==0){
// 			val1=max(solve(sumi+1,1,1),val1);
// 		}
// 		val=min(val,val1);
// 		dp[sumi][pos1][pos2]+=val;
// 	}
// 	return dp[sumi][pos1][pos2];

// }

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    foo=0;
    while(t--){
    	int n;
    	cin>>n;
    	m=n;
    	int i,j;
    	foo++;
    	dp[0][0]=0;
    	dp[1][0]=0;
    	rep(i,2){
    		f(j,1,n+1){
    			cin>>a[i][j];
    			dp[i][j]=dp[i][j-1]+a[i][j];
    			//cout<<a[i][j]<<" ";
    		}
    		//cout<<endl;
    	}
    	int ans=inf;
    	f(j,1,n+1){
    		ans=min(ans,max(dp[0][n]-dp[0][j],dp[1][j-1]));
    	}
    	cout<<ans<<endl;
    }
    return 0;
}