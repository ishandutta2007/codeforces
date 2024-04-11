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
int arr[12345];
int s1[123456];
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    
    
    int i;
    rep(i,n){
    	s1[i]=s[i];
    }
    sort(s1,s1+n);
    rep(i,n){
    	if(s[i]!=s1[i]){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    	arr[s[i]-'a']++;
    }
    if(!arr[0] || !arr[1]){
    	cout<<"NO"<<endl;
    	return 0;
    }
    if(arr[0]==arr[2] || arr[1]==arr[2]){
    	cout<<"YES"<<endl;
    	return 0;
    }
    cout<<"NO"<<endl;
    return 0;  
    
}