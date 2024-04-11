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
ll a[12345],dp1[12345],dp2[12345],rem[12345],rem2[12345];
ll ans,haha,pre[12345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    f(i,1,n+1){
    	cin>>a[i];
    	
    	pre[i]=pre[i-1]+a[i];
    }
    dp1[0]=0;
    rem[0]=1;
    f(i,1,n+1){
    	dp1[i]=-pre[i];//+pre[i-1];
    	rem[i]=1;
    	f(j,1,i+1){
    		if(dp1[i]<2*pre[j]-pre[i]){
    			rem[i]=j+1;
    			dp1[i]=2*pre[j]-pre[i];
    		}
    	}
    }
    dp2[n+1]=0;
    rem2[n+1]=n+1;
    fd(i,n,1){
    	dp2[i]=-pre[n]+pre[i-1];
    	rem2[i]=i;
    	f(j,i,n+1){
    		if(dp2[i]<pre[j]-pre[i-1]-pre[n]+pre[j]){
    			rem2[i]=j+1;
    			dp2[i]=pre[j]-pre[i-1]-pre[n]+pre[j];
    		}
    	}
    }
    haha=1;
    ans=-1*inf;
    ans*=inf;
    rep(i,n+1){
    	if(ans<dp1[i]+dp2[i+1]){
    		ans=dp1[i]+dp2[i+1];
    		haha=i+1;
    	}


    }
    //cout<<rem[1]<<endl;
    cout<<rem[haha-1]-1<<" "<<haha-1<<" "<<rem2[haha]-1<<endl;


    return 0;  
    
}