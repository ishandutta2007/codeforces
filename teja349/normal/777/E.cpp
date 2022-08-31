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
ll maxim[312345]={0},seg[1234567]={0};
map<int,int> mapi;
struct total{

	int a;
	int b;
	int h;
}; 
total hanoi[123456];
int cmpew(total p,total q){
	//cout<<"sddsa";
	if(p.b!=q.b){
		return (p.b>q.b);
	}
	else{
		return (p.a>q.a);
	}

}

ll update(ll node,ll s,ll e,ll p,ll val){
	if(s==e){
		seg[node]=val;
		//cout<<val<<endl;
		return 0;
	}
	ll mid=(s+e)/2;
	if(p<=mid){
		update(2*node,s,mid,p,val);
	}
	else{
		update(2*node+1,mid+1,e,p,val);
	}
	seg[node]=max(seg[2*node],seg[2*node+1]);
	return 0;
}


ll query(ll node,ll s,ll e,ll l,ll r){
	if(l>e || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	ll mid=(s+e)/2;
	ll a=query(2*node,s,mid,l,r);
	ll b=query(2*node+1,mid+1,e,l,r);
	return max(a,b);


}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,aer,ber,her;
	cin>>n;
	rep(i,n){
		cin>>aer>>ber>>her;
		hanoi[i].a=aer;
		hanoi[i].b=ber;
		hanoi[i].h=her;
		mapi[aer]=0;
		mapi[ber]=0;

	}
	int counti=1;
	map<int,int>::iterator it;
	for(it=mapi.begin();it!=mapi.end();it++){
		it->ss=counti++;
	}
	rep(i,n){
		hanoi[i].a=mapi[hanoi[i].a];
		hanoi[i].b=mapi[hanoi[i].b];
	}
	sort(hanoi,hanoi+n,cmpew);
	rep(i,n){
		//cout<<seg[1]<<endl;
		ll val=query(1,0,200010,0,hanoi[i].b - 1);
		//cout<<val<<" "<<hanoi[i].b<<endl;
		val+=hanoi[i].h;

		if(maxim[hanoi[i].a]<val){
			maxim[hanoi[i].a]=val;
			update(1,0,200010,hanoi[i].a,val);
		}
	}
	cout<<seg[1]<<endl;




}