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
struct total{
	int t,d,p,ind;
};
total arr[1234];
int dp[123][2123],taken[123][2123];
int comp(total a,total b){
	return a.d<b.d;
}
int compute(int pos,int maxi){
	if(maxi<=0){
		return -inf;
	}
	if(pos==-1){
		return 0;
	}
	if(taken[pos][maxi]){
		return dp[pos][maxi];
	}
	int ans1=compute(pos-1,maxi);
	int val=min(maxi,arr[pos].d);

	int ans2=compute(pos-1,val-arr[pos].t);
	ans2+=arr[pos].p;
	if(ans1>ans2){
		dp[pos][maxi]=ans1;
		taken[pos][maxi]=2;
	}
	else{
		dp[pos][maxi]=ans2;
		taken[pos][maxi]=1;
	}
	//cout<<pos<<" "<<maxi<<dp[pos][maxi]<<endl;
	return dp[pos][maxi];
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>arr[i].t>>arr[i].d>>arr[i].p;
    	arr[i].ind=i+1;
    }
    sort(arr,arr+n,comp);
    compute(n-1,arr[n-1].d);
    cout<<dp[n-1][arr[n-1].d]<<endl;
    int lol=n-1;
    int maxi=arr[n-1].d;
    int val=0;
    vi vec;
    while(lol>=0){
    	if(taken[lol][maxi]==2){
    		lol--;
    	}
    	else{
    		vec.pb(arr[lol].ind);
    		val=min(maxi,arr[lol].d);
    		maxi=val-arr[lol].t;
    		lol--;
    	}
    }
    cout<<vec.size()<<endl;
    fd(i,vec.size()-1,0){
    	cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;  
    
}