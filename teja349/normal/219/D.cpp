
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

vector< vi > adji(200009),adjo(200009);
int dp[200009]={0};


int dfs(int cur,int prev){
	int i;
	rep(i,adjo[cur].size()){
		if(adjo[cur][i]!=prev){
			dp[cur]+=dfs(adjo[cur][i],cur);
		}

	}
	rep(i,adji[cur].size()){
		if(adji[cur][i]!=prev){
			dp[cur]++;	
			dp[cur]+=dfs(adji[cur][i],cur);
		}

	}
	return dp[cur];

}

int dfs2(int cur,int prev){
	int i;
	rep(i,adjo[cur].size()){
		if(adjo[cur][i]!=prev){
			dp[adjo[cur][i]]=dp[cur]+1;
			dfs2(adjo[cur][i],cur);
		}

	}
	rep(i,adji[cur].size()){
		if(adji[cur][i]!=prev){
			dp[adji[cur][i]]=dp[cur]-1;
			dfs2(adji[cur][i],cur);
		}

	}
	return 0;

}


int main(){


	std::ios::sync_with_stdio(false);
	int n,i,u,v,mini=2001000;
	cin>>n;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		adjo[u].pb(v);
		adji[v].pb(u);

	}

	dfs(0,-1);

	dfs2(0,-1);
	//cout<<"hii"<<endl;
	fflush(stdout);
	rep(i,n){
		if(dp[i]<mini){
			mini=dp[i];
		}
	}
	cout<<mini<<endl;
	rep(i,n){
		if(dp[i]==mini)
			cout<<i+1<<" ";
	}
}