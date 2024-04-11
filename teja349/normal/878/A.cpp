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
int haha[512345],lol[512345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,ans=0,zer=0,on=0,val1=0,val2=0,val3=0;
    char ch;
    rep(i,n){
    	cin>>ch>>haha[i];
    	if(ch=='^')
    		lol[i]=0;
    	else if(ch=='|')
    		lol[i]=1;
    	else
    		lol[i]=2;
    }
    ans=0;
    rep(i,n){
    	if(lol[i]==0)
    		ans^=haha[i];
    	else if(lol[i]==1)
    		ans|=haha[i];
    	else
    		ans&=haha[i];
    }
    zer=ans;
    ans=(1<<10)-1;
   rep(i,n){
    	if(lol[i]==0)
    		ans^=haha[i];
    	else if(lol[i]==1)
    		ans|=haha[i];
    	else
    		ans&=haha[i];
    }
    on=ans;
    rep(i,10){
    	if(zer&(1<<i)){
    		if(on&(1<<i)){
    			val1+=(1<<i);
    			val2+=(1<<i);
    			val3+=(1<<i);

    		}
    		else{
    			val1+=(1<<i);
    			//val2+=(1<<i);
    			val3+=(1<<i);
    		}
    	}
    	else{
    		if(on&(1<<i)){
    			//val1+=(1<<i);
    			//val2+=(1<<i);
    			val3+=(1<<i);

    		}
    		else{
    			val1+=(1<<i);
    			val2+=(1<<i);
    			//val3+=(1<<i);
    		}
    	}
    }
    cout<<3<<endl;
    cout<<"^ "<<val1<<endl;
    cout<<"| "<<val2<<endl;
    cout<<"& "<<val3<<endl;
    return 0;  
    
}