
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
ll c[123456],dp[123456][2];
string str[123456];
string reverse(string s){
	string s1="";
	int i;
	fd(i,s.length()-1,0){
		s1+=s[i];
	}
	return s1;
}
int main(){
	ll n,i;
	ll inff=inf;
	inff*=inf;
	cin>>n;
	rep(i,n){
		cin>>c[i];
	}
	rep(i,n){
		cin>>str[i];
	}
	dp[0][0]=0;
	dp[0][1]=c[0];
	string strrevp=reverse(str[0]);
	string strrev;
	f(i,1,n){
		strrev=reverse(str[i]);
		if(str[i-1]<=str[i]&&strrevp<=str[i]){
			dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
		}
		else{
			if(str[i-1]<=str[i]){
				dp[i][0]=dp[i-1][0];
			}
			else if(strrevp<=str[i]){
				dp[i][0]=dp[i-1][1];
			}
			else{
				dp[i][0]=inff;
			}
		}
		//str[i]=strrev;
		if(str[i-1]<=strrev&&strrevp<=strrev){
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+c[i];
		}
		else{
			if(str[i-1]<=strrev){
				dp[i][1]=dp[i-1][0]+c[i];
			}
			else if(strrevp<=strrev){
				dp[i][1]=dp[i-1][1]+c[i];
			}
			else{
				dp[i][1]=inff;
			}
		}
		strrevp=strrev;

	}
	ll ans=min(dp[n-1][0],dp[n-1][1]);
	if(ans>=inff)
		cout<<-1<<endl;
	else{
		cout<<ans<<endl;
	}
}