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
#define mod (998244353)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define int ll

string s,t;
int n,m;
int two[12345];
int visit[3123][3123],dp[3123][3123];
int solve(int cur,int pos){
	//cout<<cur<<" dasd "<<pos<<endl;
	if(cur==-1){
		return 1;
	}
	
	if(pos>=m){
		return two[cur+1];
	}
	if(visit[cur][pos])
		return dp[cur][pos];
	int lastpos=cur+pos;
	visit[cur][pos]=1;
	dp[cur][pos]=0;
	if(s[cur]==t[pos]){
		dp[cur][pos]+=solve(cur-1,pos+1);
	}
	if(lastpos>=m || s[cur]==t[lastpos]){
		dp[cur][pos]+=solve(cur-1,pos);
	}
	if(dp[cur][pos]>=mod)
		dp[cur][pos]-=mod;
	return dp[cur][pos];
} 
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>s>>t;
	n=s.length();
	m=t.length();
	int ans=0;
	int i;
	two[0]=1;
	f(i,1,12345){
		two[i]=two[i-1]*2;
		two[i]%=mod;
	}
	f(i,m-1,n){
		ans+=solve(i,0);
		//cout<<i+1<<" "<<solve(i,0)<<endl;
		ans%=mod;
	}
	//cout<<solve(1,0)<<endl;
	cout<<ans<<endl;
}