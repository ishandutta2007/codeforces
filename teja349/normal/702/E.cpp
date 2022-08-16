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
int f[123456],w[123456],lol[100004][34],ans[100004][34];
ll dp[100004][34];
ll n,k;
int compute(){
	int i,j;

	f(i,1,34){

		rep(j,n){
			dp[j][i]=dp[j][i-1]+dp[ans[j][i-1]][i-1];
			lol[j][i]=min(lol[j][i-1],lol[ans[j][i-1]][i-1]);
			ans[j][i]=ans[ans[j][i-1]][i-1];
		}
		//cout<<dp[1][0]<<endl;
	}
	//cout<<dp[1][0]<<endl;
	return 0;
}
int calc(ll num,ll haha){
	ll sumi=0;
	int i;
	int mini=inf;
	fd(i,33,0){
		//ll mini=inf;
		//cout<<(1LL<<i)<<endl;
		if(haha>=1LL<<i){
			//cout<<"yoo"<<endl;
			sumi+=dp[num][i];
			mini=min(lol[num][i],mini);
			//cout<<i<<" "<<lol[num][i]<<endl;
			haha-=1LL<<i;
			num=ans[num][i];
		}
	}
	cout<<sumi<<" "<<mini<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    cin>>n>>k;
    //cout<<k<<endl;
    int i;
    rep(i,n){
    	cin>>f[i];
    	ans[i][0]=f[i];
    }
    rep(i,n){
    	cin>>w[i];
    	dp[i][0]=w[i];
    	lol[i][0]=w[i];
    	//cout<<dp[i][0]<<endl;
    }
    compute();
    rep(i,n){
    	calc(i,k);
    	//cout<<dp[i][0]<<endl;
    }

    
}