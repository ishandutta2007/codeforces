#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define int signed
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
 
// -----<SCANF>-----
#define sfi(x) scanf("%d",&x);
#define sfi2(x,y) scanf("%d%d",&x,&y);

void solvethetestcase();
 
signed main(){
	solvethetestcase();
}   
 
int n;

vector<pair<pii,int> >v;
set<pii> gg;
vpii till[1000005];

int par[500005],sz[500005];

int findp(int u){
	if(par[u] == u) return u;
	else{
		par[u]=findp(par[u]);
		return par[u];
	}
}

void merge(int u,int v){
	u = findp(u);
	v = findp(v);
	if(u == v) return;
	if(sz[u] < sz[v]){
		sz[v] += sz[u];
		par[u] = v;
	}
	else{
		sz[u] += sz[v];
		par[v] = u;
	}

}

void solvethetestcase(){
	sfi(n)
	REP(i,n){
		int l,r; sfi2(l,r)
		v.pb({{l,r},i});
		par[i] = i;
		sz[i] = 1;
	}
	sort(all(v));
	int edges =0;
	REP(i,n){
		for(auto x:till[i]) gg.erase(x);
		till[i].clear();
		if(gg.size()){
			auto it = gg.begin();
			while(gg.size() and (*it).F < v[i].F.F ){
				gg.erase(gg.begin());
				it = gg.begin();
			}
			while(gg.size() and it != gg.end() and v[i].F.S >= (*it).F){
				merge(i,(*it).S);
				edges ++;
				if(edges >= n){
					printf("NO\n");
					return;
				}
				it++;
			}
		}
		gg.insert({v[i].F.S,i});
		till[v[i].F.S].pb({v[i].F.S,i});
		
	}
	if(sz[findp(0)] == n){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}