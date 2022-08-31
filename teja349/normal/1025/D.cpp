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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
int compute1(int,int);
int visit2[712][712],dp2[712][712];
int a[712];
int gg[712][712];
int compute2(int l,int r){
	assert(l<=r);
	if(visit2[l][r])
		return dp2[l][r];
	visit2[l][r]=1;
	int ans=0;
	if(l==r){
		if(gg[l][l+1]!=1){
			dp2[l][r]=1;
			return 1;
		}
		else{
			dp2[l][r]=0;
			return 0;
		}
	}
	int i;
	f(i,l,r+1){
		if(gg[i][r+1]==1)
			continue;
		if(i==l){
   			if(compute1(i+1,r))
   				ans=1;
   		} 	
   		else if(i==r){
   			if(compute2(l,r-1))
   				ans=1;
   		}
   		else{
   			if(compute2(l,i-1)){
   				if(compute1(i+1,r))
   					ans=1;
   			}
   		}
   		if(ans==1)
   			break;
	}
	dp2[l][r]=ans;
	return ans;
}
int visit1[712][712],dp1[712][712];
int compute1(int l,int r){
	assert(l<=r);
	if(visit1[l][r])
		return dp1[l][r];
	visit1[l][r]=1;
	if(l==r){
		if(gg[l][l-1]!=1){
			dp1[l][r]=1;
			return 1;
		}
		else{
			dp1[l][r]=0;
			return 0;
		}
	}
	int i;
	int ans=0;
	f(i,l,r+1){
		if(gg[l-1][i]==1)
			continue;
		if(i==l){
   			if(compute1(i+1,r))
   				ans=1;
   		} 	
   		else if(i==r){
   			if(compute2(l,r-1))
   				ans=1;
   		}
   		else{
   			if(compute2(l,i-1)){
   				if(compute1(i+1,r))
   					ans=1;
   			}
   		}
   		if(ans==1)
   			break;
	}
	dp1[l][r]=ans;
	return ans;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n;
    //cin>>n;
    scanf("%d",&n);
    int i;
    rep(i,n){
    	scanf("%d",&a[i]);
    }
    int j;
    rep(i,n){
    	rep(j,n){
    		gg[i][j]=__gcd(a[i],a[j]);
    	}
    }
    int ans=0;
    rep(i,n){
   		if(i==0){
   			if(compute1(i+1,n-1))
   				ans=1;
   		} 	
   		else if(i==n-1){
   			if(compute2(0,i-1))
   				ans=1;
   		}
   		else{
   			if(compute2(0,i-1) && compute1(i+1,n-1)){
   				ans=1;
   			}
   		}
   		if(ans==1)
   			break;
    }

    if(ans){
    	cout<<"Yes";
    }
    else{
    	cout<<"No";
    }
    return 0;  
    
}