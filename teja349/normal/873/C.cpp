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
int a[200][200],haha[200][200];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int i,j;
    f(i,1,n+1){
    	f(j,1,m+1){
    		cin>>a[i][j];
    	}
    }
    f(j,1,m+1){
    	f(i,1,n+1){
    		haha[i][j]=haha[i-1][j]+a[i][j];
    	}
    }
    int ans=0,lol=0,tot=0,rem=0,gg=0,val;
    f(j,1,m+1){
    	ans=0,lol=0;
    	rem=0;
    	f(i,1,n+1){
    		if(!a[i][j])
    			continue;
    		val=haha[min(i+k-1,n)][j]-haha[i-1][j];
    		//cout<<val<<" "<<rem<<endl;
    		if(val>ans){
    			ans=val;
    			rem=lol;
    		}
    		if(a[i][j])
    			lol++;
    	}
    	//cout<<"dadsd";
    	tot+=ans;
    	gg+=rem;
    }
    cout<<tot<<" "<<gg<<endl;

    return 0;  
    
}