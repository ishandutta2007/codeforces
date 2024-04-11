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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
 

int a[123456],b[123456];
int getsteps(int val){
	//cout<<val<<endl;
	int gg=0;
	while(val){
		gg++;
		val/=2;
	}
	return gg;
} 
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int i,n;
		cin>>n;
		rep(i,n){
			cin>>a[i];
		}
		b[0]=a[0];
		int maxi=0;
		f(i,1,n){
			b[i]=max(a[i],b[i-1]);
		}
		f(i,1,n){
			maxi=max(maxi,b[i]-a[i]);
		}
		cout<<getsteps(maxi)<<endl;
	}
}