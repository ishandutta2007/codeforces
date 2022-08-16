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

int m,k,n,s;

int cnt[512345],a[512345],b[512345];
int solve(int val,int en){
	vi vec;
	int i;
	f(i,(val/k)*k,val){
		vec.pb(i);
	}
	int haha=en-i+1;
	f(i,val,en){
		if(haha>k && cnt[a[i]]<0){
			vec.pb(i);
			cnt[a[i]]++;
			haha--;
		}
	}
	cout<<vec.size()<<endl;
	rep(i,vec.size()){
		cout<<vec[i]+1<<" ";
	}
	return 0;
	
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	
  	cin>>m>>k>>n>>s;
  	int i;
  	rep(i,m){
  		cin>>a[i];
  	}
  	rep(i,s){
  		cin>>b[i];
  		cnt[b[i]]++;
  	}
  	int gg=0;
  	rep(i,512345){
  		if(cnt[i])
  			gg++;
  	}
  	int haha=k;
  	i=0;
  	int j=-1;
  	while(i<m && j<m){
  		//cout<<i<<" "<<j<<endl;
  		if(gg==0 && haha<=0){
  			
  			if(i/k+(m-j-1)/k+1>=n){
  				solve(i,j);
  				return 0;
  			}
  			haha++;
  			cnt[a[i]]++;
  			if(cnt[a[i]]==1){
  				gg++;
  			}
  			i++;
  		}
  		else{
  			j++;
  			if(j==m){
  				cout<<-1<<endl;
  				return 0;
  			}
  			haha--;
  			cnt[a[j]]--;
  			if(cnt[a[j]]==0){
  				gg--;
  			}
  		}
  	}
  	cout<<-1<<endl;
  	return 0;
    return 0;   
}