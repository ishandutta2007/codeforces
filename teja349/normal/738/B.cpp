
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
	int n,m,i,a[1001][1001]={0},b[1001]={0},c[1001]={0},d[1001]={0},e[1001]={0},j,s=0;
	cin>>n>>m;
	rep(i,n){
		rep(j,m){
			cin>>a[i][j];
			b[i]+=a[i][j];
			c[j]+=a[i][j];
		}
	}
	// rep(i,m){
	// 	cout<<c[i]<<endl;
	// }
	rep(i,n){
		rep(j,m){
			if(a[i][j]==1){
				d[i]++;
				e[j]++;
			}
			else{
				
				
				if(d[i]!=0)
					s++;
				if(b[i]-d[i]!=0)
					s++;

				if(e[j]!=0)
					s++;
				if(c[j]-e[j]!=0)
					s++;
				//cout<<i<<" "<<j<<" "<<s<<endl;
			}
		}
	}
	cout<<s<<endl;

}