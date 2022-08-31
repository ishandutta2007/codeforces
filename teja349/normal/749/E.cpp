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
ll bit[123456]={0},a[123456];
ll update(ll pos,ll val){
	while(pos<112345){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
ll query(ll pos){
	ll sumi=0;
	while(pos>0){
		sumi+=bit[pos];
		pos-=pos&(-pos);
	}
	return sumi;
}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,i;
	cin>>n;
	double nn=n,ans=0,sumi=0,sumi1=0,sumi2=0;
	nn*=1.00;
	f(i,1,n+1){
		cin>>a[i];
	}
	double total=nn*(nn+1);
	total/=2;
	
	f(i,1,n+1){
		ans=(nn-i)*(nn-i+1);
		ans/=4.00;
		ans/=total;
		ans*=(i*1.00);
		sumi+=ans;

	}

	//cout<<sumi<<endl;

	f(i,1,n+1){
		ans=query(100005)-query(a[i]);

		update(a[i],1);
		sumi1+=ans;
	}
	//cout<<sumi1<<endl;
	sumi+=(sumi1/(nn+1))*(nn-1);
	sumi+=(2*sumi1/(nn+1));
	rep(i,123456){
		bit[i]=0;
	}
	f(i,1,n+1){
		ans=query(100005)-query(a[i]);
		ans*=1.0;
		ans/=total;
		update(a[i],i);
		sumi2+=ans*(nn-i+1);
	}
	//cout<<sumi2<<endl;
	sumi-=sumi2;

	cout << setprecision (20) <<sumi<< endl;


	


}