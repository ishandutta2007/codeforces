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
double PI=3.14159265358979323846;
struct total{
	ll x,y,r;
};  
total a[1234];
vector<vi> adj(1234);
int par[1234];
ll dp[1234][2][2];

int comp(total p,total q){
	return p.r>q.r;
}
ll compute(int cur,int p,int q){
	if(dp[cur][p][q]!=0){
		return dp[cur][p][q];
	}
	ll i;
	ll maxi,ans;
	if(p==0){
		ans=a[cur].r*a[cur].r;
		rep(i,adj[cur].size()){
			ans+=compute(adj[cur][i],1,q);
		}
	}
	else{
		ans=a[cur].r*a[cur].r*-1;
		rep(i,adj[cur].size()){
			ans+=compute(adj[cur][i],0,q);
		}
	}
	maxi=ans;
	if(q==0){
		ans=a[cur].r*a[cur].r;
		rep(i,adj[cur].size()){
			ans+=compute(adj[cur][i],p,1);
		}
	}
	else{
		ans=a[cur].r*a[cur].r*(-1);
		rep(i,adj[cur].size()){
			ans+=compute(adj[cur][i],p,0);
		}
	}
	maxi=max(maxi,ans);
	dp[cur][p][q]=maxi;
	return maxi;

}
int inner(int i,int j){
	ll sumi=(a[i].x-a[j].x)*(a[i].x-a[j].x);
	sumi+=(a[i].y-a[j].y)*(a[i].y-a[j].y);
	if(sumi<=a[j].r *a[j].r){
		return 1;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>a[i].x>>a[i].y>>a[i].r;
    }
    sort(a,a+n,comp);
    rep(i,n){
    	par[i]=-1;
    	fd(j,i-1,0){
    		if(inner(i,j)){
    			par[i]=j;
    			break;
    		}
    	}
    }
    rep(i,n){
    	if(par[i]!=-1){
    		adj[par[i]].pb(i);
    	}
    }
    double sumi=0;
    rep(i,n){
    	if(par[i]==-1){
    		sumi+=compute(i,0,0);
    	}
    }
    sumi*=PI;

    cout << setprecision (20) << sumi << endl;
}