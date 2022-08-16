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

int a[212345],haha[212345],gg[212345];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int i;
    	rep(i,n){
    		cin>>a[i];
    		haha[i]=0;
    		gg[i]=0;
    	}
    	set<int> seti;
    	set<int>::iterator it;
    	rep(i,n){
    		seti.insert(a[i]);
    		it=seti.end();
    		it--;
    		if(seti.size()==i+1 && (*it==i+1)){
    			haha[i]=1;
    		}
    	}
    	seti.clear();
    	int len=0;
    	fd(i,n-1,0){
    		len++;
    		seti.insert(a[i]);
    		it=seti.end();
    		it--;
    		if(seti.size()==len && (*it==len)){
    			gg[i]=1;
    		}
    	}
    	int cnt=0;
    	rep(i,n-1){
    		if(haha[i]==1 && gg[i+1]==1){
    			cnt++;
    		}
    	}
    	cout<<cnt<<endl;
    	rep(i,n-1){
    		if(haha[i]==1 && gg[i+1]==1){
    			cout<<i+1<<" "<<n-(i+1)<<endl;
    		}
    	}
    }	
    return 0;
}