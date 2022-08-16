//raja1999
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
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
vector<vl>vec(100005);
vl v;
ll a[100005],b[100005];
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	//cin>>t;
	t=1;
	while(t--){
		ll n,k,i,j,ans=0;
		cin>>n>>k;
		rep(i,n){
			cin>>a[i];

		}
		rep(i,n){
			cin>>b[i];
		}
		rep(i,n){
			vec[a[i]].pb(b[i]);
		}
		f(i,1,k+1){
			sort(vec[i].rbegin(),vec[i].rend());
			f(j,1,vec[i].size()){
				v.pb(vec[i][j]);
			}
		}
		sort(all(v));
		j=0;
		f(i,1,k+1){
			if(vec[i].size()==0){
				ans+=v[j];
				j++;
			}
		}
		cout<<ans<<endl;
	}
}