
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
ll c[300000],d[300000];
int main(){
	
	ll high=inf;
	high*=inf;
	
	ll infff=inf;
	infff*=inf;
	ll low=-1*infff;
	ll check=infff/200;
	ll n,i,lown,highn;
	cin>>n;

	rep(i,n){
		cin>>c[i]>>d[i];
	}
	if(d[0]==1){
		low=1900;
	}
	else{
		high=1899;
	}
	f(i,0,n-1){
		if(d[i]==1&&d[i+1]==1){
			// if(c[i]>0){
			// 	lown=1900+c[i];

			// 	highn=infff;
			// }
			lown=max(1900+c[i],(ll)1900);
			highn=infff;
			
			
		}
		else if(d[i]==1&&d[i+1]==2){

				lown=1900+c[i];
				highn=1899;
			
		}
		else if(d[i]==2&&d[i+1]==1){
			lown=1900;
			highn=1899+c[i];
		}
		else{
			lown=-1*infff;
			highn=(1899+c[i],(ll)1899);
		}
		low=max(low+c[i],lown);
		high=min(high+c[i],highn);//cout<<low<<" "<<high<<endl;
		if(low>high){
			cout<<"Impossible"<<endl;
			return 0;
		}
		//if(d[i+1]==2&&)

	}
	low+=c[i];
	high+=c[i];
	if(high>check){
		cout<<"Infinity"<<endl;
	}
	else{
		cout<<high<<endl;
	}
}