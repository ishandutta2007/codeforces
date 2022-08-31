
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
ll count(int n,int k);
int main(){
	int n,k,d;
	cin>>n>>k>>d;
	ll ans1=count(n,k);
	ll ans2=count(n,d-1);
	cout<<(ans1-ans2+mod)%mod<<endl;

}
ll count(int n,int k){
	ll dp[200],sum=0,i;
	dp[0]=1;
	sum=dp[0];
	f(i,1,k+1){

		dp[i]=sum;

		sum+=dp[i];
		sum%=mod;
	}
	//cout<<dp[1]<<endl;
	f(i,k+1,n+1){
		sum-=dp[i-k-1];
		sum+=mod;
		sum%=mod;
		dp[i]=sum;
		sum+=dp[i];
		sum%=mod;
		//cout<<i<<"   "<<dp[i];
	}
	return dp[n];
}