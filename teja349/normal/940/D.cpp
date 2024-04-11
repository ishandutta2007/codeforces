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
#define inf (1000*1000*1000)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll a[123456],b[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    ll lmax=-inf,rmax=-inf,lmin=inf,rmin=inf;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    string s;
    cin>>s;
    rep(i,n){
    	b[i]=s[i]-'0';
    }
    f(i,4,n){
    	if(b[i]!=b[i-1]){
    		if(b[i]==1){
    			rep(j,5){
    				lmax=max(lmax,a[i-j]+1);
    			}
    		}
    		else{
    			rep(j,5){
    				rmin=min(rmin,a[i-j]-1);
    			}
    		}
    	}
    	else{
    		continue;
    		// flag=0;
    		// rep(j,5){
    		// 	if(b[i]!=b[i-j])
    		// 		flag=1;
    		// }
    		// if(flag)
    		// 	continue;
    		// rep(j,5){
    		// 	maxi=max(maxi,a[i-j]);
    		// 	mini=min(mini,a[i-j]);
    		// }
    		// lmin=min(lmin,maxi);
    		// rmax=max(rmax,mini);
    		
    	}
    }
    cout<<lmax<<" "<<rmin<<endl;
    // if(lmax<=lmin && rmax<=rmin){

    // }
    return 0;  
    
}