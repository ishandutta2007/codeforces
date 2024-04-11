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
 
 
int a[123456],b[123456],arr[1234];
int sig(int val){
	if(val<0)
		return 0;
	else if(val>0)
		return 1;
	else
		return 2;
}
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i;
		//int pos=0,zero=0,neg=0;
		arr[0]=0;
		arr[1]=0;
		arr[2]=0;
		rep(i,n){
			cin>>a[i];
		}
		rep(i,n){
			cin>>b[i];
		}
		int flag=1;
		arr[2]=1;
		rep(i,n){
				
			if(arr[sig(b[i]-a[i])]==0){
				flag=0;
			}
			arr[sig(a[i])]=1;
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}