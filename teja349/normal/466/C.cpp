
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
ll n,s,i,sum=0,count1=0,a[511111],b[511111],c[511111],d[511111];
int main(){
	
	cin>>n;
	rep(i,n){
		cin>>a[i];
		s+=a[i];
	}
	if(s%3!=0){
		cout<<0<<endl;
		return 0;
	}
	b[0]=a[0];
	if(b[0]==s/3)
		c[0]=++sum;
	f(i,1,n){
		b[i]=b[i-1]+a[i];
		if(b[i]==s/3)
			c[i]= ++sum;

		//cout<<i<<"   "<<c[i]<<endl;
	}
	sum=0;
	
	fd(i,n-2,0){
		if(b[n-1]-b[i] == s/3){
			
			d[i+1]=++sum;
			//cout<<i+1<<"   "<<d[i+1]<<endl;

		}
		else{
			d[i+1]=sum;
		}
	}
	//cout<<s<<"mee"<<endl;
	f(i,0,n-2){
		if(b[i]==s/3){
			count1+=d[i+2];
		}
	}
	cout<<count1<<endl;
	
}