
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
int n,m,k;
int checked(ll val);
int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	m-=n;
	int low=0;
	int high=m+2;
	int mid=(low+high)/2;
	int ans;
	while(low<=high){
		if(checked(mid)==1){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	cout<<ans+1<<endl;

}

int checked(ll val){
	ll ri,li,val1;
	ri=val*(val+1)/2;
	if(val>n-k){
		val1=val+k-n-1;
		ri-=max(val1*(val1+1)/2,(ll)0);
	}
	val--;
	li=val*(val+1)/2;

	ll k1=k-1;
	val++;
	if(val>k){

		val1=val-k;
		li-=max(val1*(val1+1)/2,(ll)0);
	}
	if(ri+li<=m)
		return 1;
	else 
		return 0;
	
}