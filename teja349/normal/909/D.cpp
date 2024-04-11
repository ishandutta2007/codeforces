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
set<int> seti,set1,set2;
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int i,j;
    set<int>::iterator it1,it2,it;
    int n=s.length();
    rep(i,n){
    	seti.insert(i);
    }
    rep(i,n){
    	if(i!=n-1 && s[i]!=s[i+1]){
    		set1.insert(i);
    		seti.erase(i);
    	}
    	else if(i!=0 && s[i]!=s[i-1]){
    		set1.insert(i);
    		seti.erase(i);
    	}
    }
   // cout<<set1.size()<<endl;
    int counter=0;
    while(!set1.empty()){
    	counter++;
    	for(it=set1.begin();it!=set1.end();it++){
    		it1=seti.upper_bound(*it);
    		if(it1!=seti.begin() && it1!=seti.end()){
    			it2=it1;
    			it2--;
    			if(s[*it1]!=s[*it2]){
    				//cout<<
    				set2.insert(*it1);
    				set2.insert(*it2);
    			}
    		}
    	}
    	//cout<<set2.size()<<endl;
    	set1.clear();
    	for(it=set2.begin();it!=set2.end();it++){
    		set1.insert(*it);
    		seti.erase(*it);
    	}
    	set2.clear();
    }
    cout<<counter<<endl;
    return 0;  
    
}