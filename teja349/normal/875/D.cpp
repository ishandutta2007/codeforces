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
ll seg[812345];
ll a[212345];

int build(int node,int s,int e){
	if(s==e){
		seg[node]=a[s];
		return 0;
	}
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	seg[node]=seg[node*2]|seg[2*node+1];
	return 0;
}
ll query(int node,int s,int e,int l,int r){
	if(e<l || r<s)
		return 0;
	if(l<=s && e<=r)
		return seg[node];
	int mid=(s+e)/2;
	ll a=query(2*node,s,mid,l,r);
	ll b=query(2*node+1,mid+1,e,l,r);
	return a|b;
}
int getleft(int node,int s,int e,int l,int r){
	int mid;
	int ans=r;
	int lol=r;
	while(l<=r){
		mid=(l+r)/2;
		if(query(node,s,e,mid,lol)==a[lol]){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}
int getrig(int node,int s,int e,int l,int r){
	int mid;
	int ans=l;
	int lol=l;
	while(l<=r){
		mid=(l+r)/2;
		if(query(node,s,e,lol,mid)==a[lol]){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
int nexti[212345],previ[212345],nextior[212345],previor[212345];
int main(){
   // std::ios::sync_with_stdio(false);
    ll n;
    //cin>>n;
    scanf("%lld",&n);
    int i;
    rep(i,n){
    	//cin>>a[i];
    	scanf("%lld",&a[i]);
    }
    build(1,0,n-1);
    stack<int> st;
    i=0;
    while(i<n){
    	while(!st.empty()){
    		if(a[st.top()]<a[i])
    		{
    			nexti[st.top()]=i;
    			st.pop();
    		}
    		else{
    			break;
    		}
    	}
    	st.push(i);
    	i++;
    }
    while(!st.empty()){
    	nexti[st.top()]=n;
    	st.pop();
    }
    i=0;
    while(i<n){
    	while(!st.empty()){
    		if((a[st.top()]|a[i])!=a[st.top()])
    		{
    			nextior[st.top()]=i;
    			st.pop();
    		}
    		else{
    			break;
    		}
    	}
    	st.push(i);
    	i++;
    }
    while(!st.empty()){
    	nextior[st.top()]=n;
    	st.pop();
    }
    i=n-1;
    while(i>=0){
    	while(!st.empty()){
    		if((a[st.top()]|a[i])!=a[st.top()])
    		{
    			previor[st.top()]=i;
    			st.pop();
    		}
    		else{
    			break;
    		}
    	}
    	st.push(i);
    	i--;
    }

    while(!st.empty()){
    	previor[st.top()]=-1;
    	st.pop();
    }
    i=n-1;
    while(i>=0){
    	while(!st.empty()){
    		if(a[st.top()]<=a[i])
    		{
    			previ[st.top()]=i;
    			st.pop();
    		}
    		else{
    			break;
    		}
    	}
    	st.push(i);
    	i--;
    }

    while(!st.empty()){
    	previ[st.top()]=-1;
    	st.pop();
    }
    ll ans=0,val1,val2;
    rep(i,n){
    	//cout<<val1<<endl;
    	val2=min(nexti[i],nextior[i]);
    	val1=max(previ[i],previor[i]);
    	val2--;
    	val1++;
    	//cout<<nextior[i]<<endl;
    	//cout<<val1<<" "<<val2
    	ans+=(i-val1+1)*(val2-i+1);
    }
    //cout<<ans<<endl;
    printf("%lld",n*(n+1)/2-ans);//<<endl;
    return 0;  
    
}