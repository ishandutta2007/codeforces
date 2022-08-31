
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
	int n,i;
	cin>>n;
	int a[150],d[150],b[150],c[150];
	rep(i,n){
		cin>>a[i];
	}
	b[0]=c[0]=d[0]=0;

	f(i,1,n+1){
		if(a[i-1]==0){
			b[i]=1000;
			c[i]=1000;
			d[i]=min(d[i-1],min(c[i-1],b[i-1]))+1;
		}
		else if(a[i-1]==1){
			b[i]=min(d[i-1],c[i-1]);
			c[i]=1000;
			d[i]=min(b[i-1],min(c[i-1],d[i-1]))+1;
		}
		else if(a[i-1]==2){
			b[i]=1000;
			c[i]=min(b[i-1],d[i-1]);
			d[i]=min(b[i-1],min(c[i-1],d[i-1]))+1;
			//cout<<i<<"  "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
		}
		else if(a[i-1]==3){
			b[i]=min(d[i-1],c[i-1]);
			c[i]=min(b[i-1],d[i-1]);
			d[i]=min(b[i-1],min(c[i-1],d[i-1]))+1;
		}
	}
	cout<<min(b[n],min(c[n],d[n]));

}