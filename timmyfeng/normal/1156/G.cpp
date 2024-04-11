#include <bits/stdc++.h> 
using namespace std;

mt19937 rng(uint64_t(new char));

map<string, tuple<string, string, char>> expr;
map<tuple<string, string, char>, string> vstd;
map<string, string> eq, mp;
vector<string> ans;

void dfs(const string& u) {
	if (!expr.count(u)) {
		if (expr.count(eq[u])) {
			expr[u] = expr[eq[u]];
		} else if (eq[u] != u) {
			ans.push_back(u + '=' + eq[u]);
			return;
		} else return;
	}
	auto [arg1, arg2, op] = expr[u];
	expr.erase(u);
	dfs(arg1);
	dfs(arg2);
	ans.push_back(u + '=' + arg1 + op + arg2);
}

string newVar() {
	string res = "";
	for (int i = 0; i < 4; ++i) {
		res += char('a' + rng() % 26);
	}
	if (eq.count(res))
		return newVar();
	return res;
}

void chk(string& s) {
	if (mp.count(s)) {
		s = mp[s];
	}
	if (!eq.count(s)) {
		eq[s] = s;
	} else {
		s = eq[s];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	eq["res"] = "res";
	while (n--) {
		string s;
		cin >> s;
		int ndxE = find(s.begin(), s.end(), '=') - s.begin();
		string lval = s.substr(0, ndxE);
		string rval = s.substr(ndxE + 1);

		string arg1 = "", arg2 = "";
		char op = 0;
		for (char c : "$^#&") {
			int ndxO = find(rval.begin(), rval.end(), c) - rval.begin();
			if (ndxO < int(rval.size())) {
				arg1 = rval.substr(0, ndxO);
				arg2 = rval.substr(ndxO + 1);
				op = c;
			}
		}

		if (op) {
			chk(arg1);
			chk(arg2);
		} else {
			chk(rval);
		}
		if (eq.count(lval)) {
			mp[lval] = newVar();
			lval = mp[lval];
		}

		if (op) {
			auto res = make_tuple(arg1, arg2, op);
			if (vstd.count(res)) {
				eq[lval] = vstd[res];
			} else {
				eq[lval] = lval;
				expr[lval] = res;
				vstd[res] = lval;
			}
		} else {
			eq[lval] = rval;
		}
	}

	if (mp.count("res")) {
		string oth = mp["res"];
		eq["res"] = eq[oth];
		if (eq["res"] == oth) {
			eq["res"] = "res";
		}
		if (expr.count(oth)) {
			expr["res"] = expr[oth];
		}
	}

	dfs("res");
	cout << ans.size() << '\n';
	for (auto& s : ans) {
		cout << s << '\n';
	}
}