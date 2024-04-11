
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
ll dp[5002][5002];
bool palin[5002][5002]={0};
int main(){
	//std::ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int n=s.length(),i,j;
	rep(i,n){
		dp[i][i]=1;
		palin[i][i]=1;
	}
	rep(i,n-1){
		if(s[i]==s[i+1]){
			dp[i][i+1]=3;
			palin[i][i+1]=1;
		}
		else{
			dp[i][i+1]=2;
			palin[i][i+1]=0;
		}
	}
	int len;
	f(len,2,n){
		rep(i,n){
			if(i+len>=n){
				break;
			}
			dp[i][i+len]=dp[i][i+len-1]+dp[i+1][i+len]-dp[i+1][i+len-1];
			if(s[i]==s[i+len] && palin[i+1][i+len-1]){
				palin[i][i+len]=1;
				dp[i][i+len]++;
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",dp[l-1][r-1]);
	}

}