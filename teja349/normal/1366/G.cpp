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

int n,m;
vector<vi> dp(12345);
string s,t;
int gg[12345];
int compute(int pos1,int pos2){
	if(pos2<0)
		return 2e4;
	if(pos1==n){
		if(pos2==m){
			return 0;
		}
		return 2e4;
	}
	if(dp[pos1][pos2]!=-1)
		return dp[pos1][pos2];
	int mini=1+compute(pos1+1,pos2);
	if(s[pos1]==t[pos2]){
		mini=min(mini,compute(pos1+1,pos2+1));
	}
	else{
		if(s[pos1]=='.'){
			mini=min(mini,compute(pos1+1,pos2-1));
		}
		else{
			if(gg[pos1]!=0){
				mini=min(mini,compute(gg[pos1],pos2));
			}
		}
	}
	dp[pos1][pos2]=mini;
	return mini;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>s>>t;
    int i,j;
    n=s.length();
    m=t.length();
    map<int,int> mapi;
    mapi[0]=n;
    int sofar=0;
    fd(i,n-1,0){
    	if(s[i]=='.')
    		sofar--;
    	else
    		sofar++;
    	gg[i]=mapi[sofar];
    	mapi[sofar]=i;	
    }
    rep(i,n){
    	rep(j,i+1){
    		dp[i].pb(-1);
    	}
    }
    cout<<compute(0,0)<<endl;
    return 0;   
}