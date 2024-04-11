
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
	int a,b;
	cin>>a>>b;
	int ans12=0,ans22=0,ans13=0,ans23=0,ans15=0,ans25=0;
	while(a%2==0){
		ans12++;
		a/=2;
	}
	while(b%2==0){
		ans22++;
		b/=2;
	}

	while(a%3==0){
		ans13++;
		a/=3;
	}
	while(b%3==0){
		ans23++;
		b/=3;
	}
	while(a%5==0){
		ans15++;
		a/=5;
	}
	while(b%5==0){
		ans25++;
		b/=5;
	}
	if(a!=b){
		cout<<-1;
		return 0;
	}
	cout<<abs(ans12-ans22)+abs(ans13-ans23)+abs(ans15-ans25);


}