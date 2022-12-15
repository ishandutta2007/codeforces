#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define pu push
#define pb push_back
#define em emplace
#define eb emplace_back
#define sp ' '
#define nl '\n'
#define ct first
#define idx second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t, A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; sc(n, m);
	pi a[105]; //ct, idx
	for(int i = 0; i <= m; i++) a[i] = {0, 0};
	for(int i = 1; i <= m; i++) a[i].idx = i;
	for(int i = 0; i < n; i++) {
		int tmp; sc(tmp);
		a[tmp].ct++;
	}
	int ans = 0;
	vector<pi> tp;
	sort(a + 1, a + m + 1, greater<>());
	while(a[1].ct != 0) {
		if(a[2].ct == 0) {
			while(a[1].ct != 0) tp.eb(a[1].idx, a[1].idx), a[1].ct--;
		}
		else if(a[1].ct == 1) {
			int last = -1;
			for(int i = 2; a[i].ct != 0; i++) {
				tp.eb(a[i].idx, a[i - 1].idx); ans++;
				last = a[i].idx;
			}
			tp.eb(a[1].idx, last); ans++;
			break;
		}
		else {
			tp.eb(a[1].idx, a[2].idx);
			tp.eb(a[2].idx, a[1].idx);
			a[1].ct--; a[2].ct--;
			ans += 2;
		}
		sort(a + 1, a + m + 1, greater<>());
	}
	pr(ans, nl);
	for(int i = 0; i < tp.size(); i++) {
		pr(tp[i].first, sp, tp[i].second, nl);
	}
}