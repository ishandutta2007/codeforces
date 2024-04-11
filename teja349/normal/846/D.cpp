// teja349
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


//helper functions
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
int arr[1000][1000];
struct total{
	int x,y,t;
};
total haha[523456];

bool comp(total a,total b){
	return a.t<b.t;
}
int n,m,k,q;
int check(int val){
	int i,j;
	rep(i,n+1){
		rep(j,m+1){
			arr[i][j]=0;
		}
	}
	rep(i,q){
		if(haha[i].t>val)
			break;

		arr[haha[i].x][haha[i].y]=1;
	}
	f(i,1,n+1){
		f(j,1,m+1){
			arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
			if(i>=k && j>=k){

				if(arr[i][j]-arr[i-k][j]+arr[i-k][j-k]-arr[i][j-k]==k*k){
					//cout<<i<<" "<<k<<endl;
					return 1;
				}
			}
		}
	}
	return 0;

}

int main(){
	std::ios::sync_with_stdio(false);
	int x,y,d;
	cin>>n>>m>>k>>q;
	int i;
	rep(i,q){
		cin>>x>>y>>d;
		haha[i].x=x;
		haha[i].y=y;
		haha[i].t=d;
	}
	sort(haha,haha+q,comp);
	int l=0;
	int r=inf;
	int mid,ans=inf;
	//cout<<check(0)<<endl;
	//return 0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	if(ans==inf){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}


	return 0;  
}