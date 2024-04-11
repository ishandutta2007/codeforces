
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
int dsu[100000];
int root(int p){
	if(dsu[p]<0)
		return p;
	dsu[p]=root(dsu[p]);
	return dsu[p];
}  
int merge(int p,int q){
	p=root(p);
	q=root(q);
	if(p==q)
		return 0;
	if(dsu[p]<dsu[q]){
		dsu[p]=dsu[p]+dsu[q];
		dsu[q]=p;
	}
	else{
		dsu[q]=dsu[p]+dsu[q];
		dsu[p]=q;
	}
	return 0;
}
int main(){
	fill(dsu,dsu+100000,-1);
	vi vec;
	vi::iterator it;
	int n,m,k,i,u,v,val,sum=0,ans=0,spec[100000]={0};
	cin>>n>>m>>k;
	rep(i,k){
		cin>>u;
		u--;
		spec[u]=1;
	}
	rep(i,m){
		cin>>u>>v;
		u--;
		v--;
		merge(u,v);
	}
	//cout<<"hii";
	rep(i,n){
		if(spec[i]==1){
			val=root(i);
			vec.pb(((-1)*dsu[val]));
			sum+=((-1)*dsu[val]);
		}
	}
	sum=n-sum;
	
	//cout<<sum<<"DSads";
	fflush(stdout);
	it=max_element(vec.begin(),vec.end());
	*it=*it + sum;
	rep(i,vec.size()){
		val=vec[i];
		//cout<<val<<endl;
		ans+=(val*(val-1))/2;
	}
	cout<<ans-m<<endl;
}