
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
//std::ios::sync_with_stdio(false);   


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

int dsu[2005],a[2004][2004]={0};
viii vec;
ll s=0;
vector< vi > adj(2004),cost(2004);
int intial,n;



int root(int p){
	if(dsu[p]<0) 
		return p;
	else
		return (dsu[p]=root(dsu[p]));
}
int merge(int p,int q){
	p=root(p);q=root(q);
	if(dsu[p]>dsu[q]){
		dsu[p]=q;
	}
	else if(dsu[q]>dsu[p]){
		dsu[q]=p;
	}
	else{
		dsu[q]=p;
		dsu[p]--;
	}
}


int form_tree(){
	int i;
	sort(vec.begin(),vec.end());
	rep(i,vec.size()){
		int val=vec[i].ff;
		int first = (vec[i].ss).ff;
		int last = (vec[i].ss).ss;
		if(root(first)!=root(last)){
			merge(first,last);
			adj[first].pb(last);
			adj[last].pb(first);
			cost[first].pb(val);
			cost[last].pb(val);
		}

	}
	return 0;
}

int dfs(int cur,int prev){
	int i;

	rep(i,adj[cur].size()){
		//cout<<adj[cur][i]<<endl;
		if(adj[cur][i]!=prev){
			s+=cost[cur][i];
			//cout<<s<<endl;
			//if(cur)
			if(a[intial][adj[cur][i]]!=s){
				cout<<"NO"<<endl;
				exit(0);
			}
			dfs(adj[cur][i],cur);
			s-=cost[cur][i];
		}
	}
	return 0;
}

int check_tree(){
	int i;
	rep(i,n){
		ll s=0;
		intial =i;
		dfs(i,-1);
	}
	return 0;
}


int main(){
	std::ios::sync_with_stdio(false); 
	fill(dsu,dsu+2005,-1);
	int i,j,nott=0;
	cin>>n;
	rep(i,n){
		rep(j,n){
			cin>>a[i][j];
			if(i!=j && a[i][j]==0)nott=1;
			if(a[j][i]!=0 && a[j][i]!=a[i][j]) nott=1;
			if(i==j&&a[i][j]!=0)nott=1;
			if(i!=j){
				vec.pb(mp(a[i][j],mp(i,j)));
			}
		}
		
	}
	if(nott==1){
		cout<<"NO"<<endl;
		return 0;
	}
	else {
		form_tree();
		check_tree();
		//cout<<"hii"<<endl;
		//cout<<adj[2].size();
		cout<<"YES"<<endl;
		return 0;
	}
}