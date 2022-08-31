
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
//std::ios::sync_with_stdio(false);   


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



int construct(int n,int h,int d);
int constrt(int n,int h);


int main(){
	int n,h,d;
	cin>>n>>d>>h;

	if(d>2*h){
		cout<<-1<<endl;
		return 0;
	}
	if(h<d){
		construct(n,h,d);
		return 0;
	}
	if(h==d){
		 if(h==1){
		 	if(n==2){
		 		cout<<1<<" "<<2<<endl;
		 		return 0;
		 	}
		 	else{
		 		cout<<-1<<endl;
		 		return 0;
		 	}
		 }
		 constrt(n,h);
	}


}


int constrt(int n,int h){
	int i,j,k,flag;
	f(i,2,h+2){

		cout<<i-1<<" "<<i<<endl;
	}
	while(i<=n){
		cout<<2<<" "<<i<<endl;
		i++;
	}
	
}




int construct(int n,int h,int d){
	int i;
	f(i,2,h+2){
		cout<<i-1<<" "<<i<<endl;
	}
	cout<<1<<" "<<h+2<<endl;
	f(i,h+3,h+2+d-h){
		cout<<i-1<<" "<<i<<endl;
	}
	f(i,h+2+d-h,n+1){
		cout<<1<<" "<<i<<endl;
	}
}