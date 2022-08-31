
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
#define inf (1000*1000*10+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll a[5005];
ll dper[5005][5005]={0};
//int visit[5005][5005]={0};
ll dp[5005]={0};
ll n,m,k;
ll inff;
ll compute(int p,int left){
	if(left==0)
		return 0;
	if(p>n-k)
		return -1*inff;
	if(dper[p][left]!= -1 )
		return dper[p][left];
	//visit[p][left]=1;
	dper[p][left]=max(compute(p+1,left),compute(p+k,left-1)+dp[p]);
	return dper[p][left];
}

int main(){
	int i,j;
	inff=inf;
	inff*=inf;
	cin>>n>>k>>m;
	rep(i,n+2){
		rep(j,m+1){
			dper[i][j]=-1;
		}
	}
	rep(i,n){
		cin>>a[i];
	}
	rep(i,k){
		dp[0]+=a[i];
	}
	f(i,1,n-k+1){
		dp[i]=dp[i-1]+a[i+k-1]-a[i-1];
	}
	rep(i,n){
	//	cout<<dp[i]<< " endl   ";
	}
	cout<<compute(0,m)<<endl;
}