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
int pre[200],post[200],last;
string s[300];
int dp[200][200];
int n,m;
int preprocess(int j){
	pre[j]=0;
	post[j]=m+1;
	int i;
	rep(i,m+2){
		if(s[j][i]=='1'){
			pre[j]=i;
		}
	}
	fd(i,m+2-1,0){
		if(s[j][i]=='1'){
			post[j]=i;
		}
	}
	//cout<<j<<" "<<post[j]<<endl;
	post[j]=m+1-(post[j]);
	return 0;

}
int compute(int flo,int side){
	if(flo==last){
		if(side==1){
			return post[flo];
		}
		else
			return pre[flo];
	}
	if(dp[flo][side]!=0){
		return dp[flo][side];
	}
	if(side==1){
		dp[flo][side]=2*post[flo]+1+compute(flo+1,side);
		dp[flo][side]=min(dp[flo][side],m+2+compute(flo+1,side^1));
	}
	else{
		dp[flo][side]=2*pre[flo]+1+compute(flo+1,side);

		dp[flo][side]=min(dp[flo][side],m+2+compute(flo+1,side^1));
		//cout<<dp[flo][side]<<endl;
	}
	return dp[flo][side];

}
int main(){
    std::ios::sync_with_stdio(false);
	
	cin>>n>>m;
	int i;
	fd(i,n-1,0){
		cin>>s[i];
	}    
	rep(i,n){
		preprocess(i);
		if(pre[i]){
			last=i;
		}
	}

	cout<<compute(0,0)<<endl;
    //cout<<post[1]<<endl;
}