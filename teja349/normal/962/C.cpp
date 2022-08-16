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
int mini=1000,tot=0;
//std::ios::sync_with_stdio(false);   
int check(ll val,ll wow){
	int rem=0;
	while(val>0 && wow>0){
		if(wow%10==val%10){
			wow/=10;
			rem++;
		}
		val/=10;
	}
	if(wow==0){
		mini=min(mini,tot-rem);
		
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll i=n;
    while(i>0){
    	tot++;
    	i/=10;
    }
    f(i,1,123456){
    	check(n,i*i);
    }
    if(mini==1000)
    	cout<<-1<<endl;
    else
    	cout<<mini<<endl;
    return 0;  
    
}