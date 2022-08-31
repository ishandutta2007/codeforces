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
int x[12345],y[12345];
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
    rep(i,8){
    	cin>>x[i]>>y[i];
    }
    int haha=0,lol=0;
    f(i,4,8){
    	haha+=x[i];
    	lol+=y[i];
    }
    haha/=4;
    lol/=4;
    rep(i,8){
    	x[i]-=haha;
    	y[i]-=lol;
    }
    int maa=-100000;
    int maxix=maa;
    int maxiy=maa;
    int minix= 1000000;
    int miniy = minix;
    f(i,4,8){
    	maa=max(maa,x[i]);
    }
    rep(i,4){
    	minix=min(minix,x[i]);
    	maxix=max(maxix,x[i]);
    	miniy=min(miniy,y[i]);
    	maxiy=max(maxiy,y[i]);
    }
    f(i,minix,maxix+1){
    	f(j,miniy,maxiy+1){
    		if(abs(i)+abs(j)<=maa){
    			cout<<"YES"<<endl;
    			return 0;
    		}
    	}
    }
    cout<<"NO"<<endl;
    return 0;  
    
}