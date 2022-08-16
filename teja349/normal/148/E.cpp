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
int num[200],ans[200][200],shl[150][150],dp[12345]={0},dp1[12345];
int compute(int ind){
	int i,j;
	rep(i,200){
		ans[ind][i]=inf;
	}
	int sum=0,bigs=0;
	rep(i,num[ind]){
		sum=0;
		bigs+=shl[ind][i];
		f(j,i,num[ind]){
			sum+=shl[ind][j];
			//if(j-i+1)
			ans[ind][num[ind]-(j-i+1)]=min(ans[ind][num[ind]-(j-i+1)],sum);
		}
		
	}
	ans[ind][num[ind]]=bigs;
	rep(i,num[ind]){
		ans[ind][i]=bigs-ans[ind][i];
		//cout<<ans[ind][i]<<"   "<<i<<endl;
	}



	return 0;


}

int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int i,j,k;
	rep(i,n){
		cin>>num[i];
		rep(j,num[i]){
			cin>>shl[i][j];
		}
		compute(i);
	}
	rep(i,n){
		rep(j,m+1){
			rep(k,min(num[i]+1,j+1)){
				dp1[j]=max(dp1[j],dp[j-k]+ans[i][k]);
			}
		}
		rep(j,m+1){
			dp[j]=dp1[j];
			dp1[j]=0;
		}
	}
	cout<<dp[m]<<endl;


}