
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
	string s;
	int i,arr[1000]={0},barr[1000]={0};
	cin>>s;
	rep(i,s.length()){
		arr[s[i]]++;
	}
	rep(i,s.length()){
		if(s[i]=='R'){
			barr[s[i]]=i%4;

		}
		if(s[i]=='B'){
			barr[s[i]]=i%4;
		}
		if(s[i]=='G'){
			barr[s[i]]=i%4;
		}
		if(s[i]=='Y'){
			barr[s[i]]=i%4;
		}


	}
	int n=(s.length()-1)/4;
	int val=(s.length()-1)%4;

	if(barr['R']<=val){
		cout<<n+1- arr['R']<<" ";
	}
	else{
		cout<<n-arr['R']<<" ";
	}
	if(barr['B']<=val){
		cout<<n+1- arr['B']<<" ";
	}
	else{
		cout<<n-arr['B']<<" ";
	}
	if(barr['Y']<=val){
		cout<<n+1- arr['Y']<<" ";
	}
	else{
		cout<<n-arr['Y']<<" ";
	}
	if(barr['G']<=val){
		cout<<n+1- arr['G']<<" ";
	}
	else{
		cout<<n-arr['G']<<" ";
	}
}