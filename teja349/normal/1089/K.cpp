//raja1999
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
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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

#define int ll
//std::ios::sync_with_stdio(false);
int st[1500005],lazy[1500005],bit[500005],c=0,inv[1000005],t[300005],d[300005],id[300005];
char ch[300005];
map<int,int>mapi;
int iinf=inf;
map<int,int>::iterator it;
// int update(int pos,int s,int e,int node,int val){
// 	if(s>pos||e<pos){
// 		return 0;
// 	}
// 	if(s==e){
// 		st[node]=val;
// 		return 0;
// 	}
// 	int mid=(s+e)/2;
// 	update(pos,s,mid,2*node,val);
// 	update(pos,mid+1,e,2*node+1,val);
// 	st[node]=max(st[2*node],st[2*node+1]);
// 	return 0;
// }
int range(int l,int r,int s,int e,int node,int val){
	
	if(lazy[node]!=0){
		st[node]+=lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=s&&r>=e){
		st[node]+=val;
		if(s!=e){
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		lazy[node]=0;
		return 0;
	}
	if(l>r)
		return 0;
	if(l>e||r<s){
		return 0;
	}
	int mid=(s+e)/2;
	range(l,r,s,mid,2*node,val);
	range(l,r,mid+1,e,2*node+1,val);
	st[node]=max(st[2*node],st[2*node+1]);
	return 0;
}
int query(int s,int e,int node,int l,int r){
	if(l>e||r<s){
		return -1LL*iinf;
	}
	if(lazy[node]!=0){
		st[node]+=lazy[node];
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=s&&r>=e){	
		return st[node];
	}
	int mid=(s+e)/2;
	int a=query(s,mid,2*node,l,r);
	int b1=query(mid+1,e,2*node+1,l,r);
	int ans=max(a,b1);
	//cout<<ans<<endl;
	return ans;
}
int bitupdate(int pos,int val){
	while(pos<c+10){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
}
int bitquery(int pos){
	int res=0;
	while(pos>0){
		res+=bit[pos];
		pos-=pos&(-pos);
	}
	return res;
}
signed main(){
	std::ios::sync_with_stdio(false);
	int t1;
	//cin>>t;
	t1=1;
	while(t1--){
		int q,i,val,ans,val1;
		// vl v;
		iinf*=inf;
		cin>>q;
		rep(i,q){
			cin>>ch[i];
			if(ch[i]=='+'){
				cin>>t[i]>>d[i];
				mapi[t[i]]=1;
				// v.pb(i);
			}
			else if(ch[i]=='-'){
				cin>>id[i];
			}
			else if(ch[i]=='?'){
				cin>>t[i];
				mapi[t[i]]=1;
			}
		}
		c=1;
		for(it=mapi.begin();it!=mapi.end();it++){
			inv[it->ff]=c;
			c++;
		}
		c--;
		rep(i,q){
			if(ch[i]=='+'){
				bitupdate(inv[t[i]],d[i]);
				val=bitquery(c)-bitquery(inv[t[i]]);
				int gg=query(1,c,1,inv[t[i]],inv[t[i]]);
				range(inv[t[i]],inv[t[i]],1,c,1,-1*gg);
				range(inv[t[i]],inv[t[i]],1,c,1,t[i]+val+d[i]);
				range(1,inv[t[i]]-1,1,c,1,d[i]);
			}
			else if(ch[i]=='-'){
				val=id[i]-1;
				bitupdate(inv[t[val]],-1*d[val]);
				int gg=query(1,c,1,inv[t[val]],inv[t[val]]);
				range(inv[t[val]],inv[t[val]],1,c,1,-1*gg);
				range(1,inv[t[val]]-1,1,c,1,-1*d[val]);
			}
			else{
				val=query(1,c,1,1,inv[t[i]]);
				//cout<<val<<endl;
				val1=bitquery(c)-bitquery(inv[t[i]]);
				val-=val1;
				//cout<<val<<endl;
				ans=max(val,t[i]);
				cout<<ans-t[i]<<endl;
			}
		}
	}
}