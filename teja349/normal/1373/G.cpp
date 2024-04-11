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

int seg[2123456],bestsuf[2123456];
int build(int node,int s,int e){
	if(s==e){
		bestsuf[node]=0;
		seg[node]=-1;	
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=seg[2*node]+seg[2*node+1];
	bestsuf[node]=max(bestsuf[2*node+1],bestsuf[2*node]+seg[2*node+1]);
	return 0;
}
int update(int node,int s,int e,int pos,int val){
	//cout<<node<<" "<<s<<" "<<e<<" "<<bestsuf[node]<<" "<<val<<endl;
	if(s==e){
		
		seg[node]+=val;

		//cout<<seg[node]<<endl;
		bestsuf[node]=max(0,seg[node]);	
		//cout<<seg[node]<<" "<<bestsuf[node]<<" fds"<<endl;
		return 0;
	}
	int mid=(s+e)/2;
	if(pos<=mid){
		update(2*node,s,mid,pos,val);
	}
	else{
		update(2*node+1,mid+1,e,pos,val);
	}
	seg[node]=seg[2*node]+seg[2*node+1];
	bestsuf[node]=max(bestsuf[2*node+1],bestsuf[2*node]+seg[2*node+1]);
}
pii query(int node,int s,int e,int l,int r){
	if(r<l || r<s){
		return mp(0,0);
	}
	if(l<=s && e<=r){
		//cout<<s<<" "<<e<<" "<<seg[node]<<endl;
		return mp(seg[node],bestsuf[node]);
	}
	int mid=(s+e)/2;
	pii a=query(2*node,s,mid,l,r);
	pii b = query(2*node+1,mid+1,e,l,r);
	return mp(a.ff+b.ff,max(b.ss,b.ff+a.ss));
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k,m;
    cin>>n>>k>>m;
    int i;
    int e=5e5;
    build(1,1,e);
    set<pii> seti;
    multiset<int> sofar;
    multiset<int>::iterator it;
    int x,y,val;	
    rep(i,m){
    	cin>>x>>y;
    	val=abs(x-k)+y;
    	//cout<<val<<" ";
    	if(seti.find(mp(x,y))!=seti.end()){
    		//cout<<"dsa"<<endl;
    		seti.erase(mp(x,y));
    		sofar.erase(sofar.find(val));
    		update(1,1,e,val,-1);
    	}
    	else{
    		seti.insert(mp(x,y));
    		sofar.insert(val);
    		update(1,1,e,val,1);
    	}
    	if(seti.empty()){
    		cout<<0<<endl;
    		continue;
    	}
    	it=sofar.end();
    	it--;
    	//cout<<*it<<" ";
    	int ans=0;
    	//if(i==1)
    		ans=query(1,1,e,1,*it).ss;
    	ans+=*it;
    	cout<<max(ans-n,0)<<endl;
    }
    return 0;   
}