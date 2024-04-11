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
int dp[100][2];
int a[100],n;
int compute(int pos,int j){

	if(pos==n)
		return 0;
	if(dp[pos][j]!=-inf)
		return dp[pos][j];
	int ans;
	if(j==0){
		ans=max(compute(pos+1,0)-a[pos],a[pos]+compute(pos+1,1));
	}
	else{
		ans=min(compute(pos+1,1)+a[pos],-1*a[pos]+compute(pos+1,0));
	}
	dp[pos][j]=ans;
	return dp[pos][j];
}
int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>n;
	int i;
	int sumi=0;
	rep(i,100){
		dp[i][0]=-inf;
		dp[i][1]=-inf;
	}
	rep(i,n){
		cin>>a[i];
		sumi+=a[i];
	}
	int val=compute(0,0);
	//cout<<val<<endl;
	cout<<(sumi-val)/2<<" "<<(sumi+val)/2<<endl;
	return 0;
}