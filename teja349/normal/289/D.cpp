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
int sumi=0;
int n,k;
vi vec;
int reach(int pos){
	int steps=0;
	while(steps!=20){
		if(pos==-1){
			return 1;
		}
		steps++;
		pos=vec[pos];
	}
	return 0;
} 
int check(){
	int i;
	rep(i,k){
		if(!reach(i)){
			return 0;
		}
	}
	//cout<<"yo"<<endl;
	sumi++;
	return 0;
}
int compute(){
	if(vec.size()==k){
		check();
		return 0;
	}
	int i;
	rep(i,k){
		vec.pb(i);
		compute();
		vec.erase(vec.end()-1);
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    
    int i,j;
    ll haha=0;
    ll val;
    cin>>n>>k;
    f(i,1,k+1){
    	//cout<<"boo"<<endl;
    	vec.clear();
    	rep(j,i){
    		vec.pb(-1);
    	}
    	sumi=0;
    	val=1;
    	f(j,1,k){
    		val*=j;
    	}
    	f(j,1,k-i+1){
    		val/=j;
    	}
    	//val/=i;
    	val%=mod;
    	compute();
    	haha+=(val*sumi)%mod;
    }
    //cout<<haha<<endl;
   	rep(i,n-k){
   		haha*=(n-k);
   		haha%=mod;
   	}
   	cout<<haha<<endl;
}