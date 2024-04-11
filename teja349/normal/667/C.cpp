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
int n,dp[12345][10]={0};
set<string> seti;
set<string>::iterator it;
string s;
int compute(int pos,int len){
	int flag=0;
	if(pos==n )
		return 1;
	if(pos==n-1)
		return 0;
	if(pos==n-2){
		if(len==0 || len==3){
			seti.insert(s.substr(pos,2));
			return 1;
		}
		else if(len==2){
			if(s.substr(pos-2,2)!=s.substr(pos,2)){
				seti.insert(s.substr(pos,2));
				return 1;
			}
			return 0;
		}
	}
	if(dp[pos][len]==3){
		return 0;
	}
	else if(dp[pos][len]==1){
		return 1;
	}
	dp[pos][len]=3;
	if(len==0){
		if(compute(pos+2,2)){
			seti.insert(s.substr(pos,2));
			flag=1;
		}
		if(compute(pos+3,3)){
			flag=1;
		 	seti.insert(s.substr(pos,3));
		}
		if(flag){
			dp[pos][len]=1;
			return 1;
		}
		
		
	}
	else if(len==2){
		if(compute(pos+3,3)){
			 seti.insert(s.substr(pos,3));
			 flag=1;
		}
		if(s.substr(pos-2,2)!=s.substr(pos,2)){
			if(compute(pos+2,2)){
				seti.insert(s.substr(pos,2));
				flag=1;
			}
		}
		if(flag){
			dp[pos][len]=1;
			return 1;
		}
	}
	else if(len==3){
		if(compute(pos+2,2)){
				seti.insert(s.substr(pos,2));
				flag=1;
		}
		if(s.substr(pos-3,3)!=s.substr(pos,3)){
			if(compute(pos+3,3)){
				 seti.insert(s.substr(pos,3));
				 flag=1;
			}
		}
		if(flag){
			dp[pos][len]=1;
			return 1;
		}
	}
	return 0;

}
int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>s;
	n=s.length();
	int i;
	f(i,5,n){
		compute(i,0);
	}
	cout<<seti.size()<<endl;
	for(it=seti.begin();it!=seti.end();it++){
		cout<<*it<<endl;
	}

}