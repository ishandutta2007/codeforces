#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define pb push_back
#define ar array
#define sz(v) int(v.size())
#define vt vector
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__) 
#define EACH(x, a) for (auto& x: a)
void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}

}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
	EACH(a, x)
		read(a);
}
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
	bool f=1;
	string res;
	EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
	return res;
}

template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}
template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
}






















// #define BRUH 0
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	// int t = 1;
	while(t--) {
		int n, k, l, r;
		cin >> n >> l >> r >> k;
		int len = r - l + 1;
		int rs = k;
		
		for(int i = n, cnt = 0; cnt < len && i >= 1; i--, ++cnt) {
			rs -= i;
		}
		if(rs > 0) {
			cout << -1 << ""<< "\n";
			continue;
		}
		vector<int> a(n);
		vector<int> res;
		int s = 0;
		for(int i = 0; i < len; i++) {
			res.push_back(i + 1);
			s += (i + 1);
		}
		// print(res);
		if(s > k) {
			cout << -1 << "" << "\n";
			// return;
			continue;
		}
		int dist = k - s;
		// print("HERE IS DIST: ", dist);
		int mx = n;
		for(int i = len - 1; i >= 0; i--) {
			if(dist == 0) continue;
			if(mx - res[i] >= dist) {
				int es = mx - res[i];
				res[i] += dist;
				dist = 0;
				// res[i] += dist;
				// cout << "ITS GOO";
				break;
			} else {
				dist -= (mx - res[i]);
				res[i] = mx;
				// --mx;
				// dist -= (res[i] - mx);
				--mx;
			}
		}
		// print(dist);
		// print("HERE IS RES: ", res);
		if(dist > 0) {
			cout << -1 << "" << "\n";
			continue;
		}

		// print(res);
		// continue;
		// print(res);
		// continue;
		if((int)res.size() < len) {
			cout << -1 << "\n";
			continue;
		}
		// print(res);
		// continue;
		set<int> re;
		for(int i = 1; i <= n; i++) {
			re.insert(i);
		}
		// continue;
		for(int i : res) {
			re.erase(i);
		}
		// continue;

		for(int i = r; i < n; i++) {
			res.push_back(*re.begin());
			re.erase(re.begin());
		}
		// print(res);
		// continue;
		for(int i = 0; i < l - 1; i++) {
			// cout << i << endl;
			// break;
			assert(!re.empty());
			res.insert(res.begin(), *re.begin());
			re.erase(re.begin());
		}
		print(res);
	}
}







// look out for overflows + run on system plz
// and dumb stuff
// like you typically do :/