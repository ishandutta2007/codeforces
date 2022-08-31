
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
#define N 1000100
//std::ios::sync_with_stdio(false);   
ll bit[2][1234567]={0};
int update(int index,int p,int val){
	while(p < N){
		bit[index][p]+=val;
		p+=p&(-p);
	}
	return 0;
}
ll query(int index,int p){
	ll sum=0;
	while(p>0){
		sum+=bit[index][p];
		p-=p&(-p);
	}
	return sum;
}
int counti=1;
map<int,int> mapi;
int a[1234567];
int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	rep(i,n){
		cin>>a[i];
		mapi[a[i]]=0;
	}
	map< int , int >::iterator it;
	for(it=mapi.begin();it!=mapi.end();it++){
		it->ss=counti++;
	}
	rep(i,n){
		a[i]=mapi[a[i]];
	}
	ll sum1=0;
	ll sum2=0;
	ll ans=0;
	rep(i,n){
		ll val=query(0,a[i]);
		val=sum1-val;
		update(0,a[i],1);
		sum1++;
		ll val1 = query(1,a[i]);
		update(1,a[i],val);
		
		ans+=sum2-val1;
		sum2+=val;
		//cout<<ans<<endl;

	}
	cout<<ans<<endl;



}