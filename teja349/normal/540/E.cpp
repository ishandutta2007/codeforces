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
vi vec,vec1;
int bit[312345];
ll calc(int pos,int elem){
	ll ans=0;
	if(pos<elem){
		ans=elem-pos;
		ans-=lower_bound(vec.begin(),vec.end(),elem)-lower_bound(vec.begin(),vec.end(),pos);

	}
	else{
		ans=elem-pos;
		ans-=lower_bound(vec.begin(),vec.end(),elem)-lower_bound(vec.begin(),vec.end(),pos);
		ans*=-1;
	}
	return ans;
}
int query(int pos){
	int sumi=0;
	while(pos>0){
		sumi+=bit[pos];
		pos-=pos&(-pos);
	}
	return sumi;
}
int update(int pos){
	while(pos<223456){
		bit[pos]++;
		pos+=pos&(-pos);
	}
	return 0;
}
int a[123456],b[123456];
map<int,int> elem,mapi;
map<int,int>::iterator it;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>a[i]>>b[i];
    	vec.pb(a[i]);
    	vec.pb(b[i]);
    	elem[a[i]]=a[i];
    	elem[b[i]]=b[i];
    }
    sort(vec.begin(),vec.end());
    int counter=1;
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    rep(i,n){
    	swap(elem[a[i]],elem[b[i]]);
    }
    ll sumi=0;
    for(it=elem.begin();it!=elem.end();it++){
    	sumi+=calc(it->ff,it->ss);
    	vec1.pb(it->ss);
    }
    rep(i,vec1.size()){
    	mapi[vec1[i]]=0;
    }
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    }
    rep(i,vec1.size()){
    	vec1[i]=mapi[vec1[i]];
    	sumi+=query(212345)-query(vec1[i]);
    	update(vec1[i]);
    }
    cout<<sumi<<endl;


    


    return 0;      

}