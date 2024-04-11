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
int n,k;
multiset<int> seti;
multiset<int>::iterator it,it1;   
int check(){
	if(seti.empty())
		return 1;
	it=seti.begin();
	it1=seti.end();
	it1--;
	if(*it1-*it<=k){
		//cout<<*it1<<" "<<*it<<endl;
		return 1;
	}
	return 0;
}
int a[123456],ans[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    cin>>n>>k;
    rep(i,n){
    	cin>>a[i];
    }
    i=0;
    int j=0;
    int maxi=0,cnt=0;
    rep(i,n){
    	while(j<n && check()){
    		
    		seti.insert(a[j]);
    		j++;
    	}
    	//cout<<j<<" dsd"<<check()<<endl;
    	if(check()) ans[i]=j-1;
    	else
    		ans[i]=j-2;
    	seti.erase(seti.find(a[i]));
    	maxi=max(maxi,ans[i]-i);
    }
    cout<<maxi+1<<" ";
    rep(i,n){
    	if(ans[i]-i==maxi)
    		cnt++;
    }
    cout<<cnt<<endl;
    rep(i,n)
    {
    	if(ans[i]-i==maxi)
    		cout<<i+1<<" "<<ans[i]+1<<endl;
    }
    return 0;


    return 0;  
    
}