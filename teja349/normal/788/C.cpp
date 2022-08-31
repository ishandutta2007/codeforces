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
bitset<1010002> b,b1;
vi vec;
int arr[20000]={0};
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	int k;
	int i,j,val;
	cin>>n>>k;
	rep(i,k){
		cin>>val;
		arr[val]=1;
	}
	int haha=0,lol=0;
	rep(val,1004){
		if(arr[val]){
			vec.pb(val);
			b[val]=1;
			if(val==n){
				cout<<1<<endl;
				return 0;
			}
			if(val<n){
				haha=1;
			}
			if(val>n){
				lol=1;
			}
		}
		
	}
	if(haha*lol==0){
		cout<<-1<<endl;
		return 0;
	}
	rep(i,1003){
		b1&=0;
		rep(j,vec.size()){
			b1|=b<<(vec[j]);
		}
		b&=0;
		b|=b1;
		if(b[n*(i+2)]==1){
			cout<<i+2<<endl;
			return 0;
		}
	}
}