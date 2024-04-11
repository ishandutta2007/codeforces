// teja349
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


//helper functions
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

set<int> seti;
int a[12345],b[12345];
int factoriz(int val){
	int i,ans=0;
	for(i=2;i*i<=val;i++){
		while(val%i==0){
			if(seti.find(i)!=seti.end()){
				//cout<<"dasad";
				ans--;
			}
			else{
				ans++;
			}
			val/=i;
		}
	}
	if(val==1){
		return ans;
	}

	if(seti.find(val)!=seti.end()){
		ans--;
	}
	else{
		ans++;
	}
	return ans;

	//return ans;
}
int dp[12345],gc[12345];
int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	int i,j,sum=0,val;
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	gc[0]=a[0];
	f(i,1,n){
		gc[i]=__gcd(gc[i-1],a[i]);
	}
	rep(i,m){
		cin>>b[i];
		seti.insert(b[i]);
	}
	rep(i,n){
		sum+=factoriz(a[i]);
		//cout<<a[i]<<" "<<factoriz(a[i])<<endl;
	}
	int haha=0;
	rep(i,n){
		haha=factoriz(gc[i]);
		dp[i]=(i+1)*haha;
		rep(j,i){
			dp[i]=min(dp[i],dp[j]+(i-j)*haha);
		}	
	}
	val=0;
	rep(i,n){
		val=min(dp[i],val);
	}
	cout<<sum-val<<endl;
	return 0;  
}