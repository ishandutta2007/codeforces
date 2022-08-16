
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
ll a[1000*10000+7]={0},prib[1000*10000+7]={0},pribs[1000*10000+7]={0};

int decomp(int n){
	//cout<<"hii";
	//fflush(stdout);
	int val;
	while(a[n]!=0){
		 val=a[n];
		prib[val]++;
		while(a[n]==val){
			n/=val;
			
		}
	}
	if(n!=1&&n!=val){
		prib[n]++;
	}
	return 0;

}


int main(){
	std::ios::sync_with_stdio(false);  
	int i,j,l,r,m;
	for(i=2;i*i<=1000*10000+5;i++){
		if(a[i]!=0)
			continue;
		for(j=i*i;j<=1000*10000+5;j+=i){
			if(a[j]==0)
				a[j]=i;
		}
	}

	int n;
	cin>>n;
	
	rep(i,n){
		cin>>l;
	
		decomp(l);
	}
	
	f(i,1,1000*10000+4){
		pribs[i]=pribs[i-1]+prib[i];
	}

	cin>>m;
	//cout<<prib[2]<<endl;
	while(m--){
		cin>>l>>r;
		if(r>1000*10000+2)
			r=1000*10000+2;
		if(l>1000*10000+2)
			l=1000*10000+2;
		cout<<pribs[r]-pribs[l-1]<<endl;
	}
}