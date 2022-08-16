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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
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

//std::ios::sync_with_stdio(false);  
int seg[812345],pre[212345],en[212345],invpre[212345];
int lazy[812345],p[212345],t[212345];
vector<vi> adj(212345);
 int tim=0;
int dfs(int cur){
	//cout<<cur<<endl;
	pre[cur]=tim++;
	invpre[tim-1]=cur;
	int i;
	rep(i,adj[cur].size()){
		dfs(adj[cur][i]);

	}
	en[cur]=tim-1;
	return 0;
}
int build(int node,int s,int e){
	if(s==e){
		//cout<<s<<endl;
		seg[node]=t[invpre[s]];
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=seg[2*node]+seg[2*node+1];
	return 0;
}
int lazyup(int node,int s,int e){
	if(!lazy[node])
		return 0;
	lazy[node]=0;
	seg[node]=(e-s+1)-seg[node];
	if(s!=e){
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
	return 0;
}
int query(int node,int s,int e,int l,int r){
	if(e<l || r<s)
		return 0;
	lazyup(node,s,e);
	if(l<=s && e<=r)
		return seg[node];
	int mid=(s+e)/2;
	int a=query(2*node,s,mid,l,r);
	int b=query(2*node+1,mid+1,e,l,r);
	return a+b;
}
int update(int node,int s,int e,int l,int r){
	
	lazyup(node,s,e);
	if(e<l || r<s)
		return 0;
	
	if(l<=s && e<=r){
		seg[node]=(e-s+1)-seg[node];
		if(s!=e){
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		return 0;
	}
	int mid=(s+e)/2;
	update(2*node,s,mid,l,r);
	update(2*node+1,mid+1,e,l,r);
	seg[node]=seg[2*node+1]+seg[2*node];
	return 0;

}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n-1){
    	cin>>p[i+1];
    	p[i+1]--;
    	adj[p[i+1]].pb(i+1);
    }
    rep(i,n){
    	cin>>t[i];
    }
    dfs(0);
    int q;
    build(1,0,n-1);
    cin>>q;
    string s;
    int val;
    while(q--){
    	cin>>s>>val;
    	val--;
    	if(s[0]=='g'){
    		//cout<<pre[val]<<" "<<en[val]<<endl; 
    		cout<<query(1,0,n-1,pre[val],en[val])<<endl;
    		//return 0;
    	}
    	else{
    		update(1,0,n-1,pre[val],en[val]);
    	}
    }
    return 0;  
    
}