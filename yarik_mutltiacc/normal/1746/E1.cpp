// Problem: E1. - ( )
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/E1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int E = 3, L = 5;

vector<int> qs, ans;
int analyze(int N) {
	int works = 0;
	for(int z = 0; z < E; z++) {
		int last_lie = 0, bad = 0;
		for(int i = 0; i < N; i++) {
			int checker = ans[i];
			int real = (qs[i] >> z)&1;
			int lie = checker ^ real;
			if(lie && last_lie) bad = 1;
			last_lie = lie;
		}
		if(!bad) {
			works |= 1<<z;
			continue;
		}
	}
	return works;
}
struct Node {
	Node *l, *r;
	int q;
};
pair<int, Node*> brute(int p) {
	int anal = analyze(p);
	if(anal != ((1<<E)-1)) {
		Node *node = new Node();
		node->q = -anal;
		return {0, node};
	}
	if(p >= L) return {100, 0};
	int res = 100;
	Node *node = new Node();
	for(int i = 0; i < (1<<E); i++) {
		int good = -1;
		array<Node*, 2> uh;
		for(int j = 0; j < 2; j++) {
			qs.push_back(i);
			ans.push_back(j);
			auto [v, ch] = brute(p+1);
			uh[j] = ch;
			good = max(good, v);
			qs.pop_back();
			ans.pop_back();
		}
		res = min(res, 1+good);
		if(res == 1+good) {
			node->q = i;
			node->l = uh[0];
			node->r = uh[1];
		}
	}
	return {res, node};
}
void print(Node *v, string pad = "") {
	if(!v) return;
	if(v->q < 0) {
		cout << pad << "A " << v->q <<endl;
		return;
	}
	cout <<pad<< "Q " << v->q << endl;
	cout <<pad<< "IF 0" << endl;
	print(v->l, pad + "\t");
	cout<<pad<< "IF 1" << endl;
	print(v->r, pad + "\t");
}

mt19937 rng(55);
const int local = 0;
namespace UHH {
	int guess = 2;
	int last_lie = 0;
}
int ask(basic_string<int> a) {
	cout << "? " << a.size() << " ";
	for(auto &i : a) cout << i << " ";cout << endl;
	string s;
	if(local) {
		int ok = 0;
		for(auto i : a) ok |= i == UHH::guess;
		if(!UHH::last_lie && (rng() % 2)) {
			UHH::last_lie = 1;
			ok ^= 1;
			cout << "lie\n";
		} else UHH::last_lie = 0;
		s = ok ? "YES" : "NO";
		cout << "> " << s << endl;
	} else {
		cin >> s;
	}
	return s[0] == 'Y';
}

basic_string<int> iter3(array<basic_string<int>, 3> a) {
	int A = ask(a[1] + a[2]);
	if(A == 1) {
		int pA = ask(a[1] + a[2]);
		if(A == pA) {
			return A ? a[1] + a[2] : a[0];
		}
		A = 0;
	}
	int B = ask(a[0] + a[2]);
	return B == 0 ? a[0] + a[1] : a[0] + a[2];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	// auto [ans, pn] = brute(0);
	// cout << ans << endl;
	// print(pn);
	int n;
	if(local) {
		n = 5;
	} else {
		cin >> n;
	}
	basic_string<int> have(n, 0);
	iota(all(have), 1);
	while(have.size() > 2) {
		array<basic_string<int>, 3> a;
		for(int i = 0; i < have.size(); i++)
			a[i%3].push_back(have[i]);
		have = iter3(a);
	}
	cout << "! " << have[0] << endl;
	string s;
	cin >> s;
	if(s != ":)") cout << "! " << have[1] << endl;
}