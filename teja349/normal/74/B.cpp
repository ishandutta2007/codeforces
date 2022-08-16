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
    int n,m,k,i,move;
    string s;
    cin>>n>>m>>k;
    cin>>s;
    cin>>s;
    if(s[0]=='h'){
    	move=-1;
    }
    else{
    	move=1;
    }
    cin>>s;
    rep(i,s.length()){
    	if(s[i]=='0'){
    		if(m<k){
    			if(m!=1){
    				m--;
    			}

    		}
    		else{
    			if(m!=n)
    				m++;
    		}
    		k+=move;
    		if(k==n || k==1){
    			move*=-1;
    		}


    	}
    	else{
    		k+=move;
    		if(k==n || k==1){
    			move*=-1;
    		}
    		if(k==n){
    			m=1;
    		}
    		else if(k==1){
    			m=n;
    		}
    		else{
    			if(move==-1){
    				m=n;
    			}
    			else{
    				m=1;
    			}
    		}
    	}
    	if(m==k){
    		cout<<"Controller "<<i+1<<endl;
    		return 0;
    	}

    }
    cout<<"Stowaway"<<endl;
}