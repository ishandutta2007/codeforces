#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second

const int N=160;
const int dx[8]={1,1,0,-1,-1,-1,0,1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
bool seen[N+N][N+N];

typedef pair<pair<int,int>,int> state;
int main() {
	int n; cin>>n;
	vector<state> vs;
	vs.pb({{N,N},0});
	int ans=0;
	for(;n--;) {
		int ti; cin>>ti;
		for(;ti--;) {
			for(auto &s:vs) {
				int x=s.fi.fi;
				int y=s.fi.se;
				int k=s.se;
				x+=dx[k];
				y+=dy[k];
				s.fi.fi=x;
				s.fi.se=y;
				if(!seen[x][y]) seen[x][y]=1, ++ans;
			}
		}
		vector<state> ns;
		for(auto &s:vs) ns.pb({s.fi,(s.se+1)&7});
		for(auto &s:vs) ns.pb({s.fi,(s.se+7)&7});
		sort(ns.begin(),ns.end());
		ns.resize(unique(ns.begin(),ns.end())-ns.begin());
		vs=ns;
	}
	cout<<ans<<endl;
}