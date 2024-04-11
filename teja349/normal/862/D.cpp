// teja349
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


//helper functions
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

int checkstring(string s){
	
	cout<<"? "<<s<<endl;
	int val;
	cin>>val;

	return val;
}
int pos0,pos1,val1;
int findone(int sig,int l,int r,string s){
	int i;
	if(l==r){
		pos1=l+1;
		return 0;
	}

	int mid=(l+r)/2;
	int val=r-mid;
	//string s="";


	f(i,mid+1,r+1){
		if(s[i]=='1')
			s[i]='0';
		else
			s[i]='1';
	}
	//cout<<s<<endl;
	int val2=checkstring(s);
	if(val1-val2==sig*val){
		val1=val2;
		findone(sig,l,mid,s);
	}
	else{
		val1=val2;
		findone(sig*-1,mid+1,r,s);
	}
	return 0;
}

int findzero(int sig,int l,int r,string s){
	int i;
	//string s="";
	if(l==r){
		pos0=l+1;
		return 0;
	}

	int mid=(l+r)/2;
	int val=r-mid;

	f(i,mid+1,r+1){
		if(s[i]=='1')
			s[i]='0';
		else
			s[i]='1';
	}
	int val2=checkstring(s);
	if(val1-val2==sig*val){
		val1=val2;
		findzero(sig,l,mid,s);
	}
	else{
		val1=val2;
		findzero(sig*-1,mid+1,r,s);
	}
	return 0;
}


int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	int i;
	s="";
	rep(i,n){
		s+='1';
	}
	val1=checkstring(s);
	s="0";
	rep(i,n-1){
		s+='1';
	}
	int val2=checkstring(s);
	//return 0;
	s[0]='1';
	if(val1>val2){
		pos0=1;
		findone(1,0,n-1,s);
	}
	else{
		findzero(-1,0,n-1,s);
		pos1=1;
	}
	cout<<"! "<<pos0<<" "<<pos1<<endl;
	return 0;  
}