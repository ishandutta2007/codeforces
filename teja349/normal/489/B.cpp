
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

int main(){
	int n,m,i,j,a[105],b[105],c[104][104];
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	sort(a,a+n);
	cin>>m;
	rep(i,m){
		cin>>b[i];

	}
	sort(b,b+m);
	if(abs(b[0]-a[0])<2)
		c[0][0]=1;
	else 
		c[0][0]=0;
	f(i,1,n){
		if(abs(b[0]-a[i])<2){
			c[0][i]=1;
		}
		else{
			c[0][i]=c[0][i-1];
		}
	}
	f(i,1,m){
		if(abs(b[i]-a[0])<2){
			c[i][0]=1;
		}
		else{
			c[i][0]=c[i-1][0];
		}
	}
	f(i,1,m){
		f(j,1,n){
			if(abs(a[j]-b[i])<2)
				c[i][j]=c[i-1][j-1]+1;
			else{
				c[i][j]=max(c[i-1][j-1],max(c[i][j-1],c[i-1][j]));
			}
		}

	}
	cout<<c[m-1][n-1]<<endl;
}