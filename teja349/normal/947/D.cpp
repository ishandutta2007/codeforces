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
int haha[123456],lol[123456],lastb[123456],bestb[123456];
int main(){
    std::ios::sync_with_stdio(false);
    string s,t;
    cin>>s>>t;
    int i,cnt1,cnt2,a,b,c,d;
    rep(i,s.length()){
    	if(s[i]=='B' || s[i]=='C'){
    		lastb[i+1]=i+1;
    		haha[i+1]=haha[i]+1;
    	}
    	else{
    		lastb[i+1]=lastb[i];
    	//lasta[i]
    		haha[i+1]=haha[i];
    	}
    }
    rep(i,t.length()){
    	if(t[i]=='B' || t[i]=='C'){
    		bestb[i+1]=i+1;
    		lol[i+1]=lol[i]+1;
    	}
    	else{
    		bestb[i+1]=bestb[i];
    		lol[i+1]=lol[i];
    	}
    }
    rep(i,s.length()){
    	
    }
    int q;
    cin>>q;
    int dist1,dist2;
    rep(i,q){
    	int a,b,c,d;
    	cin>>a>>b>>c>>d;
    	cnt1=haha[b]-haha[a-1];
    	cnt2=lol[d]-lol[c-1];
    	cnt2-=cnt1;
    	if(cnt2>0){
    		if(cnt2%2==1){
    			cout<<0;
    			continue;
    		}	
    		dist1=b-max(lastb[b],a-1);
    		dist2=d-max(bestb[d],c-1);
    		if(dist1>dist2){

    			cout<<1;
    		}
    		else if(cnt1!=0 && dist1==dist2){
    			cout<<1;
    		}
    		else{
    			cout<<0;
    		}
    	}
    	else if(cnt2==0){
    		dist1=b-max(lastb[b],a-1);
    		dist2=d-max(bestb[d],c-1);
    		if(dist1<dist2){
    			cout<<0;
    		}
    		else{
    			dist1-=dist2;
    			if(dist1%3==0){
    				cout<<1;
    			}
    			else{
    				cout<<0;
    			}

    		}

    	}
    	else{
    		cout<<0;
    	}
    }
    cout<<endl;
    return 0;
    return 0;  
    
}