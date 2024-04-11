
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
int a[123456];
int dp[123456]={0},dpr[123456]={0};
int n;
int compute(int i){
	if(dp[i]!=0)
		return dp[i];
	if(i==n-1){
		dp[i]=1;
		return 1;
	}
	if(a[i]<a[i+1])
		dp[i]=1+compute(i+1);
	else
		dp[i]=1;
	return dp[i];
}
int comp(int i){
	if(dpr[i]!=0)
		return dpr[i];
	if(i==0){
		dpr[i]=1;
		return 1;
	}
	if(a[i]>a[i-1])
		dpr[i]=1+comp(i-1);
	else
		dpr[i]=1;
	return dpr[i];
}


int main(){
	
	cin>>n;
	int i;
	if(n<=2)
	{
		cout<<n<<endl;
		return 0;
	}
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		compute(i);
	}
	fd(i,n-1,0){
		comp(i);
	}
	int val=max(dp[1]+1,dpr[n-2]+1);
	f(i,1,n-1){
		val=max(max(val,dpr[i-1]+1),dp[i+1]+1);
		int value=a[i-1]+1;
		if(value<a[i+1])
			val=max(val,dpr[i-1]+dp[i+1]+1);
	}
	
	cout<<val<<endl;
}