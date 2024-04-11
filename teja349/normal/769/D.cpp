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
ll arr[123456]={0};
int lol[123456]={0};
int k;
int checker(int val){
	int cou=0;
	while(val>0){
		if(val%2==1)
			cou++;
		val/=2;
	}
	if(cou==k)
		return 1;
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,val,i,j;
	ll sumi=0;
	cin>>n>>k;
	rep(i,n){
		cin>>val;
		arr[val]++;
	}
	rep(i,123456){
		if(checker(i)){
			lol[i]=1;
		}
	}
	//ll sumi=0;
	rep(i,10001){
		f(j,i+1,10001){
			if(lol[i^j]){
				sumi+=arr[i]*arr[j];
			}
		}
	}
	if(k==0){
		rep(i,10001){
			sumi+=(arr[i]*(arr[i]-1))/2;
		}
	}
	
	cout<<sumi<<endl;

}