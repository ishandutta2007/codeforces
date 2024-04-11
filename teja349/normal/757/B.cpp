
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
map<int ,int > mapi;
int p[123456]={0}; 
int used(int n);
int main(){
	int n;
	cin>>n;
	int i,j;
	
	map< int,int >::iterator it;
	for(i=2;i*i<100006;i++){
		if(p[i]!=0)
			continue;
		for(j=i*i;j<100005;j+=i){
			if(p[j]==0)
				p[j]=i;
		}
	}
	int a[123456];
	rep(i,n){
		cin>>a[i];

	}
	int maxi=1;
	rep(i,n){
		used(a[i]);
	}
	for(it=mapi.begin();it!=mapi.end();it++){
		maxi=max(maxi,it->ss);
	}
	cout<<maxi<<endl;

}

int used(int n){
	set<int> seti;
	set< int >::iterator it;
	if(n==1)
		return 0;
	int val=p[n];
	while(p[n]!=0){
		seti.insert(p[n]);
		n/=p[n];

	}
	seti.insert(n);
	for(it=seti.begin();it!=seti.end();it++){
		if(mapi.find(*it)==mapi.end()){
			mapi[*it]=1;
		}
		else{
			mapi[*it]++;
		}
	}

	return 0;


}