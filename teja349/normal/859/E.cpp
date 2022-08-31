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
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
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
int a[212345],b[212345],visit[212345];
int out[212345];
ll dp[212345];
int flag,ans;
vector<vi> inadj(212345);
int dfs(int val){
	visit[val]=1;
	//intime[val]=timer++;
	if(out[val]==0){
		ans=val;
		flag=0;
		return 0;
	}
	if(visit[out[val]])
	{
		flag=1;
		ans=val;
		return 0;
	}
	dfs(out[val]);
	return 0;




}
int dfs1(int cur,int par){
	int i;
	visit[cur]=1;
	dp[cur]=1;
	rep(i,inadj[cur].size()){
		if(inadj[cur][i]!=par){
			dfs1(inadj[cur][i],cur);
			dp[cur]+=dp[inadj[cur][i]];
			dp[cur]%=mod;
		}
	}
	return 0;
	
}
int dfs2(int cur){
	//cout<<cur<<endl;
	int val=cur;
	int haha=1;
	//dfs1(cur,-1);
	int prev=cur;
	cur=out[cur];

	while(cur!=val){
		//if(cur==0)
			//cout<<"boo";
		dfs1(cur,prev);
		haha++;
		prev=cur;
		cur=out[cur];
	}
	//cout<<visit[prev]<<endl;
	dfs1(val,prev);

	return haha;
}
int haha[212345];
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i;
	rep(i,n){
		cin>>a[i]>>b[i];
		inadj[b[i]].pb(a[i]);
		
		out[a[i]]=b[i];
		haha[a[i]]=1;
		haha[b[i]]=1;
	}
	ll lol=1;
	f(i,1,2*n+1){
		if(!haha[i])
			continue;
		if(!visit[i]){
			dfs(i);
			if(flag==0){
				dfs1(ans,-1);
				lol*=dp[ans];
				lol%=mod;
			}
			else{
				lol*=min(dfs2(ans),2);
				lol%=mod;
			}
		}
	}
	cout<<lol<<endl;
}