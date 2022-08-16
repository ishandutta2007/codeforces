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

int n,a[123456],p[123456],dp[123456];
int compute(int pos){
	dp[pos]=1;
	if(a[pos]==n){
		
		return dp[pos];
	}
	else if(p[a[pos]+1]>pos){
		dp[pos]+=compute(p[a[pos]+1]);

	}
	return dp[pos];


}
int main(){
    std::ios::sync_with_stdio(false);
    //int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i];
    	p[a[i]]=i;
    }
    int maxi=0;
    rep(i,n){
    	if(dp[i]==0){
    		maxi=max(maxi,compute(i));
    	}

    }
    cout<<n-maxi<<endl;

    
}