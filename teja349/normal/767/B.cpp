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
vl vec;
ll ans;
int main(){
	std::ios::sync_with_stdio(false);
	ll ts,tf,t,n,i,j,val;
	ll bigt=0;
	cin>>ts>>tf>>t>>n;
	rep(i,n){
		cin>>val;
		vec.pb(val);
		if(val<tf){
			bigt++;
		}
		
	}
	ll mytime;
	ans=inf;
	ans*=inf;
	



	ll timer=0;
	i=0;
	while(i<n){
		
			//cout<<"hiivvv";
			if(ts+i*t<=tf-t && vec[i]<tf-1){

				if(ans>ts+i*t-vec[i]){
					//;
					ans=ts+i*t-vec[i]+1;
					mytime=vec[i]-1;
					//cout<<ans<<endl;
				}

			}
			else{
				break;
			}
		
		
		timer=vec[i];	
		while(vec[i]==timer && i<n){
			i++;
		}




	}
	//cout<<ans<<endl;
	if(ans<=0){
		cout<<mytime<<endl;
	}
	else if(ts+bigt*t<=tf-t){
		//cout<<"hii";
		cout<<tf-t<<endl;
		return 0;
	}
	else {
		cout<<mytime<<endl;
	}
	

}