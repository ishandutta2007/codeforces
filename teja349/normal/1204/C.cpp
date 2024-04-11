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

int dist[123][123];
string s[123];
int val[1234567];
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int i,j,k;
	rep(i,n){
		cin>>s[i];
	}
	rep(i,n){
		rep(j,n){
			if(s[i][j]=='0')
				dist[i][j]=inf;
			else
				dist[i][j]=1;
		}
		dist[i][i]=0;
	}
	rep(k,n){
		rep(i,n){
			rep(j,n){
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	int m;
	int ver,last;
	cin>>m;
	cin>>ver;
	ver--;
	vi vec;
	vec.pb(ver);
	last=0;
	f(i,1,m){
		cin>>val[i];
		val[i]--;
		if(dist[ver][val[i]]!=i-last){
			vec.pb(val[i-1]);
			ver=val[i-1];
			last=i-1;
		}
	}
	vec.pb(val[m-1]);
	cout<<vec.size()<<endl;
	rep(i,vec.size()){
		cout<<vec[i]+1<<" ";
	}
	cout<<endl;

}