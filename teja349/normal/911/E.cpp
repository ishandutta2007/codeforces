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

//std::ios::sync_with_stdio(false);   
int a[212345],pres[212345],seg[812345];
int build(int node,int s,int e){
	if(s==e){
		seg[node]=a[s];
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=max(seg[2*node],seg[2*node+1]);
	return 0;
}
int query(int node,int s,int e,int l,int r){
	if(e<l || r<s)
		return 0;
	if(l<=s && e<=r)
		return seg[node];
	int mid=(s+e)/2;
	int aa=query(2*node,s,mid,l,r);
	int bb=query(2*node+1,mid+1,e,l,r);
	return max(aa,bb);
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,k,i,j;
    cin>>n>>k;
    f(i,1,k+1){
    	cin>>a[i];
    	pres[a[i]]=i;
    }
    stack<int> st;
    int foo=k+1,val;
    build(1,1,k);
    f(i,1,n){
    	if(pres[i] && pres[i+1]){
    		if(pres[i+1]<pres[i]){
    			val=query(1,1,k,pres[i+1],pres[i]);
    			if(val>i+1){
    				cout<<-1<<endl;
    				return 0;
    			}
    		}
    	}
		else if(pres[i]){
			continue;
		}
		else if(pres[i+1]){
			val=query(1,1,k,pres[i+1],k);
			if(val>i+1){
				cout<<-1<<endl;
				return 0;
			}
			st.push(i);
			while(!st.empty()){
				a[foo]=st.top();
				foo++;
				st.pop();
			}
		}
		else{
			st.push(i);
			//cout<<i<<endl;
		}
    	

    }
    if(!pres[n]){
    	st.push(n);
    }
    while(!st.empty()){
    	a[foo]=st.top();
    	foo++;
    	st.pop();
    }
    
    f(i,1,n+1){
    	cout<<a[i]<<" ";
    }
    return 0;  
    
}