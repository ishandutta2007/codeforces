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
int haha[1234];
int main(){
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int i,j;
    rep(i,s.length()){
    	haha[s[i]]=1;
    }
    if(k>s.length()){
    	cout<<s;
    	rep(i,1000){
    		if(haha[i])
    			break;
    	}
    	f(j,n,k){
    		cout<<(char)i;
    	}
    	return 0;
    }
    rep(i,1000){
    	if(haha[i])
    		break;
    }
    int lol=i;
    int val;
    rep(i,1000){
    	if(haha[i]){
    		val=i;
    	}
    }
    string t=s;
    fd(i,k-1,0){
    	if(s[i]!=val){
    		f(j,s[i]+1,1000){
    			if(haha[j])
    				break;
    		}
    		t[i]=(char)j;
    		break;
    	}
    	else{
    		t[i]=(char)lol;
    	}

    }
    rep(i,k){
    	cout<<t[i];
    }
    return 0;  
    
}