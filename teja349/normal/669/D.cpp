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
int a[1234567]; 
int fir=1;
int sec=2,n;
int update1(int val){
	fir+=val;
	while(fir>n)
		fir-=n;
	while(fir<=0)
		fir+=n;
	sec+=val;
	while(sec>n)
		sec-=n;
	while(sec<=0)
		sec+=n;
	return 0;
}
int update2(){
	if(fir%2)
		fir++;
	else
		fir--;
	if(sec%2)
		sec++;
	else
		sec--;
}
int main(){
    //std::ios::sync_with_stdio(false);
	int q;
	cin>>n>>q;
	int t,val;
	while(q--){

		scanf("%d",&t);
		if(t==1){
			scanf("%d",&val);
			update1(val);
		}
		else{
			update2();
		}	
	}
	int i,odd=1;
	while(odd<=n){
		a[fir]=odd;
		fir+=2;
		if(fir>n)
			fir-=n;
		odd+=2;
	}
	//eve=2;
	odd=2;
	fir=sec;
	while(odd<=n){
		a[fir]=odd;
		fir+=2;
		if(fir>n)
			fir-=n;
		odd+=2;
	}
	f(i,1,n+1){
		printf("%d ",a[i]);
	}



    
}