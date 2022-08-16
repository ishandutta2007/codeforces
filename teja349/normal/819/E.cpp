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
vector<vi> vec;  
int add(int p,int q,int r){
	vec.pb({3,p,q,r});
} 

int add(int p,int q,int r,int s){
	vec.pb({4,p,q,r,s});
} 

int solve(int val){
	int n=val;
	if(val==3){
		add(1,2,3);
		add(1,2,3);
		return 0;
	}
	else if(val==4){
		add(1,2,3,4);
		add(1,2,4,3);
		add(1,4,2,3);
		return 0;
	}
	solve(n-2);
	int i;
	f(i,1,n-2){
		add(i,n,i+1,n-1);
	}
	add(n-1,n,n-2);
	add(n-1,n,1);
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	solve(n);
	int i,j;
	cout<<vec.size()<<endl;
	rep(i,vec.size()){
		rep(j,vec[i].size()){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}	
    
}