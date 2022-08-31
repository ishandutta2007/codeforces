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

int x[12345],y[12345];
int dp[3][3],gg[3];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>x[i]>>y[i];
    	x[i]+=1e7;
    	y[i]+=1e7;
    }
    vi vec;
    int j;
    while(1){
    	rep(i,2){
    		rep(j,2){
    			dp[i][j]=0;
    		}
    		gg[i]=0;
    	}
    	int xx,yy;
    	rep(i,n){
    		xx=x[i]%2;
    		yy=y[i]%2;
    		dp[xx][yy]++;
    		gg[(xx+yy)%2]++;
    	}
    	if(gg[0]%n!=0){
    		rep(i,n){
    			xx=x[i]%2;
    			yy=y[i]%2;
    			xx+=yy;
    			xx%=2;
    			if(xx==0){
    				vec.pb(i);
    			}
    		}
    		cout<<vec.size()<<endl;
    		rep(i,vec.size()){
    			cout<<vec[i]+1<<" ";
    		}
    		cout<<endl;
    		return 0;
    	}
    	int flag=0;
    	rep(i,2){
    		rep(j,2){
    			if(dp[i][j]%n!=0)
    			{
    				flag=1;
    				break;
    			}
    		}
    		if(flag==1)
    			break;
    	}
    	if(flag){
    		int haha=i;
    		int gg=j;
    		rep(i,n){
    			xx=x[i]%2;
    			yy=y[i]%2;
    			if(xx==haha && yy==gg){
    				vec.pb(i);
    			}
    		}
    		//cout<<haha<<" "<<gg<<endl;
    		
    		cout<<vec.size()<<endl;
    		rep(i,vec.size()){
    			cout<<vec[i]+1<<" ";
    		}
    		cout<<endl;
    		return 0;
    	}
    	rep(i,n){
    		x[i]/=2;
    		y[i]/=2;
    	}
    }
    return 0;   
}