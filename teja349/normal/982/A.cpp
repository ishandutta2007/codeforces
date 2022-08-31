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

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i;
    rep(i,n-1){
    	if(s[i]=='1' && s[i+1]=='1'){
    		cout<<"No"<<endl;
    		return 0;
    	}
    }
    if(n>=2){
    	if(s[0]=='0' && s[1]=='0')
    	{
    		cout<<"No"<<endl;
    		return 0;
    	}
    	if(s[n-2]=='0' && s[n-1]=='0'){
    		cout<<"No"<<endl;
    		return 0;	
    	}
    }
    else if(s[0]=='0'){
    	cout<<"No"<<endl;
    		return 0;
    }
    rep(i,n-2){
    	if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0'){
    		cout<<"No"<<endl;
    		return 0;
    	}
    }
    cout<<"Yes"<<endl;
    return 0;  
    
}