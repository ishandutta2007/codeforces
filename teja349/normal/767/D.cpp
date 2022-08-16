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
int n,m,k,flirt=0,accm[1000*10000+5]={0},preve[1000*10000+5];
int finder(int val){
	if(val==-1){
		return val;
	}
	if(accm[val]!=k){
		return val;
	}
	preve[val]=finder(preve[val]);
	return preve[val];
}
int filler(int val){
	if(accm[val]!=k){
		accm[val]++;
	}
	else{
		int value=finder(val);
		if(value==-1){
			if(!flirt){
				cout<<-1<<endl;
				exit(0);
			}
			else{
				//cout<<"guuu";
				return 1;
			}
		}
		accm[value]++;
	}
	return 0;
}
vi vec;
int main(){
	std::ios::sync_with_stdio(false);
	int i,val;
	cin>>n>>m>>k;
	rep(i,1000*10000+4){
		preve[i]=i-1;
	}
	rep(i,n){
		cin>>val;
		filler(val);
	}

	flirt=1;
	rep(i,m){
		cin>>val;
		//myshop.pb(mp(val,i+1));
		if(!filler(val))
			vec.pb(i+1);

	}
	cout<<vec.size()<<endl;
	
	//cout<<endl;
	rep(i,vec.size()){
		cout<<vec[i]<<" ";
	}
	return 0;



}