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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<int,int> mapi;
int a[12345],l[12345],r[12345];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    map<int,int>::iterator it;
    rep(i,n){
    	cin>>l[i];
    	
    }
    rep(i,n){
    	cin>>r[i];
    	mapi[l[i]+r[i]]++;
    }
    int counter=0;
    int j;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    }
    rep(i,n){
    	//cout<<l[i]+r[i]<<" ";
    	a[i]=n-mapi[l[i]+r[i]];
    	//cout<<a[i]<<endl;
    }
    rep(i,n){
    	rep(j,i){
    		if(a[j]>a[i]){
    			l[i]--;
    		}
    	}
    	f(j,i+1,n){
    		if(a[j]>a[i])
    			r[i]--;
    	}
    	if(l[i]||r[i])
    	{
    		cout<<"NO"<<endl;
    		return 0;
    	}
    }
    cout<<"YES"<<endl;
    rep(i,n){
    	cout<<a[i]<<" ";
    }


    return 0;   
}