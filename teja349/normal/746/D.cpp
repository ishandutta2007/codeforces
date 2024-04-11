	
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

//std::ios::sync_with_stdio(false);   
int main(){
	ll n,k,a,b,i;
	cin>>n>>k>>a>>b;
	if(a>b){
		ll val=a/k;
		if(a>(b+1)*k){
			cout<<"NO";
			return 0;
		}
		while(!(a>k*b)&&a!=0&&b!=0){
			cout<<"GB";
			a--;
			b--;
		}
		while(a>=k){
			rep(i,k){
				cout<<"G";
			}
			a-=k;
			if(b!=0){
				cout<<"B";
				b--;
			}
		}
		rep(i,a){
			cout<<"G";
		}


	}
	else{
		swap(a,b);
		//int val=a/k;
		if(a>(b+1)*k){
			cout<<"NO";
			return 0;
		}
		while(!(a>k*b)&&a!=0&&b!=0){
			cout<<"BG";
			a--;
			b--;
		}
		while(a>k&&b!=0){
			rep(i,k){
				cout<<"B";
			}
			a-=k;
			if(b!=0){
				cout<<"G";
				b--;
			}
		}
		//cout<<a<<endl;
		rep(i,a){
			cout<<"B";
		}
		cout<<endl;

	}
		

}