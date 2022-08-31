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
bool prim[2*1234569]={0};
int a[12345];
vi vec;
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,j;
	cin>>n;
	for(i=2;i*i<=2*1234567;i++){
		if(prim[i])
			continue;
		for(j=i*i;j<=2*1234567;j+=i){
			prim[j]=1;
		}
	}
	int counter=0;
	rep(i,n){
		cin>>a[i];
		if(a[i]==1){
			counter++;
		}
		else{
			vec.pb(a[i]);
		}
	}
	int maxi=0;
	rep(i,vec.size()){
		if(counter==0)
			break;
		if(prim[vec[i]+1]==0){
			maxi=counter+1;
			cout<<maxi<<endl;
			rep(j,counter){
				cout<<1<<" ";
			}
			cout<<vec[i]<<endl;
			return 0;
		}
	}
	if(counter>=2){
		cout<<counter<<endl;
		rep(i,counter){
			cout<<1<<" ";
		}
		return 0;
	}
	rep(i,vec.size()){
		rep(j,vec.size()){
			if(prim[vec[i]+vec[j]]==0){
				maxi=max(maxi,2);
				cout<<maxi<<endl;
				cout<<vec[i]<<" "<<vec[j]<<endl;
				return 0;
			}
		}
	}
	cout<<1<<endl;
	cout<<a[0]<<endl;
	return 0;



}