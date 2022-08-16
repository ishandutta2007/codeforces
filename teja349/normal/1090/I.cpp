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
int b[12345678];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int t;
  	cin>>t;
  	while(t--){
  		int n,l,r,x,y,z;
  		cin>>n>>l>>r>>x>>y>>z;
  		cin>>b[1]>>b[2];
  		int i;
  		int val=(1LL<<32);
  		//val--;
  		//cerr<<val<<endl;
  		f(i,3,n+1){
  			b[i]=b[i-2]*x+b[i-1]*y+z;
  			b[i]%=val;
  			if(b[i]<0)
  				b[i]+=val;
  		}
  		f(i,1,n+1){
  			b[i]=b[i]%(r-l+1)+l;
  		}
  		int iinf=inf;
  		iinf*=inf;
  		iinf*=4;
  		int mini=iinf;
  		int min1=iinf;
  		//cerr<<iinf<<endl;
  		f(i,1,n+1){
  			min1=min(min1,b[i]);
  			if(b[i]>=0 && min1<b[i]){
  	
  					mini=min(mini,min1*(b[i]));
  				
  			}
  			
  		}
  		min1=iinf;
  		min1*=-1;
  		fd(i,n,1){
  			min1=max(min1,b[i]);
  			if(b[i]<0 && min1>b[i]){
  				mini=min(mini,min1*(b[i]));
  			}
  		}
  		if(mini==iinf){
  			cout<<"IMPOSSIBLE"<<"\n";
  		}
  		else{
  			cout<<mini<<"\n";
  		}
  	}
    return 0;   
}