
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
vii remov;
int dsu[1234];
int root(int p){
	if(dsu[p]<0)
		return p;
	dsu[p]=root(dsu[p]);
	return dsu[p];
}

int merge(int p,int q){
	int p1=root(p);
	int q1=root(q);
			
	if(p1==q1){
		//cout<<"hii";
		remov.pb(mp(p,q));
	}
	else{

		if(dsu[p1]>dsu[q1]){
			dsu[p1]=q1;
		}
		else if(dsu[p1]<dsu[q1]){
			dsu[q1]=p1;
		}
		else{
			dsu[q1]=p1;
			dsu[p1]--;
		}
	}
	return 0;
}

int main(){
	fill(dsu,dsu+1005,-1);
	int i,u,v,n,val;
	cin>>n;
	rep(i,n-1){
		cin>>u>>v;
		u--;
		v--;
		merge(u,v);

	}
	//cout<<"hii"<<endl;
	set<int> set1;
	set<int>::iterator it,it1;
	rep(i,n){
		val=root(i);
		//cout<<dsu[1]<<endl;
		if(set1.find(val)==set1.end()){
			set1.insert(val);
		}
	}
	//cout<<"hiiii";

	cout<<remov.size()<<endl;
	it1=set1.begin();
	it1++;
	i=0;
	for(it=set1.begin();it1!=set1.end();it++,it1++){
		cout<<remov[i].ff+1<<" "<<remov[i].ss+1<<" "<<*it+1<<" "<<*it1+1<<endl;
		i++;
	}
	return 0;


}