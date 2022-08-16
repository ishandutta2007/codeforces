
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
int a[1000*10000+7]={0};



int update(int n,int val);
int compute(int n);

map<int,int> mapi;
int main(){
	std::ios::sync_with_stdio(false);   
	int i,j;
	for(i=2;i*i<1000*10000+5;i++){
		if(a[i]!=0)
			continue;
		for(j=i*i;j<=1000*10000+5;j+=i){
			if(a[j]==0)
				a[j]=i;
		}
	}

	int t;
	//cin>>t;
	t=1;
	while(t--){
		mapi.clear();
		int b[123456];
		int n;
		cin>>n;
		int maxi=0;
		rep(i,n){
			cin>>b[i];
		}
		rep(i,n){
			int val;
			if(a[i]==1)
				val=0;
			else
				val=compute(b[i]);
			val++;
			//cout<<val<<endl;
			maxi=max(maxi,val);
			update(b[i],val);
		}
		cout<<maxi<<endl;
	}
}


int update(int n,int val){

	while(a[n]!=0){
		
			
				mapi[a[n]]=val;
		

		n/=a[n];
	}
	if(n!=1){
		
			mapi[n]=val;
		
	}
	return 0;
}
int compute(int n){
	int maxi=0;
	//cout<<n<<"  ";
	while(a[n]!=0){
		if(mapi.find(a[n])!=mapi.end()){
			if(maxi<mapi[a[n]])
				maxi=mapi[a[n]];
		}

		n/=a[n];
	}
	if(n!=1){
		if(mapi.find(n)!=mapi.end()){
			if(maxi<mapi[n])
				maxi=mapi[n];
		}
	}
	//cout<<maxi<<endl;
	return maxi;
}