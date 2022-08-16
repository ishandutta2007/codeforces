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

int a[123456];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,l;
    	cin>>n>>l;
    	int i;
    	rep(i,n){
    		cin>>a[i];
    	}
    	long double tottime=0;
    	long double st=0,en=l;
    	int stf=0,enf=n-1;
    	long double sp1=1.0;
    	long double sp2=1.0;
    	while(stf<=enf){
    		long double tim1=(a[stf]-st)*1.0/sp1;
    		long double tim2=(en-a[enf])*1.0/sp2;
    		
    		if(tim1<tim2){
    			tottime+=tim1;
    			st=a[stf];
    			stf++;
    			sp1++;
    			en=en-sp2*tim1;
    		}
    		else{
    			tottime+=tim2;
    			en=a[enf];
    			enf--;
    			sp2++;
    			st=st+sp1*tim2;
    		}
    		//cout<<sp1<<" "<<sp2<<endl;
    	}
    	// cout<<sp1<<" "<<sp2<<endl;
    	tottime+=(en-st)/(sp1+sp2);
    	cout<<setprecision(30)<<tottime<<endl;
    }
}