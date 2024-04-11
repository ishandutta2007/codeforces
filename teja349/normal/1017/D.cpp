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
int a[523456]; 
int dp[(1<<6)+3][(1<<6)+3][612];
int w[123];
int lower[(1<<6)+10],upper[12345];
int converttonum(string s){
	int i,ans=0;
	rep(i,s.length()){
		ans*=2;
		ans+=s[i]-'0';
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,q,i;
    int j,k;
    cin>>n>>m>>q;
    f(i,12-n,12){
    	cin>>w[i];
    	//cout<<"das"<<endl;
    }

    int val,value;
    val=(1<<6);
    value=val-1;
    string str;
    int goo,boo;
    rep(i,val){
    	rep(j,6){
    		if(i&(1<<j)){
    			upper[i]+=w[5-j];
    		}
    	}
    	rep(j,6){
    		if(i&(1<<j)){
    			lower[i]+=w[6+5-j];
    		}
    	}
    	
    }

    rep(j,m){
    	cin>>str;
    	a[j]=converttonum(str);
    	boo=a[j]%val;
    	goo=a[j]/val;
    	rep(i,val){
    		dp[goo][i][lower[(i^boo)^value]]++;
    	}
    }
    
    rep(i,val){
    	rep(j,val){
    		f(k,1,602){
    			dp[i][j][k]+=dp[i][j][k-1];
    		}
    	}
    }
    int haha,gg,ans=0;
    //cout<<q<<endl;
    rep(i,q){
    	ans=0;
    	cin>>str>>k;
    	haha=converttonum(str);
    	goo=haha/val;
    	boo=haha%val;
    	rep(j,(1<<6)){
    		gg=upper[(goo^j)^value];
    		gg=k-gg;
    		if(gg>601){
    			ans+=dp[j][boo][601];
    		}
    		else if(gg>=0){
    			ans+=dp[j][boo][gg];
    		}
    	}
    	cout<<ans<<endl;
    }

    return 0;     
}