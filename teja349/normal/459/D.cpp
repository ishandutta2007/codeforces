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
#define inf (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
struct total{
	int type;
	int index;
	int num;
};
vector< total > query;
int a[1234567],bite[1234567]={0};

ll bigans=0;
int comp(total a,total b ){
	if(a.num!=b.num){
		return (a.num<b.num);
	}
	return (a.type<b.type);
}

int update(int i){
	bigans++;
	while(i<inf){
		bite[i]++;
		i+=i&(-i);

	}
	return 0;
}

ll querybit(int i){
	ll sumi=0;
	while(i>0){
		sumi+=bite[i];
		i-=i&(-i);
	}
	return sumi;
}
map<ll , ll > mapi;
int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	total value;
	value.type=1;
	int haha;
	rep(i,n){
		mapi[a[i]]++;
		haha=mapi[a[i]];
		value.index=i;
		value.num=haha;
		query.pb(value);
	}
	mapi.clear();
	value.type=2;
	fd(i,n-1,0){
		mapi[a[i]]++;
		haha=mapi[a[i]];
		value.index=i;
		value.num=haha;
		query.pb(value);

	}
	ll sumi=0;
	sort(query.begin(),query.end(),comp);
	rep(i,query.size()){
	//	cout<<query[i].num<<"  "<<query[i].type<<"   "<<query[i].num<<endl;
		if(query[i].type==1){
			sumi+=bigans-querybit(query[i].index + 1);
			//cout<<querybit(query[i].index + 1)<<endl;
		}
		else{
			update(query[i].index + 1);
			//cout<<"asddsa"<<endl;
		}

	}
	cout<<sumi<<endl;

}