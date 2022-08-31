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

int visit[123][123];
string s[123];
int n,m;
int d1[4] = {1,0,-1,0};
int d2[4] = {0,1,0,-1};
int valid(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m)
		return 0;
	if(s[i][j]=='.')
		return 1;
	return 0;
}
int valid1(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m)
		return 0;
	if(s[i][j]!='#')
		return 1;
	return 0;
}

int fg=0,fb=0;
int dfs(int i,int j){
	visit[i][j]=1;
	if(s[i][j]=='G')
		fg++;
	if(s[i][j]=='B')
		fb++;
	int k;
	//cout<<i<<" "<<j<<endl;
	rep(k,4){
		if(valid1(i+d1[k],j+d2[k]) && visit[i+d1[k]][j+d2[k]]==0)
			dfs(i+d1[k],j+d2[k]);
	}
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	//int n,m;
    	cin>>n>>m;
    	int i,j,k;
    	int good=0;
    	fg=0;
    	fb=0;
    	rep(i,n){
    		cin>>s[i];
    		rep(j,m){
    			if(s[i][j]=='G'){
    				good++;
    			}
    		}
    	}
    	if(good==0){
    		cout<<"Yes"<<endl;
    		continue;
    	}
    	good++;
    	s[n-1][m-1]='G';
    	rep(i,n){
    		rep(j,m){
    			if(s[i][j]!='B')
    				continue;
    			//cout<<"Das"<<endl;
    			rep(k,4){
    				if(valid(i+d1[k],j+d2[k])){
    					s[i+d1[k]][j+d2[k]]='#';
    				}
    			}
    		}
    	}
    	rep(i,n){
    		rep(j,m){
    			visit[i][j]=0;
    		}
    	}
    	int ffddf=0;
    	rep(i,n){
    		rep(j,m){
    			if(s[i][j]=='G'){
    				//cout<<i<<" "<<j<<endl;
    				ffddf=1;
    				break;
    			}
    		}
    			if(ffddf)
    				break;

    	}
    	
    	dfs(i,j);
    	//cout<<fg<<endl;
    	if(fg!=good || fb!=0){
    		cout<<"No"<<endl;
    	}
    	else{
    		cout<<"Yes"<<endl;
    	}

    }
    return 0;   
}