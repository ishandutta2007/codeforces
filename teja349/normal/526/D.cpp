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
int adder[1234567],pre[1234567];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    int i,l,r;
    l=0;
    r=0;
    string s;
    cin>>s;
    f(i,1,n){
    	if(r<i){
    		l=i;
    		r=i;
    		while(r<n && s[r]==s[r-l])
    			r++;
    		pre[i]=r-l;
    		r--;

    		continue;
    	}
    	if(r-i+1>pre[i-l]){
    		pre[i]=pre[i-l];
    	}
    	else{
    		l=i;
    		while(r<n && s[r]==s[r-l]) r++;
    		pre[i]=r-l;
    		r--;
    	}

    }
    ll haha,haha1,endp;
    f(i,1,n){
    	haha=k*i;
    	haha1=(k+1)*i;
    	endp=i+pre[i];
    	if(haha>endp)
    		continue;
    	haha1=min(haha1,n);
    	haha1=min(haha1,endp);
    	adder[haha]++;
    	adder[haha1+1]--;
    }
    if(k==1){
    	adder[n]++;
    }
    for(i=1;i<=n;i++){
    	adder[i]+=adder[i-1];
    	if(adder[i])
    		cout<<1;
    	else
    		cout<<0;
    }
    return 0;  
    
}