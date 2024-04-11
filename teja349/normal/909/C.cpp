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
vl vec;
ll wow[12345],dp[5123][5123];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,i=0,ans=1,j,val;

    cin>>n;
    char ch,prev='s';
    rep(i,n){
    	cin>>ch;
    	if(ch=='f')
    		wow[i]=1;
    }
    // while(n!=0){
    // 	cin>>ch;
    // 	n--;
    // 	if(ch=='s'){
    // 		if(prev=='f'){
    // 			prev=ch;
    // 			continue;
    // 		}
    // 		else
    // 			i++;
    // 	}
    // 	else{
    // 		if(prev!='f'){
    // 			vec.pb(i);
    // 			i++;
    // 		}

    // 	}
    // 	prev=ch;

    // }
    // n=i;
    //cout<<n<<endl;
    rep(j,vec.size()){
    	wow[vec[j]]=1;
    }
    rep(i,n+10){
    	dp[n-1][i]=1;
    }
    fd(i,n-2,0){
    	val=0;
    	ans=0;
    	if(wow[i]){
    		ans=dp[i+1][0];
    		val=1;
    	}

    	rep(j,n+10){
    		ans+=dp[i+1][j+val];
    		if(val==1)
    			ans=dp[i+1][j+val];
    		ans%=mod;
    		dp[i][j]=ans;

    	}
    }
    cout<<dp[0][0]<<endl;
    
}