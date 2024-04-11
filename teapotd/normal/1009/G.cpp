#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

constexpr int ALPHA = 6;
constexpr int APOW = 1 << ALPHA;

int counts[ALPHA], hall[APOW];
Vi masks;

bool isHall() {
	rep(mask, 0, APOW) {
		int x = 0;
		rep(i, 0, ALPHA) if (mask & (1<<i)) x += counts[i];
		if (x > hall[mask]) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	string str; cin >> str;
	each(c, str) counts[c-'a']++;

	masks.resize(str.size(), APOW-1);

	int n; cin >> n;
	while (n--) {
		int i; cin >> i >> str; i--;
		masks[i] = 0;
		each(c, str) masks[i] |= 1 << (c-'a');
	}

	rep(mask, 0, APOW) each(opt, masks) if (opt & mask) hall[mask]++;

	if (!isHall()) {
		cout << "Impossible\n";
		return 0;
	}

	rep(i, 0, sz(masks)) {
		int opt = masks[i];
		rep(mask, 0, APOW) if (opt & mask) hall[mask]--;

		rep(chr, 0, ALPHA) if (counts[chr] > 0 && (masks[i] & (1<<chr))) {
			counts[chr]--;
			if (isHall()) {
				cout << char('a'+chr);
				break;
			}
			counts[chr]++;
		}
	}
	return 0;
}