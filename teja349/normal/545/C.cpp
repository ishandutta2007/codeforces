
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

int main(){
	int n,i,a[123456],b[123456],l[123456],r[123456],st[123456];
	l[0]=r[0]=st[0]=0;
	cin>>n;
	rep(i,n){
		cin>>a[i];
		cin>>b[i];
	}
	f(i,1,n-1){
		st[i]=max(st[i-1],max(l[i-1],r[i-1]));
		if(a[i-1]<a[i]-b[i]){
			l[i]=max(l[i-1],st[i-1])+1;
			if(a[i-1]+b[i-1]<a[i]-b[i]){
				l[i]=max(l[i],r[i-1]+1);
			}
		}
		else{
			l[i]=-2;
		}
		if(a[i]+b[i]<a[i+1])
		{
			r[i]=max(l[i-1],max(r[i-1],st[i-1]))+1;
		}
		else{
			r[i]=-2;
		}
	}
	cout<<max(l[n-2],max(r[n-2],st[n-2]))+min(2,n);
}