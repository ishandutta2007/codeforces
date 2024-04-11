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
	std::ios::sync_with_stdio(false);
	int k,i,j;
	cin>>k;
	if(k%2==0){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	if(k==1){
		cout<<"2"<<" "<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	cout<<2*(2*k+1)<<" "<<k*(2*k+1)<<endl;
	f(i,1,(k-1)/2+1){
		f(j,k+1,2*k+1){
			if(i!=j-k){
				cout<<i<<" "<<j<<endl;
				cout<<i+2*k<<" "<<j+2*k<<endl;

			}
		}
		cout<<i<<" "<<4*k+1<<endl;
		cout<<i+k<<" "<<4*k+1<<endl;
		cout<<i+2*k<<" "<<4*k+2<<endl;
		cout<<i+3*k<<" "<<4*k+2<<endl;
	}
	cout<<4*k+1<<" "<<4*k+2<<endl;
	f(i,(k-1)/2+1,k+1){
		f(j,k+1,2*k+1){
			
				cout<<i<<" "<<j<<endl;
				cout<<i+2*k<<" "<<j+2*k<<endl;

			
		}
	}
}