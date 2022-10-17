#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()

#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>

const int INF = 1e9;

int ask(ii poz){
	cout << "SCAN " << poz.f << ' ' << poz.s << endl;
	int ret;
	cin >> ret;
	
	return ret;
}

int dig(ii poz){
	cout << "DIG " << poz.f << ' ' << poz.s << endl;
	int ret;
	cin >> ret;
	
	return ret;
}

int dist(ii a, ii b){
	return abs(a.f - b.f) + abs(a.s - b.s);
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	vii zap;
	vi ans;
	
	zap.pb({1, 1});
	ans.pb(ask(zap.back()));
	zap.pb({1, m});
	ans.pb(ask(zap.back()));
	//zap.pb({n, 1});
	//ans.pb(ask(zap.back()));
	
	bool found = false;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int a = i; a <= n; a++){
				for(int b = j; b <= m; b++){
					if(i == a and j == b)
						continue;
					if(found)
						break;
					bool ok = true;
					for(int k = 0; k < sz(zap); k++)
						ok &= (dist({a, b}, zap[k]) + dist({i, j}, zap[k])) == ans[k];
					
					if(ok){
						found = true;
						zap.pb({(i + a) / 2, 1});
						ans.pb(ask(zap.back()));
						zap.pb({(i + a) / 2, (j + b) / 2});
						ans.pb(ask(zap.back()));
					}
				}
			}
		}
	}
	
	assert(found);
	found = false;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int a = i; a <= n; a++){
				for(int b = j; b <= m; b++){
					if(i == a and j == b)
						continue;					
					bool ok = true;
					for(int k = 0; k < sz(zap); k++)
						ok &= (dist({a, b}, zap[k]) + dist({i, j}, zap[k])) == ans[k];
					
					if(ok){				
						//cout << "KANDYDAT " << i << ' ' << j << ' ' << a << ' ' << b << endl;
						assert(not found);
						found = true;
						
						if(dig({i, j}))
							assert(dig({a, b}));
						else{
							assert(dig({i, b}));
							assert(dig({a, j}));
						}
					}
				}
			}
		}
	}
	assert(found);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int testy;
	cin >> testy;
	
	while(testy--){
		solve();
	}
	
	return 0;
}