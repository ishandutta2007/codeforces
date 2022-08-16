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

int visit[101][101][101][2],dp[101][101][101][2];
int p[123],a[123];
int n;
int compute(int pos,int zero,int one,int last){
	if(pos==n)
		return 0;
	if(visit[pos][zero][one][last])
		return dp[pos][zero][one][last];
	visit[pos][zero][one][last]=1;
	int ans=0;
	if(p[pos]!=0){
		ans=0;
		if(p[pos]%2!=last)
			ans++;
		ans+=compute(pos+1,zero,one,p[pos]%2);
	}
	else{
		int mini=inf;
		if(zero){
			ans=0;
			if(last!=0)
				ans++;
			ans+=compute(pos+1,zero-1,one,0);
			mini=min(mini,ans);
		}
		if(one){
			ans=0;
			if(last!=1)
				ans++;
			ans+=compute(pos+1,zero,one-1,1);
			mini=min(mini,ans);
		}
		ans=mini;
	}
	dp[pos][zero][one][last]=ans;
	return ans;
}
int deg[3];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n;
    int i;
    rep(i,n){
    	cin>>p[i];
    	a[p[i]]=1;
    }
    f(i,1,n+1){
    	if(a[i]==0){
    		deg[i%2]++;
    	}
    }
    //cout<<deg[0]<<" "<<deg[1]<<endl;
    int val1=compute(0,deg[0],deg[1],0);
    int val2=compute(0,deg[0],deg[1],1);
    cout<<min(val1,val2)<<endl;
    return 0;   
}