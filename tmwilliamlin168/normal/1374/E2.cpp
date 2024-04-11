#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

const int mxN=2e5;
int n, k, m;
vector<ar<ll, 2>> v[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	FOR(n) {
		int t, a, b;
		cin >> t >> a >> b;
		v[a*2+b].push_back({t, i});
	}
	FOR(4) {
		//v[i].push_back(0);
		sort(all(v[i]));
		//FOR(j, 1, sz(v[i]))
			//v[i][j]+=v[i][j-1];
	}
	ll ans=1e18;
	set<int> ans2;
	FOR(_, 2) {
		ll s=0;
		set<int> s2;
		priority_queue<ar<ll, 2>> pq;
		priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq2;
		FOR(j, 1, 3) {
			FOR(min(k, sz(v[j])))
				s+=v[j][i][0], s2.insert(v[j][i][1]);
			FOR(i, k, sz(v[j])) {
				s+=v[j][i][0], s2.insert(v[j][i][1]);
				pq.push(v[j][i]);
			}
		}
		FOR(sz(v[0])) {
			s+=v[0][i][0], s2.insert(v[0][i][1]);
			pq.push(v[0][i]);
		}
		FOR(sz(v[3])+1) {
			//cout << i << " " << s << endl;
			if(i) {
				s+=v[3][i-1][0], s2.insert(v[3][i-1][1]);
				FOR(j, 1, 3) {
					if(sz(v[j])>k-i&&k-i>=0)
						pq.push(v[j][k-i]);
				}
			}
			if(pq2.size()) {
				pq.push(pq2.top());
				s+=pq2.top()[0];
				s2.insert(pq2.top()[1]);
				pq2.pop();
			}
			while(pq.size()&&pq.size()>m-i-2*max(k-i, 0)) {
				s-=pq.top()[0];
				s2.erase(pq.top()[1]);
				pq2.push(pq.top());
				pq.pop();
			}
			if(pq.size()==m-i-2*max(k-i, 0)&&v[3].size()>=i&&sz(v[1])>=k-i&&sz(v[2])>=k-i&&s<ans) {
				ans=s;
				//ans2=s2;
			}
			if(_&&s==ans&&ans2.empty())
				ans2=s2;
		}
	}
	cout << (ans>=1e18?-1:ans) << "\n";
	for(int a : ans2)
		cout << a+1 << " ";
}