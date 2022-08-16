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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
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
int dp[1234][(1<<12)+2],visit[1234][(1<<12)+2];
int mask[1234],n,gao[1234],cost[1234];
vii poss;
int solve(int cur,int plot){
	//cout<<cur<<" "<<plot<<endl;
	if(cur>=n)
		return 0;
	if(visit[cur][plot])
		return dp[cur][plot];
	visit[cur][plot]=1;
	int gg=plot/256;
	int bar,foo,costi;
	//if(cur==0){
	//	cout<<gg<<endl;
	//}
	if(gg==0){
		foo=plot%256;
		dp[cur][plot]=solve(cur+1,foo*16+mask[cur+3]);
		return dp[cur][plot];
	}
	dp[cur][plot]=cost[4]+solve(cur+4,gao[cur+4]);
	//cout<<dp[cur][plot]<<" "<<cur<<endl;
	int i;
	rep(i,poss.size()){
		bar=plot&poss[i].ff;
		gg=bar/256;
		foo=bar%256;
		costi=poss[i].ss+__builtin_popcount(gg)*cost[1]+solve(cur+1,foo*16+mask[cur+3]);
		//if(i==0)
		//	cout<<cur<<" "<<costi<<endl;
		//if(cur==3)
		//	cout<<costi<<" "<<i<<" "<<foo<<endl;
		dp[cur][plot]=min(dp[cur][plot],costi);
	}
	//cout<<cur<<" "<<plot<<" "<<dp[cur][plot]<<endl;
	//cout<<cur<<" "<<plot<<" "<<dp[cur][plot]<<endl;
	return dp[cur][plot];
	//cout<<cur<<" "<<plot<<" "<<dp[cur][plot]<<endl;
}

int a[6][1234];
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	//int n;
	cin>>n;
	int i;
	f(i,1,5){
		cin>>cost[i];
	}
	//poss.pb(mp(0,a[4]));
	poss.pb(mp((1<<11)+(1<<7)+(1<<3),cost[3]));
	poss.pb(mp((1<<8)+(1<<4)+(1<<0),cost[3]));
	poss.pb(mp(0,2*cost[3]));
	poss.pb(mp(1,cost[3]+cost[2]));
	poss.pb(mp(8,cost[3]+cost[2]));
	poss.pb(mp((1<<12)-1-(1<<11)-(1<<10)-(1<<7)-(1<<6),cost[2]));
	poss.pb(mp((1<<12)-1-(1<<9)-(1<<10)-(1<<5)-(1<<6),cost[2]));
	poss.pb(mp((1<<12)-1-(1<<8)-(1<<9)-(1<<4)-(1<<5),cost[2]));
	poss.pb(mp((1<<0)+(1<<1)+(1<<2)+(1<<3),2*cost[2]));
	poss.pb(mp((1<<12)-1,0));
	string s;
	int j;
	rep(i,4){
		cin>>s;
		rep(j,n){
			if(s[j]=='*')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	rep(i,n){
		rep(j,4){
			mask[i]*=2;
			mask[i]+=a[j][i];
		}
	}
	rep(i,n){
		gao[i]=mask[i]*16*16+mask[i+1]*16+mask[i+2];
	}
	//cout<<(gao[3]&poss[5].ff)<<endl;
	cout<<solve(0,gao[0])<<endl;
	//cout<<solve(3,gao[3])<<endl;
}