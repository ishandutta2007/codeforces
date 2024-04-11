#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>

#define mp make_pair
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define TM template<class T,class U=int,class...V>
#define DF(t,...)TM auto operator<<(ostream&o,__VA_ARGS__ x)->decltype(t,cout)
#define DD(...)void print(){cerr<<'{';dbgx(#__VA_ARGS__,__VA_ARGS__);cerr<<'}';}
#ifdef LOC
#define dbg(...)(cerr<<"<"<<__LINE__,dbgx("> "#__VA_ARGS__,__VA_ARGS__),cerr<<"\n")
#else
#define dbg(...)
#endif
using namespace std;using namespace rel_ops;using ll=int64_t;using Vi=vector<int>;using Pii=pair<int,int>;
void dbgx(...){}TM void dbgx(T s,U a,V...b){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;dbgx(s,b...);}
DF(&T::print,T){x.print();return o;}DF(0,pair<T,U>){return o<<"("<<x.first<<", "<<x.second<<")";}
DF(T().begin(),T){o<<"[";each(e,x)o<<e<<", ";return o<<"]";}

// ----------------------------------------------------------------------------------------------------- //

int n;
vector<Pii> swaps4, swaps5, swaps4x4;

Vi perm, stable;
vector<Pii> allSwaps, goodSwaps;

bool isIdent(const vector<Pii>& swaps, int len) {
	perm.resize(len);
	iota(all(perm), 0);

	each(x, swaps) swap(perm[x.first], perm[x.second]);
	rep(i, 0, len) if (perm[i] != i) return false;
	return true;
}

bool findIdent(int mask) {
	if (mask == 0) return true;

	rep(i, 0, sz(allSwaps)) if ((mask >> i) & 1) {
		auto s = allSwaps[i];
		swap(perm[s.first], perm[s.second]);

		bool ok1 = (--stable[s.first] > 0 || perm[s.first] == s.first);
		bool ok2 = (--stable[s.second] > 0 || perm[s.second] == s.second);

		if (ok1 && ok2 && findIdent(mask & ~(1 << i))) {
			goodSwaps.push_back(s);
			return true;
		}

		stable[s.first]++;
		stable[s.second]++;
		swap(perm[s.first], perm[s.second]);
	}
	return false;
}

void makeIdent(vector<Pii>& swaps, int len) {
	allSwaps = swaps;
	
	goodSwaps.clear();
	perm.resize(len);
	stable.resize(len);
	iota(all(perm), 0);
	fill(all(stable), 0);

	each(s, swaps) {
		stable[s.first]++;
		stable[s.second]++;
	}

	assert(findIdent((1 << sz(swaps)) - 1));
	swaps = goodSwaps;
	assert(isIdent(swaps, len));
}

void initPerms() {
	rep(i, 0, 4) rep(j, i+1, 4) swaps4.push_back(mp(i, j));
	rep(i, 0, 5) rep(j, i+1, 5) swaps5.push_back(mp(i, j));
	rep(i, 0, 4) rep(j, 4, 8) swaps4x4.push_back(mp(i, j));

	makeIdent(swaps4, 4);
	makeIdent(swaps5, 5);
	makeIdent(swaps4x4, 8);

	dbg(swaps4);
	dbg(swaps5);
	dbg(swaps4x4);
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	cin >> n;

	if ((n % 4) != 0 && (n % 4) != 1) {
		cout << "NO\n";
		return 0;
	}

	initPerms();
	cout << "YES\n";

	vector<Pii> final;

	for (int i = 0; i+4 <= n; i += 4) {
		if ((n % 4) == 1) {
			each(s, swaps5) final.push_back({ i+s.first, (s.second == 4 ? n-1 : i+s.second) });
		} else {
			each(s, swaps4) final.push_back({ i+s.first, i+s.second });
		}

		for (int j = i+4; j+4 <= n; j += 4) {
			each(s, swaps4x4) final.push_back({ i+s.first, j+s.second-4 });
		}
	}

	assert(isIdent(final, n));
	assert(sz(final) == n*(n-1)/2);
	dbg(final);

	each(x, final) cout << x.first+1 << " " << x.second+1 << endl;
	return 0;
}