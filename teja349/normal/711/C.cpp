
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
//std::ios::sync_with_stdio(false);   


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
ll c[200],arr[101][101];
ll dp[101][101][101];
int main(){
	ll n,m,k,i,j,p,q,mini=1,mini1;
	mini*=inf;
	mini*=inf;
	mini1=mini;
	cin>>n>>m>>k;
	rep(i,n){
		rep(j,m+1){
			rep(q,k+1){
				dp[i][q][j]=mini;
			}
		}
	}

	//cout<<endl<<dp[0][3][1]<<endl;
	rep(i,n){
		cin>>c[i];
	}
	rep(i,n){
		f(j,1,m+1){
			cin>>arr[i][j];
		}
	}
	if(c[0]!=0){
		dp[0][1][c[0]]=0;
	}
	else{
		f(j,1,m+1){
			dp[0][1][j]=arr[0][j];
		}
	}
	f(i,1,n){
		f(j,1,k+1){
			if(c[i]!=0){
				f(q,1,m+1){
					if(c[i]!=q)
						dp[i][j][c[i]]=min(dp[i-1][j-1][q],dp[i][j][c[i]]);
				}
				dp[i][j][c[i]]=min(dp[i-1][j][c[i]],dp[i][j][c[i]]);
				
			}
			else{
				f(p,1,m+1){
					c[i]=p;
					f(q,1,m+1){
						if(c[i]!=q)
							dp[i][j][c[i]]=min(dp[i-1][j-1][q]+arr[i][p],dp[i][j][c[i]]);
					}
					dp[i][j][c[i]]=min(dp[i-1][j][c[i]]+arr[i][p],dp[i][j][c[i]]);

					c[i]=0;
				}
				
			}
		}

			
	}
	
	f(i,1,m+1){
		//cout<<dp[n-1][k][i]<<endl;
		mini=min(dp[n-1][k][i],mini);
		//cout<<mini<<endl;
	}
	if(mini<mini1)
		cout<<mini<<endl;
	else
		cout<<-1<<endl;
}