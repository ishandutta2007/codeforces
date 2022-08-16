
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
vii edge(412345),wt;
vector<pair< pii , pii > > ans(412345);
int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,u,v,w;
	cin>>n>>m;
	rep(i,m){
		cin>>u>>v>>w;
	//	u--;
		//v--;
		edge[i]=mp(u,v);
		wt.pb(mp(w,i));
	}
	rep(i,n+10){
		ans[i].ff.ff=0;
		ans[i].ss.ff=0;
		ans[i].ss.ss=-3;
		ans[i].ff.ss=-2;
	}
	sort(wt.begin(),wt.end());
	rep(i,m){
		if(ans[edge[wt[i].ss].ff].ff.ss < wt[i].ff){
			if(ans[edge[wt[i].ss].ss].ff.ff < 1 + ans[edge[wt[i].ss].ff].ff.ff){
				if(ans[edge[wt[i].ss].ss].ff.ss != wt[i].ff){
					ans[edge[wt[i].ss].ss].ss=ans[edge[wt[i].ss].ss].ff;
				}
				ans[edge[wt[i].ss].ss].ff=mp(ans[edge[wt[i].ss].ff].ff.ff+1,wt[i].ff);

			}

		}
		else{
			if(ans[edge[wt[i].ss].ss].ff.ff < 1 + ans[edge[wt[i].ss].ff].ss.ff){
				if(ans[edge[wt[i].ss].ss].ff.ss != wt[i].ff){
					ans[edge[wt[i].ss].ss].ss=ans[edge[wt[i].ss].ss].ff;
				}
				ans[edge[wt[i].ss].ss].ff=mp(ans[edge[wt[i].ss].ff].ss.ff+1,wt[i].ff);

			}
		}
	}
	int maxi=0;
	f(i,1,n+3){
		maxi=max(maxi,ans[i].ff.ff);
		maxi=max(maxi,ans[i].ss.ff);
	}
	cout<<maxi<<endl;

}