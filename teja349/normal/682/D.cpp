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

#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
int inf=(1000+5);
//std::ios::sync_with_stdio(false);   
int dp[1011][1011][15][2];
string s,t;
int n,m,k;
int compute(int a,int b,int c,int lol){
	if(c<0){
		//cout<<"Ut"<<endl;
		return -1*inf;
	}
	
	if(a==n || b==m){
		
		if(c==0)
			return 0;
		else
			return -1*inf;
		//cout<<"boo"<<endl;
	}
	if(dp[a][b][c][lol]!=-1)
		return dp[a][b][c][lol];
	//cout<<c<<endl;
	dp[a][b][c][lol]=0;
	if(lol==0){
		if(s[a]==t[b]){
			//cout<<a<<" "<<b<<endl; 	

			dp[a][b][c][lol]=max(dp[a][b][c][lol],1+compute(a+1,b+1,c-1,1));
			//	cout<<compute(a+1,b+1,c-1,1)<<endl;
		}
		else{
			dp[a][b][c][lol]=0;
		}
		dp[a][b][c][lol]=max(dp[a][b][c][lol],compute(a,b+1,c,0));
		//cout<<compute(a+1,b,c,0)<<endl;
		dp[a][b][c][lol]=max(dp[a][b][c][lol],compute(a+1,b,c,0));

	}
	else{
		if(s[a]==t[b]){
		//	cout<<a<<" "<<b<<endl;
			dp[a][b][c][lol]=max(dp[a][b][c][lol],1+compute(a+1,b+1,c,1));
			dp[a][b][c][lol]=max(dp[a][b][c][lol],compute(a,b,c,0));

		}
		else{
			dp[a][b][c][lol]=0;
		}
		dp[a][b][c][lol]=max(dp[a][b][c][lol],compute(a,b+1,c,0));
		dp[a][b][c][lol]=max(dp[a][b][c][lol],compute(a+1,b,c,0));
	}
	return dp[a][b][c][lol];


}
int main(){
	std::ios::sync_with_stdio(false);

	cin>>n>>m>>k;
	cin>>s>>t;
	int i,j,h,p;
	rep(i,n+2){
		rep(j,m+2){
			rep(h,k+2){
				rep(p,2){
					dp[i][j][h][p]=-1;
				}
			}
		}
	}

	//cout<<"bd"<<endl;

	rep(i,n){
		rep(j,m){
			rep(h,k+1){
				rep(p,2){
					//cout<<i<<" "<<j<<" "<<h<<" "<<p<<" "<<compute(i,j,h,p)<<endl;
				}
			}
		}
	}
	cout<<compute(0,0,k,0)<<endl;
	
}