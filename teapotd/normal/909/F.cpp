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
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<'\n')
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

int n;

void solve0() {
	if (n % 2) {
		cout << "NO\n";
		return;
	}

	Vi perm(n);

	for (int k = n; k > 0;) {
		int i, p = 1;
		while ((p<<1) <= k) p <<= 1;

		for (i = 0; p+i-1 <= k; i++) {
			perm[p+i-2] = p-i;
			perm[p-i-1] = p+i-1;
		}
		k = p-i;
	}

	cout << "YES\n";
	each(x, perm) cout << x << " ";
	cout << endl;
}

void solve1() {
	if (n <= 5 || __builtin_popcount(n) == 1) {
		cout << "NO\n";
		return;
	}

	Vi perm(min(n, 7));
	iota(all(perm), 1);

	do {
		rep(i, 0, sz(perm)) if (perm[i] == i+1 || (perm[i] & (i+1)) == 0) goto nope;
		break; nope:;
	} while (next_permutation(all(perm)));

	perm.resize(n);

	for (int i = 8; i <= n; i <<= 1) {
		for (int j = 0; j < i && i+j <= n; j++) {
			perm[i+j-1] = i + ((j+1) % min(i,n-i+1));
		}
	}

	cout << "YES\n";
	each(x, perm) cout << x << " ";
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n;
	solve0();
	solve1();
	return 0;
}