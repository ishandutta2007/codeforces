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

string str[123];
int a[123][123],b[123][123];
int mask[12345],cost[12345],haha[12345],wow[12345];
int dp[(1<<20)+12];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,j,k;
    rep(i,n){
    	cin>>str[i];
    }
    rep(i,n){
		rep(j,m){
			cin>>a[i][j];
		}
    }
    int cnt=0;
    rep(i,n){
    	cost[i]=inf;
    	rep(j,m){	
    		cost[i]=min(cost[i],a[i][j]);
    	}
    	mask[i]=(1<<i);
    }
    rep(i,(1<<n)){
    	dp[i]=inf;
    }	
    dp[(1<<n)-1]=0;
    cnt=n;
    rep(j,m){
    	map<int,int> mapi;
    	mapi.clear();
    	rep(i,n){
    		if(mapi.find(str[i][j])==mapi.end()){
    			mapi[str[i][j]]=cnt++;
    		}
    		b[i][j]=mapi[str[i][j]];
    	}
    }
    f(i,n,cnt){
    	haha[i]=0;
    	wow[i]=0;
    }
    
    rep(i,n){
    	rep(j,m){
    		haha[b[i][j]]+=a[i][j];
    		wow[b[i][j]]=max(wow[b[i][j]],a[i][j]);
    		mask[b[i][j]]^=(1<<i);
    	}
    }

    f(i,n,cnt){
    	haha[i]-=wow[i];
    	cost[i]=haha[i];
    	//cout<<haha[i]<<endl;
    }
    int gfdgd=(1<<n)-1;
    rep(i,cnt){
    	mask[i]^=gfdgd;
    }
    rep(i,cnt){
    	//cout<<cost[i]<<endl;
    	rep(j,(1<<n)){
    		dp[j&mask[i]]=min(dp[j&mask[i]],dp[j]+cost[i]);
    	}
    	//cout<<dp[0]<<" "<<mask[i]<<endl;
    }
    cout<<dp[0]<<endl;



    return 0;   
}