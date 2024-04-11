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
ll dp[2123][2123];
int compute(int i,int j){
	
	if(i==j){
		dp[i][j] = dp[i][j-1];
		return dp[i][j];
	}
	else{
		dp[i][j]=dp[i-1][j];
		dp[i][j]%=mod;
		if(j!=0){
			dp[i][j]+=dp[i][j-1];
			dp[i][j]%=mod;
		}	
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    if(n%2){
    	cout<<0<<endl;
    	return 0;
    }
    string s;
    cin>>s;
    int a=0;
    int b=0;
    int rem=0;
    int i,j,left,jojo,lol=0;
    rep(i,s.length()){
    	if(s[i]==')')
    		b++;
    	else
    		a++;
    	//cout<<b<<" "<<a<<endl;
    	rem=max(rem,b-a);
    	lol=max(lol,a-b);
    }
    if(b>n/2 || a>n/2){
    	cout<<0<<endl;
    	return 0;
    }
    dp[0][0]=1;
    f(i,1,2010){
    	rep(j,i+1){
    		compute(i,j);
    	}
    }
    //cout<<rem<<endl;
    int here=a-b;
    ll ans=0;

    f(i,rem,2001){
    	left=n-m-i;
		if(left<0)
		{
			break;
		}
		//cout<<i<<endl;
    	f(j,rem,2001){
    		if(i%2!=j%2)
    			continue;
    		if(i<j)
    			continue;
    		jojo=here+j;
    		if(jojo>left)
    			continue;
    		ans+=dp[(i+j)/2][(i-j)/2]*dp[(left+jojo)/2][(left-jojo)/2];
    		ans%=mod;
    	}
    }
    cout<<ans<<endl;
    return 0;  
    
}