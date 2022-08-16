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
    int n,a,b;
    cin>>n>>a>>b;

    string s;
    cin>>s;
    int cnt=0;
    int a1=a;
    int b1=b;
    int i;
    rep(i,n){
    	if(s[i]=='*'){
    		if(cnt%2){
    			if(a>b)
    				a--;
    			else
    				b--;

    		}
    		a-=cnt/2;
    		b-=cnt/2;
    		cnt=0;
    	}
    	else{
    		cnt++;
    	}
    }
    if(cnt%2){
    			if(a>b)
    				a--;
    			else
    				b--;

    		}
    		a-=cnt/2;
    		b-=cnt/2;
   	a1-=max(a,0);
   	a1+=b1-max(b,0);
   	cout<<a1<<endl;
    return 0;  
    
}