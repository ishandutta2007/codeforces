
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
int arr[123456],opp[123456];
map<string , int > mapi; 
int finde(int p){
	if(arr[p]==-1)
		return p;
	arr[p]=finde(arr[p]);
	return arr[p];
}
int lovemerge(int x,int y){
	x=finde(x);
	y=finde(y);
	if(x==y){
		cout<<"YES"<<endl;
		return 0;
	}
	if(opp[y]==x){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	arr[x]=y;
	if(opp[x]!=-1 && opp[y]!=-1){
		arr[opp[x]]=opp[y];
	}
	else if(opp[x]!=-1){
		opp[y]=opp[x];
		opp[opp[x]]=y;
	}

	return 0;

}
int hatemerge(int x,int y){
	x=finde(x);
	y=finde(y);
	if(x==opp[y]){
		cout<<"YES"<<endl;
		return 0;
	}
	if(x==y){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;

	if(opp[x]==-1 && opp[y]==-1){
		opp[x]=y;
		opp[y]=x;
	}
	else if(opp[x]==-1){
		arr[x]=opp[y];


	}
	else if(opp[y]==-1){
		arr[y]=opp[x];
	}
	else{
		arr[y]=opp[x];
		arr[opp[y]]=x;
	}
	return 0;

}
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,q,i,x,y,t;
	string s,s2,s1;
	cin>>n>>m>>q;
	rep(i,n){
		cin>>s;
		mapi[s]=i;
	}
	rep(i,n+10){
		arr[i]=-1;
		opp[i]=-1;
	}
	rep(i,m){
		cin>>t>>s1>>s2;
		if(t==1){
			lovemerge(mapi[s1],mapi[s2]);
		}
		else{
			hatemerge(mapi[s1],mapi[s2]);
		}

	}
	rep(i,q){
		cin>>s1>>s2;
		x=mapi[s1];
		y=mapi[s2];
		x=finde(x);
		y=finde(y);
		if(x==y){
			cout<<"1"<<endl;
		}
		else if(x==opp[y]){
			cout<<2<<endl;
		}
		else{
			cout<<3<<endl;
		}
	}
}