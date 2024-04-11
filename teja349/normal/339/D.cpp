
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
//std::ios::sync_with_stdio(false);   


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

ll a[200000],seg[800000];
int make_tree(int node,int s,int e){
	//int flag;
	if(s==e){
		seg[node]=a[s];
		return 0;
	}
	int mid=(s+e)/2;
	int flag = make_tree(2*node,s,mid);
	make_tree(2*node+1,mid+1,e);
	if(flag==0){
		seg[node]=seg[2*node]|seg[2*node+1];
		flag=1;
	}
	else{
		seg[node]=seg[2*node]^seg[2*node+1];
		flag=0;
	}
	return flag;

}

int update(int node,int s,int e,int pos,int val){
	int flag;
	if(s==e)
	{
		seg[node]=val;
		return 0;
	}
	int mid=(s+e)/2;
	if(mid<pos){
		flag = update(2*node+1,mid+1,e,pos,val);
	}
	else{
		flag = update(2*node,s,mid,pos,val);
	}
	if(flag==0){
		seg[node]=seg[2*node]|seg[2*node+1];
		flag=1;
	}
	else{
		seg[node]=seg[2*node]^seg[2*node+1];
		flag=0;
	}
	return flag;


}



int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,p,q;
	cin>>n>>m;
	rep(i,1<<n){
		cin>>a[i];
	}
	ll val=1<<n;
	make_tree(1,0,val-1);
	while(m--){
		cin>>p>>q;
		update(1,0,val-1,p-1,q);
		cout<<seg[1]<<endl;
	}
}