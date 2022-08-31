
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
vector< pii > adjr(400100),adjc(400100),adjrc(400100),adjcr(400100),vec;
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,x,y;
	cin>>n>>m;
	rep(i,4*n+20){
		adjr[i].ff=inf;
		adjr[i].ss=-1;
		adjc[i].ff=inf;
		adjc[i].ss=-1;
		adjrc[i].ff=inf;
		adjrc[i].ss=-1;
		adjcr[i].ff=inf;
		adjcr[i].ss=-1;
	}
	rep(i,m){
		cin>>x>>y;
		vec.pb(mp(x,y));
		adjr[x].ff=min(adjr[x].ff,y);
		adjc[y].ff=min(adjc[y].ff,x);
		adjrc[x+y].ff=min(adjrc[x+y].ff,x);
		adjcr[x-y+2*n+3].ff=min(adjcr[x-y+2*n+3].ff,x);
		adjr[x].ss=max(adjr[x].ss,y);
		adjc[y].ss=max(adjc[y].ss,x);
		adjrc[x+y].ss=max(adjrc[x+y].ss,x);
		adjcr[x-y+2*n+3].ss=max(adjcr[x-y+2*n+3].ss,x);
	}
	int ans;
	int a[20]={0};
	rep(i,m){
		ans=0;
		x=vec[i].ff;
		y=vec[i].ss;
		if(adjr[x].ff == adjr[x].ss){

		}
		else if(adjr[x].ff==y || adjr[x].ss==y){
			ans++;
		}
		else{
			ans+=2;
		}
		if(adjc[y].ff == adjc[y].ss){

		}
		else if(adjc[y].ff==x || adjc[y].ss==x){
			ans++;
		}
		else{
			ans+=2;
		}
		if(adjrc[x+y].ff == adjrc[x+y].ss){

		}
		else if(adjrc[x+y].ff==x || adjrc[x+y].ss==x){
			ans++;
		}
		else{
			ans+=2;
		}
		if(adjcr[x-y+2*n+3].ff == adjcr[x-y+2*n+3].ss){

		}
		else if(adjcr[x-y+2*n+3].ff==x || adjcr[x-y+2*n+3].ss==x){
			ans++;
		}
		else{
			ans+=2;
		}
		//cout<<ans<<" ";
		a[ans]++;
	}
	rep(i,9){
		cout<<a[i]<<" ";
	}
}