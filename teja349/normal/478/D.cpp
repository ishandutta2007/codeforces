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
int compute(int val){
	int low=1;
	int high=10000;
	int mid=(high+low)/2;
	int ans=0;
	while(low<=high){
		if(mid*(mid+1)/2<=val){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	return ans;
}
int dp[212345]={0};
int main(){
	std::ios::sync_with_stdio(false);
	int r,g;
	cin>>r>>g;
	int n=compute(r+g);
	//return 0;
	int diff=r+g-n*(n+1)/2;
	int p=min(r,g);
	int i,j;
	
	dp[0]=1;
	f(i,1,n+1){
		fd(j,p+3,0){
			if(j-i>=0){
				//if(i==1 && j==1)
					//cout<<"sasa"<<endl;
				dp[j]+=dp[j-i];
			}
			if(dp[j]>mod){
				dp[j]-=mod;
			}
		}
	}
	//cout<<dp[1]<<endl;
	ll sumi=0;
	rep(i,diff+1){
		if(p-i<0)
			break;
		sumi+=dp[p-i];
		if(sumi>mod){
			sumi-=mod;
		}
	}
	cout<<sumi<<endl;



}