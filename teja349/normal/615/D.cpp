
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >



ll power(ll a,ll b);
int main(){
	ll m,i,val,flag=-1;
	cin>>m;
	ll num=1,max=0,mul=1,a[200*1000+4]={0};
	rep(i,m){
		cin>>val;
		a[val]++;
		num*=val;
		num%=mod;
		if(val>max)
			max=val;

	}
	rep(i,max+2){
		if((a[i]+1)%2==0){
			a[i]=a[i]/2;
			flag=i;
			break;
		}

	}


	rep(i,max+2){

		mul*=a[i]+1;
		mul%=(mod-1);

	}
	if(flag==-1)
	{
		num=1;
		rep(i,max+2){
			num*=power(i,a[i]/2);
			//cout<<i<<"   "<<"   "<<a[i]<<num<<endl;
			num%=mod;
		}
	}
	//cout<<num<<"  "<<mul;
	ll ans=power(num,mul);
	cout<<ans<<endl;
}
ll power(ll a,ll b){
	ll val=1;
	if(b%2==1)
		val*=a;
	while(b/2!=0){
		b=b/2;
		a=a*a;
		a%=mod;
		if(b%2==1)
			val*=a;
		val%=mod;
	}
	val%=mod;
	return val;
}