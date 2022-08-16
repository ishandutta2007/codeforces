//teja349
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
int arr[123456],pre[123456],haha[123456];
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,j;
	cin>>n>>m;

	rep(i,n){
		rep(j,m){
			cin>>arr[m*i+j];
		}
	}
	rep(j,m){
		pre[m*0+j]=0;
		f(i,1,n){
			if(arr[m*i+j]>=arr[m*(i-1)+j]){
				pre[m*i+j]=pre[m*(i-1)+j];
			}
			else{
				pre[m*i+j]=i;
			}
		}

	}
	rep(i,n){
		haha[i]=pre[m*i+0];
		rep(j,m){
			haha[i]=min(haha[i],pre[m*i+j]);
		}
	}
	int k;
	cin>>k;
	while(k--){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		if(haha[r]<=l){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}


}