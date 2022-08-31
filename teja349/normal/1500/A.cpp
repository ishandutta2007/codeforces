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

int a[212345];
vector<vii> haha(5123456);
vector<vi> adj(2523456);
int check(int x,int y){
	int i;
	int val=a[x]+a[y];
	rep(i,haha[val].size()){
		if(haha[val][i].ff!=x && haha[val][i].ss!=x && haha[val][i].ff!=y && haha[val][i].ss!=y){
			cout<<"YES"<<endl;
			cout<<haha[val][i].ff+1<<" "<<haha[val][i].ss+1<<" "<<x+1<<" "<<y+1<<endl;
			exit(0);
		}
	}
	haha[val].pb(mp(x,y));
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,j;
    map<int,int> mapi;
    rep(i,n){
    	cin>>a[i];
    	mapi[a[i]]++;
    	adj[a[i]].pb(i+1);
    }
    int four=-1;
    int two1=-1;
    int two2=-1;
    map<int,int>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
    	if(it->ss>=4){
    		four=it->ff;
    		break;
    	}
    	if(it->ss>=2){
    		if(two1==-1){
    			two1=it->ff;
    		}
    		else{
    			two2=it->ff;
    			break;
    		}
    	}
    }
    if(four!=-1){
    	cout<<"YES"<<endl;
    	cout<<adj[four][0]<<" "<<adj[four][1]<<" "<<adj[four][2]<<" "<<adj[four][3]<<endl;
    	return 0;
    }
    
   if(two2!=-1){
   	cout<<"YES"<<endl;
   	cout<<adj[two1][0]<<" "<<adj[two2][0]<<" "<<adj[two1][1]<<" "<<adj[two2][1]<<endl;
   	return 0;
   }

   rep(i,n){
    	f(j,i+1,n){
    		check(i,j);
    	}
    }
    cout<<"NO"<<endl;
    return 0;
}