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
int brr[100005],arr[100005],vis[100005];
vector<vi>adj(100005);
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n,m,i,j,u,v,val,k;
	cin>>n>>m;
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if(n==1){
		cout<<"NO"<<endl;
		return 0;
	}	
	val=n*(n-1)/2;
	if(m==val){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	rep(i,n){
		arr[i]=i+1;
		brr[i]=i+1;
	}
	rep(i,n){
		if((int)adj[i].size()!=n-1){
			rep(j,adj[i].size()){
				vis[adj[i][j]]=1;
			}
			rep(j,n){
				if(vis[j]==0&&j!=i){
					brr[i]=brr[j];
					val=brr[i];
					fd(k,j,i+1){
						arr[k]=arr[k-1];
					}
					arr[k]=val;
					break;
				}
			}
			break;
		}
	}
	rep(i,n){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	rep(i,n){
		cout<<brr[i]<<" ";
	}
	cout<<endl;
    return 0;   
}