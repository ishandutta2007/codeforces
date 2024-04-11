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
int bit[2123456]; 
int bitquery(int val){
	int sum=0;
	while(val>0){
		sum+=bit[val];
		val-=val&(-val);
	}
	return sum;
}  
int bitupdate(int val,int va){
	//int sum=0;
	while(val<123456){
		bit[val]+=va;
		val+=val&(-val);
	}
	return 0;
}  
int query(int l ,int r){
	int val= bitquery(r)-bitquery(l-1);
	//cout<<val<<endl;
	return val;
}
int a[123456];
vector<vi> vec(123456);
int main(){
    std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i;
	map<int,int> mapi;
	int counter=0;
	map<int,int>::iterator itm;

	f(i,1,n+1){
		cin>>a[i];
		mapi[a[i]]=0;
	}     
	for(itm=mapi.begin();itm!=mapi.end();itm++){
		itm->ss=counter++;
	}
	f(i,1,n+1){
		a[i]=mapi[a[i]];
		vec[a[i]].pb(i);
		bitupdate(i,1);
	}
	//cout<<bitquery(10);
	vector<int>::iterator it,it1;
	ll pres=1,j;
	ll sum=0;
	rep(i,counter){
		it=lower_bound(vec[i].begin(),vec[i].end(),pres);
		if(it==vec[i].begin()){
			it1=vec[i].end();
			it1--;
			sum+=query(pres,*it1);
			pres=*it1;
		}
		else{
			
				sum+=query(pres,n+2);
			//pres=*it1;
			it--;

			//it1=vec[i].begin();
			sum+=query(0,*it);
			pres=*it;
		}
		rep(j,vec[i].size()){
			bitupdate(vec[i][j],-1);
		}


			

	}
	cout<<sum<<endl;

    
}