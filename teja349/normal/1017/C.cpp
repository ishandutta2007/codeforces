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
int p[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int mini=n+1;
    int i,j,val=1,seq;
    f(i,1,n+1){
    	seq=(n+i-1)/i;
    	//cout<<i<<" "<<seq<<endl;
    	if(seq+i<mini){
    		mini=seq+i;
    		val=i;
    	}
    }
    seq=(n+val-1)/val;
    //cout<<val<<endl;
   int k=1;
    f(i,1,seq+1){
    	//cout<<i<<endl;
    	f(j,n-i*val,n-(i-1)*val){
    		if(j>=0){
    			p[j]=k++;
    		}
    	}
    }
    rep(i,n){
    	cout<<p[i]<<" ";
    }
    return 0;     
}