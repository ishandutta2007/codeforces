
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
int a[500][500]={0},b[500][500]={0},c[500][500]={0},arr[500][500]={0};
int main(){
	int n,m,i,j,q;
	string s;
	cin>>n>>m;
	rep(i,n){
		cin>>s;
		rep(j,m){
			if(s.at(j)=='.')
				a[i][j]=0;
			else
				a[i][j]=1;
		}

	}
	arr[0][0]=0;
	c[0][0]=0;
	b[0][0]=0;
	f(i,1,n){
		if(a[i][0]==1){
			b[i][0]=b[i-1][0];
			arr[i][0]=arr[i-1][0];
		}
		else{
			if(a[i-1][0]==0){
				b[i][0]=b[i-1][0]+1;
				arr[i][0]=arr[i-1][0]+1;
			}

			else{
				b[i][0]=b[i-1][0];
				arr[i][0]=arr[i-1][0];
			}
		}
	}
	f(i,1,m){
		if(a[0][i]==1){
			c[0][i]=c[0][i-1];
			arr[0][i]=arr[0][i-1];
		}
		else{
			if(a[0][i-1]==0){
				c[0][i]=c[0][i-1]+1;
				arr[0][i]=arr[0][i-1]+1;
			}
			else{
				c[0][i]=c[0][i-1];
				arr[0][i]=arr[0][i-1];
			}
		}
	}
	f(i,1,n){
		f(j,1,m){
			
				b[i][j]=b[i-1][j];
				c[i][j]=c[i][j-1];
				arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
			
			if(a[i][j]==0){
				if(a[i-1][j]==0){
					b[i][j]+=1;
					arr[i][j]+=1;
				}
				if(a[i][j-1]==0){
					c[i][j]+=1;
					arr[i][j]+=1;
				}
			}
		}
	}

	cin>>q;
	while(q--){
		int p,q,r,s;
		cin>>p>>q>>r>>s;
		ll ans=arr[r-1][s-1]-arr[p-1][s-1]-arr[r-1][q-1]+arr[p-1][q-1]+b[r-1][q-1]-b[p-1][q-1]+c[p-1][s-1]-c[p-1][q-1];
		cout<<ans<<endl;
	}


}