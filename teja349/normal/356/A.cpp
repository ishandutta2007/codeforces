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

int seg[312345*4]={0},arr[312345]={0};
set<int> seti;
set<int>:: iterator it1,it2,it;
int n;
int build(int node,int s,int e){
	if(s==e){
		arr[s]=node;
		//cout<<s<<"   d   "<<node<<endl;
		seg[s]=0;
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return 0;

}




int update(int node,int s,int e,int p,int val){
	if(s==e){
		seg[node]=val;
		return 0;
	}
	int mid=(s+e)/2;
	if(p<=mid){
		update(2*node,s,mid,p,val);
	}
	else{
		update(2*node+1,mid+1,e,p,val);
	}
	seg[node]=min(seg[2*node],seg[2*node+1]);
	return 0;
}  




int query(int node,int s,int e,int l,int r){
	if(l<=s && e<=r){
		return seg[node];
	}
	if(e<l || r<s){
		return inf;
	}
	int mid=(s+e)/2;
	int a=query(2*node,s,mid,l,r);
	int b=query(2*node+1,mid+1,e,l,r);
	return min(a,b);
}


int updaterange(int l,int r,int c){
	it1=seti.lower_bound(l);
	it2=seti.upper_bound(r);
	while(it1!=seti.end()){
		if(*it1 <=r){
			arr[*it1]=c;
			
			seti.erase(it1);

		}
		else{
			break;
		}
	it1=seti.lower_bound(l);
	}

	seti.insert(c);
	return 0;
}




int main(){
	std::ios::sync_with_stdio(false);
	int m,l,r,c,i;
	cin>>n>>m;
	f(i,1,n+1){
		seti.insert(i);
	}
	//build(1,1,n);
	while(m--){
		cin>>l>>r>>c;
		updaterange(l,r,c);
		
		
		//cout<<c<<"  "<<seg[arr[c]]<<endl;
	}
	//int i;
	f(i,1,n+1){
		if(seti.count(i))
			cout<<0<<" ";
		else
			cout<<arr[i]<<" ";
	}

}