
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
int par[100000];
int parent(int u){
	if(par[u]<0)
		return u;
	par[u]=parent(par[u]);
	return par[u];
}   
int merge(int u,int v){
	u=parent(u);
	v=parent(v);
	if(u==v)
		return 0;
	if(par[u]<par[v]){
		par[v]=u;
	}
	else if(par[v]<par[u]){
		par[u]=v;
	}
	else{
		par[u]=v;
		par[v]--;
	}
}

int main(){
	int n,i,val;
	cin>>n;
	memset(par,-1,100000);
	rep(i,n){
		cin>>val;
		val--;
		merge(val,i);
	}
	int counti=0;
	rep(i,n){
		if(par[i]<0)
			counti++;
	}
	cout<<counti<<endl;

}