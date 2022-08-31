
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
int main(){
	ll n,m,k,x,y;
	cin>>n>>m>>k>>x>>y;
	if(n==1){
		ll val=k/m;
		ll val1=k%m;
		if(val1==0){
			cout<<val<<" ";
		}
		else{
			cout<<val+1<<" ";
		}
		cout<<val<<" ";
		if(y<=val1)
			cout<<val+1<<" ";
		else{
			cout<<val<<endl;
		}
		return 0;
	}
	ll val=m*(n-1)*2;
	ll rou=k/val;
	ll lef=k%val;
	ll i,j,arr[105][105]={0},maxi=0,mini=k+2;
	lef-=m;
	if(lef<0){
		rou--;
		lef+=m*(n-1)*2;
		
	}
	f(i,2,n){
		f(j,1,m+1){
			arr[i][j]=2*rou;
		}
	}
	f(j,1,m+1){
		arr[1][j]=rou+1;
		arr[n][j]=rou;
	}
	f(i,2,n+1){
		f(j,1,m+1){
			if(lef){
				arr[i][j]++;
				lef--;
			}
			else{
				break;
			}
		}
	}
	fd(i,n-1,1){
		f(j,1,m+1){
			if(lef){
				arr[i][j]++;
				lef--;
			}
			else{
				break;
			}
		}
	}
	f(i,1,n+1){
		f(j,1,m+1){
			maxi=max(maxi,arr[i][j]);
			mini=min(mini,arr[i][j]);
		}
	}
	cout<<maxi<<" "<<mini<<" "<<arr[x][y]<<endl;

	

}