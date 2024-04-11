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
ll lol[1234],dp[1234][1234];
vl vec;
int getbits(int val){
	int haha=0;
	while(val>0){
		if(val%2)
			haha++;
		val/=2;
	}
	return haha;
}
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int k,i,j;
    ll ans=0;
    cin>>k;
    if(k==0){
    	cout<<1<<endl;
    	return 0;
    }
    k--;
    lol[1]=0;
    f(i,2,1100){
    	lol[i]=lol[getbits(i)]+1;
    }
    //cout<<lol[2]<<endl;
    f(i,1,1100){
    	if(lol[i]==k){
    		vec.pb(i);
    	}
    }

    rep(i,1100){
    	dp[i][0]=1;
    }
    f(i,1,1200){
    	f(j,1,i+1){
    		dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    		dp[i][j]%=mod;
    	}
    }
    //cout<<dp[6][3]<<endl;
    int left=0,found=0,n=s.length();
    rep(i,s.length()){
    	if(s[i]=='0'){
    		continue;
    	}
    	left=n-i-1;
    	rep(j,vec.size()){
    		if(vec[j]>=found){
    			//cout<<vec[j]<<endl;
    			ans+=dp[left][vec[j]-found];
    			ans%=mod;
    		}
    	}
    	//cout<<left<<endl;
    	found++;
    	//cout<<ans<<endl;
    }
    if(lol[found]==k){
    	ans++;
    }
    if(k==0){
    	ans--;
    }
    ans+=mod;
    ans%=mod;
    ans%=mod;
    cout<<ans<<endl;




    return 0;  
    
}