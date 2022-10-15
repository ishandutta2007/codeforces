#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, m;
ll fta[mxN+1], ftb[mxN+1];

inline void upd(int l, ll x) {
	//cout << "upd " << l << " " << x << endl;
	ll x2=x*(n-l);
	for(int i=l+1; i<=n; i+=i&-i)
		fta[i]+=x2, ftb[i]+=x;
}

inline ll qry(int r) {
	//cout << "qry " << r << endl;
	ll ta=0, tb=0;
	for(int i=r+1; i>0; i-=i&-i)
		ta+=fta[i], tb+=ftb[i];
	return ta-(n-1-r)*tb;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	set<pair<int, ll>> s;
	for(int i=0; i<=n; ++i)
		s.insert({i, i+1});
	while(m--) {
		int qt, l, r;
		cin >> qt >> l >> r, --l, --r;
		if(qt==1) {
			ll x;
			cin >> x;
			auto it1=s.upper_bound({l+1, 0}), it2=s.upper_bound({r+2, 0});
			--it1, --it2;
			if(it1->first!=l)
				s.insert({l, it1->second});
			if(it2->first!=r+1)
				s.insert({r+1, it2->second});
			it2=s.lower_bound({l, 0});
			while(it2->first<=r) {
				it1=it2++;
				upd(it1->first, abs(x-it1->second));
				upd(it2->first, -abs(x-it1->second));
				it2=s.erase(it1);
			}
			s.insert({l, x});
		} else
			cout << qry(r)-qry(l-1) << "\n";
	}
}