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
vi vec1,vec2;
int a[12345],b[12345],haha[12345],lol[12345];
int check(int n){
	int i;
	rep(i,n){
		if(a[i]!=b[i]){
			//cout<<a[i]<<" "<<b[i]<<endl;
			return 0;
		}
	}
	rep(i,n){
		cout<<a[i]<<" ";
	}
	exit(0);
}
int main(){
    std::ios::sync_with_stdio(false);
	int n,i,j;
	cin>>n;
	int rem1,rem2,buff1,buff2;
	rep(i,n){
		cin>>a[i];
		haha[a[i]]++;
	}    
	rep(i,n){
		cin>>b[i];
		lol[b[i]]++;
	}
	f(i,1,n+1){
		if(haha[i]==2){
			rem1=i;
		}
		if(haha[i]==0){
			buff1=i;
		}
	}
	f(i,1,n+1){
		if(lol[i]==2){
			rem2=i;
		}
		if(lol[i]==0){
			buff2=i;
		}
	}
	rep(i,n){
		if(a[i]==rem1){

			vec1.pb(i);
		}
		if(b[i]==rem2){
			//cout<<i<<endl;
			vec2.pb(i);
		}
	}
	//cout<<rem2<<" "<<buff2<<endl;
	rep(i,vec1.size()){
		rep(j,vec2.size()){
			//cout<<"sdaa";
			a[vec1[i]]=buff1;
			b[vec2[j]]=buff2;
			check(n);
			a[vec1[i]]=rem1;
			b[vec2[j]]=rem2;
		}
	}
	return 0;


    
}