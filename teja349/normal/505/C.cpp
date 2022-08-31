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
int gem[123456]={0};
int dp[30013][800];
//unordered_map<int,int> mapi;

int dis; 
int compute(int cur,int siz){
	int d=cur;
	if(siz<=0)
		return 0;
	if(d>30003)
		return 0; 
	if(dp[cur][400+siz-dis]!=-1)
		return dp[cur][400+siz-dis];
	int ans=0;
	
		ans+=gem[cur];
	ans+=max(compute(d+siz-1,siz-1),max(compute(d+siz,siz),compute(d+siz+1,siz+1)));
	dp[cur][400+siz-dis]=ans;
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,d;
	cin>>n>>d;
	int i,val,j;
	rep(i,30012){
		rep(j,800){
			dp[i][j]=-1;
		}
	}
	dis=d;
	rep(i,n){
		cin>>val;
		gem[val]++;
	}
	//return 0;
	cout<<compute(d,d);
}