
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
ll a[20];
string s;
ll mini=inf;
ll ind;  
ll compute(ll v);
int main(){
	ll v,i;
	cin>>v;
	rep(i,9){
		cin>>a[i];
		if(a[i]<=mini){
			mini=a[i];
			ind=i;
		}
	}
	compute(v);

	if(s==""){
		cout<<-1<<endl;
	}
	else{
		cout<<s<<endl;
	}


}
ll compute(ll v){
	ll counti=v/mini;
	if(counti==0)
		return 0;
	ll i;
	//if(v==2)
		//cout<<"hghii";
	fd(i,8,ind){
		if((v-a[i]) >= (counti-1)*mini)
			break;
	}
	s+=char(i+48+1);
	compute(v-a[i]);
	return 0;
}