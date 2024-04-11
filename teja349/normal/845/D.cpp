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

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    stack<int> st1,st2;
    st1.push(10000);
    st2.push(1);
    int i,val;
    int counter=0,cursp;
    int t;
    rep(i,n){
    	
    	cin>>t;
    	if(t==1){
    		cin>>val;
    		while(st1.top()<val){
    			st1.pop();
    			counter++;
    		}
    		cursp=val;
    		
    	}
    	else if(t==2) {
    		while(!st2.top()){
    			st2.pop();
    			counter++;
    		}    		
    	}
    	else if(t==3){
    		cin>>val;
    		if(cursp>val){
    			counter++;
    		}
    		else{
    			st1.push(val);
    		}
    	}
    	else if(t==4){
    		st2.push(1);
    	}
    	else if(t==5){
    		st1.push(10000);
    	}
    	else{
    		st2.push(0);
    	}
    }
    cout<<counter<<endl;

    return 0;      

}