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
int a[1234];
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int prev=0,l=0,r;
    int i,flag=0;
    rep(i,s.length()){
    	if(s[i]==','){
    		a[prev]=1;
    		prev=0;
    	}
    	else{
    		prev*=10;
    		prev+=s[i]-'0';
    	}
    }
    a[prev]=1;
    f(i,1,1234){
    	
    	if(a[i]==1 && l!=0){
    		continue;
    	}
    	else if(a[i]==0 && l!=0){
    		r=i-1;
    		if(l==r){
    			cout<<l;
    		}
    		else{
    			cout<<l<<"-"<<r;
    		}
    		l=0;
    	}
    	else if(a[i]==1 && l==0){
    		l=i;
    		if(!flag){
    			flag=1;
    			
    		}
    		else{
    			cout<<",";
    		}
    	}
    	else{
    		continue;
    	}

    }
    cout<<endl;
    return 0;

    
}