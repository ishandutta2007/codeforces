#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

string add(string a, string b) {
	vector<char> v(max(a.length(), b.length()), 0);
	for(int i = 0; i < (int)a.length(); i++) v[(int)a.length()-1-i] += a[i]-'0';
	for(int i = 0; i < (int)b.length(); i++) v[(int)b.length()-1-i] += b[i]-'0';
	for(int i = 0; i < (int)v.size(); i++) {
		if(v[i] < 10) continue;
		if(i == (int)v.size()-1) v.push_back(0);
		v[i+1] += v[i]/10;
		v[i] %= 10;
	}
	while((int)v.size() > 1 && v.back() == 0) v.pop_back();
	string ret;
	for(int i = (int)v.size()-1; i >= 0; i--) ret += char('0'+v[i]);
	return ret;
}

bool cmp(string a, string b) { // a >= b
	if(a.length() > b.length()) return true;
	if(a.length() < b.length()) return false;
	for(int i = 0; i < (int)a.length(); i++) if(a[i] != b[i]) return a[i] > b[i];
	return true;
}

string sub(string a, string b) {
	vector<char> v(max(a.length(), b.length()), 0);
	for(int i = 0; i < (int)a.length(); i++) v[(int)a.length()-1-i] += a[i]-'0';
	for(int i = 0; i < (int)b.length(); i++) v[(int)b.length()-1-i] -= b[i]-'0';
	for(int i = 0; i < (int)v.size(); i++) {
		if(v[i] < 10 && v[i] >= 0) continue;
		if(i == (int)v.size()-1) v.push_back(0);
		if(v[i] < 0) {
			v[i+1] -= (-v[i])/10+1;
			v[i] += ((-v[i])/10+1)*10;
		}
		if(v[i] >= 10) {
			v[i+1] += v[i]/10;
			v[i] %= 10;
		}
	}
	while((int)v.size() > 1 && v.back() == 0) v.pop_back();
	string ret;
	for(int i = (int)v.size()-1; i >= 0; i--) ret += char('0'+v[i]);
	return ret;
}

string mod(string a, string b) {
	static vector<string> pw;
	pw = {b};
	while(cmp(a, pw.back())) {
		a = sub(a, pw.back());
		pw.push_back(add(pw.back(), pw.back()));
	}
	while(cmp(a, b)) {
		if(cmp(a, pw.back())) {
			a = sub(a, pw.back());
			continue;
		}
		pw.pop_back();
	}
	return a;
}

string div(string a, string b) {
	static vector<string> pw;
	static vector<string> mul;
	pw = {b};
	mul = {"1"};
	string res = "0";
	while(cmp(a, pw.back())) {
		a = sub(a, pw.back());
		res = add(res, mul.back());
		pw.push_back(add(pw.back(), pw.back()));
		mul.push_back(add(mul.back(), mul.back()));
	}
	while(cmp(a, b)) {
		if(cmp(a, pw.back())) {
			a = sub(a, pw.back());
			res = add(res, mul.back());
			continue;
		}
		pw.pop_back();
		mul.pop_back();
	}
	return res;
}

string gcd(string a, string b) {
	while(a != "0") {
		b = mod(b, a);
		swap(a, b);
	}
	return b;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string N;
	cin >> N;
	srand(N.length());
	vector<string> fac(1, N);
	for(int i = 0; i < 30; i++) {
		string x;
		for(int j = 0; j < 150; j++) {
			if(j == 0) x += ('1'+rand()%9);
			else x += ('0'+rand()%10);
		}
		x = mod(x, N);
		cout << "* " << x << " " << x << endl;
		string a;
		cin >> a;
		cout << "sqrt " << a << endl;
		string y;
		cin >> y;
		if(x == y) continue;
		if(y != "-1" && add(x, y) == N) continue;
		string d = (y == "-1") ? x : add(x, y);
		vector<string> fac_nw;
		for(int j = 0; j < (int)fac.size(); j++) {
			string c = gcd(fac[j], d);
			if(c != "1" && c != fac[j]) {
				fac_nw.push_back(c);
				fac_nw.push_back(div(fac[j], c));
			}
			else fac_nw.push_back(fac[j]);
		}
		fac = fac_nw;
	}
	cout << "! " << fac.size() << "\n";
	for(int i = 0; i < (int)fac.size(); i++) cout << fac[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing