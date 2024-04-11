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

int magic;
int query(int u,int w,int v){
	u++;

	v++;
	w++;
	cout<<"? "<<u<<" "<<v<<" "<<w<<endl;
	fflush(stdout);
	string val;
	cin>>val;
	if(val[0]=='Y')
		return 1;
	return 0;
}
int foundans(int val){
	val++;
	cout<<"! "<<val<<endl;
	fflush(stdout);
	exit(0);
}
int n;
int checkpar(int u,int v){
	int i;
	int cnt=0;
	rep(i,n){
		if(i==v || i==u)
			continue;
		if(query(v,i,u))
			cnt++;
	}
	if(cnt==magic){
		foundans(u);
	}
	if(cnt>magic){
		return 1;
	}
	return 0;
}

int getlca(int u,int v){
	vi vec;
	vi vec1;
	int i;
	vec.clear();
	rep(i,n){
		if(i==u || i==v)
			continue;
		if(query(u,v,i)){
			vec.pb(i);
		}
	}
	random_shuffle(all(vec));
	int ind=0;
	while(1){
		i=vec[ind];
		ind++;
		if(!query(u,v,i)){
			continue;
		}
		if(checkpar(i,u)){
			if(checkpar(i,v))
				return i;
			else
				u=i;
		}
		else{
			v=i;
		}

		
	}
}

int findlca(int u,int v){
	if(checkpar(u,v))
		return u;
	if(checkpar(v,u))
		return v;
	return getlca(u,v);
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int k;
  	cin>>n>>k;
  	int u,v;
  	magic=((n-1)/k)*(k-1);
  	u=rng()%n;
  	while(1){
  		v=rng()%n;
  		if(u==v)
  			continue;
  		u=findlca(u,v);
  	}
    return 0;   
}