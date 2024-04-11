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
int arr[12345];
int dp[1600][28],n;   
int precomp(int pos,int let){
	//cout<<"Sd";
	int extra=0;
	int ans=0;
	int i;
	//cout<<n<<endl;
	f(i,pos,n){
		if(arr[i]!=let){
			extra++;			
		}
		ans++;
		//cout<<extra<<" "<<ans<<endl;
		dp[extra][let]=max(dp[extra][let],ans);
	}
	return 0;

}
int main(){
    //std::ios::sync_with_stdio(false);
   // int n;
    cin>>n;
    string s;
    cin>>s;
    int i,j;
    rep(i,s.length()){
    	arr[i]=s[i]-'a';
    }
    rep(i,n){
    	rep(j,26){
    		precomp(i,j);
    	}

    }
   // precomp(1,'o'-'a');
    //cout<<dp[1]['o'-'a']<<endl;
    //return 0;
    int maxi=0;

    rep(j,26){
    	maxi=0;
    	rep(i,n+1){
    		maxi=max(maxi,dp[i][j]);
    		dp[i][j]=maxi;
    	}
    }
    int q;
    
    cin>>q;
    int val;
    char ch;
    rep(i,q){
    	scanf("%d %c",&val,&ch);
    	cout<<dp[val][ch-'a']<<endl;
    }

    
}