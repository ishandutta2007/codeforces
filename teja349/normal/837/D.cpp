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
int haha[1234],lol[1234];
int dp[205][205*40]; 

int comp2(ll val){
	int ans=0;
	while(val%2==0){
		ans++;
		val/=2;
	}
	return ans;
}
int comp5(ll val){
	int ans=0;
	while(val%5==0){
		ans++;
		val/=5;
	}
	return ans;
}
ll a[1234];
int main(){
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i,j,p;
    rep(i,n){
    	cin>>a[i];
    	haha[i]=comp5(a[i]);
    	lol[i]=comp2(a[i]);
    }
    rep(j,k+1){
		rep(p,30*n){
			dp[j][p]=-inf;
		}
	}
	dp[0][0]=0;
    rep(i,n){
    	fd(j,k-1,0){
    		rep(p,29*n){
    			dp[j+1][p+haha[i]]=max(dp[j+1][p+haha[i]],lol[i]+dp[j][p]);
    		}
    	}
    }
    int mini=0;
    rep(p,29*n){
    	mini=max(min(p,dp[k][p]),mini);
    }
    cout<<mini<<endl;

    
    return 0;      

}