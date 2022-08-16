
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
pii dp[109][10036];
int n;
int a[109],b[109];
pii compute(int pos,int wt);
int main(){
	std::ios::sync_with_stdio(false);
	int i,j;
	int sumi=0;
	cin>>n;
	rep(i,n){
		cin>>a[i];
		sumi+=a[i];

	}
	rep(i,n){
		cin>>b[i];
	}
	rep(i,n+3){
		rep(j,sumi+20){
			dp[i][j]=mp(-1,-1);
		}
	}
	pii ans=compute(0,sumi);

	cout<<ans.ff<<" "<<ans.ss<<endl;
}

pii compute(int pos,int wt){
	pii ans,value;
	if(wt<=0){
		ans=mp(0,0);
		return ans;
	}

	if(pos==n){
		ans=mp(200,100);
		return ans;
	}
	if(dp[pos][wt].ff!=-1)
		return dp[pos][wt];

	ans=compute(pos+1,wt);
	value=compute(pos+1,wt-b[pos]);
	value.ff++;
	value.ss+=min(b[pos]-a[pos],wt-a[pos]);
	dp[pos][wt]=min(ans,value);
	return dp[pos][wt];
}