#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100050;

struct Event{
	int t, id;
	bool operator<(const Event &ev)const{
		return t < ev.t;
	}
};

struct disj{
	int pa[MAXN];
	void init(int n) {
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<int> c(n + 1);
		vector<int> l(n + 1), r(n + 1);
		vector<Event> ev;
		for(int i = 1; i <= n; i++) {
			cin >> c[i] >> l[i] >> r[i];
			ev.push_back({l[i], i});
			ev.push_back({r[i]+1, -i});
		}
		sort(all(ev));
		disj.init(n);
		int ans = n;
		set<pi> s[2];
		for(auto& e : ev) {
			int i = e.id;
			int col = c[abs(i)];
			if(i > 0){
				vector<pi> tmp;
				while(sz(s[col ^ 1]) && l[i] <= (*prev(s[col ^ 1].end())).first){
					auto it = prev(s[col ^ 1].end());
					if(disj.uni(i, it->second)) ans--;
					tmp.push_back(*it);
					s[col ^ 1].erase(it);
				}
				if(sz(tmp)){
					s[col ^ 1].insert(tmp[0]);
				}
				s[col].insert({r[i], i});
			}else{
				i = -i;
				s[col].erase({r[i], i});
			}
		}
		cout << ans << "\n";
	}
}