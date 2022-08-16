
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

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

set< int > set1;

int reduce(int val){
	while(set1.find(val)!=set1.end()){
		val=val/2;
	}
	return val;
}


int main(){
	int n,i,val;
	cin>>n;
	rep(i,n){
		cin>>val;
		set1.insert(val);
	}
	set<int>::iterator it;
	it=set1.end();
	it--;
	while(1){

		val=reduce(*it);
		if(val!=0){
			set1.erase(it);
			set1.insert(val);
			it=set1.end();
			it--;

		}
		else{
			
				break;
			it--;
		}
	}
	for(it=set1.begin();it!=set1.end();it++){
		cout<<*it<<" ";
	}
}