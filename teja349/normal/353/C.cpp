
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
int main(){
	ll n,maxi=0,a[123456],b[123456],i,sum=0;
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	string s;
	cin>>s;
	b[0]=a[0];
	f(i,1,n){
		b[i]=b[i-1]+a[i];
	}
	fd(i,s.length()-1,0){
		if(s.at(i)=='0')
			continue;
		if(i==0)
			maxi=max(maxi,sum+b[0]);
		else
			maxi=max(maxi,sum+b[i-1]);
		sum+=a[i];
		//cout<<b[s.length()-2-i]<<"   "<<s.length()<<endl;
	}
	cout<<maxi<<endl;

}