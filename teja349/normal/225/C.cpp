//raja1999
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
int x,y;
string a[1234];
int ans[1234],dp[1234][2],pre[1234],n;
int compute(int m,int ty){
	if(m==0)
		return 0;
	if(m<0)
		return inf;
	if(dp[m][ty]!=-1)
		return dp[m][ty];
	int i,ans=inf;
	f(i,x,y+1){
		if(m-i<0)
			break;
		if(ty==0)
			ans=min(pre[m]-pre[m-i]+compute(m-i,1),ans);
		else
			ans=min(i*n-(pre[m]-pre[m-i])+compute(m-i,0),ans);
	}
	dp[m][ty]=ans;
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	int m;
	cin>>n>>m>>x>>y;
	int i,j;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,m){
		dp[i][0]=-1;
		dp[i][1]=-1;

		rep(j,n){
			if(a[j][i]=='#')
				ans[i]++;
				
		}
		pre[i+1]=pre[i]+ans[i];
		

	}
	int ans=inf;
	f(i,x,y+1){
		if(m-i<0)
			break;
		ans=min(pre[m]-pre[m-i]+compute(m-i,1),ans);
		ans=min((i)*n-(pre[m]-pre[m-i])+compute(m-i,0),ans);
		//cout<<m-i<<" "<<compute(m-i,0)<<endl;
	}
	cout<<ans<<endl;
}