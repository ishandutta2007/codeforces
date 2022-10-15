#include<bits/stdc++.h>
using namespace std;
vector<char> opers;
int modulo(1e9 + 7);
typedef long long LL;
int pw(int x, int n) {
	int res(1);
	while(n) {
		if(n & 1)
			res = (LL)res * x % modulo;
		x = (LL)x * x % modulo;
		n /= 2;
	}
	return res;
}
inline bool isDigit(char c) {
	return c >= '0' && c <= '9';
}
const int N(111111);
char st[N];
struct Opad {
	string str;
	int val, mul;
	Opad() {
		val = 0;
		mul = 1;
	}
};
vector<Opad> opads;
void operate() {
	Opad o1, o2;
	o2 = opads.back();
	opads.pop_back();
	o1 = opads.back();
	opads.pop_back();
	if(opers.back() == '+') {
		Opad res;
		res.val = ((LL)o1.val * o2.mul + o2.val) % modulo;
		res.mul = (LL)o1.mul * o2.mul % modulo;
		opads.push_back(res);
	}else {
		Opad res;
		for(int i((int)o1.str.size() - 1); i >= 0; i--) {
			for(int j(0); j < (int)o1.str[i] - '0'; j++) {
				res.val = ((LL)res.val * o2.mul + o2.val) % modulo;
				res.mul = ((LL)res.mul * o2.mul) % modulo;	
			}
			int mul(o2.mul), add(o2.val);
			for(int j(0); j < 9; j++) {
				o2.mul = ((LL)mul * o2.mul) % modulo;
				o2.val = ((LL)mul * o2.val + add) % modulo;
			}
		}
		opads.push_back(res);
	}
	opers.pop_back();
}
Opad calc(const string & a) {
	Opad res;
	res.str = a;
	for(int i(0); i < (int)a.size(); i++) {
		res.mul = res.mul * 10ll % modulo;
		res.val = (res.val * 10ll + a[i] - '0') % modulo;
	}
	return res;
}
Opad calc(const string & le, const string & ri) {
	//cout << le << ' ' << ri << endl;
	Opad res;
	Opad a(calc(le)), b(calc(ri));
	int phil(0), phir(0);
	for(int i(0); i < (int)le.size(); i++) {
		phil = ((LL)phil * 10ll + le[i] - '0') % (modulo - 1);
	}
	for(int i(0); i < (int)ri.size(); i++) {
		phir = ((LL)phir * 10ll + ri[i] - '0') % (modulo - 1);
	}
	//cout << a.val << ' ' << b.mul << endl;
	int cur(1), curphi(1);
	for(int i(1); i < le.size(); i++) {
		cur = cur * 10ll % modulo;
		curphi = curphi * 10ll % (modulo - 1);
	}
	for(int len(le.size()); len <= ri.size(); len++) {
		int leval, rival, lephi, riphi;
		if(len == le.size()) {
			leval = a.val;
			lephi = phil;
		}else {
			leval = cur;
			lephi = curphi;
		}
		if(len == ri.size()) {
			rival = b.val;
			riphi = phir;
		}else {
			rival = (cur * 10ll + modulo - 1) % modulo;
			riphi = (curphi * 10ll + modulo - 2) % (modulo - 1);
		}
		//printf("%d %d %d %d\n", leval, lephi, rival, riphi);
		int bs(pw(10, len));
		//cout << bs << endl;
		//cout << (rival + 1ll) * ((pw(bs, (riphi - lephi + modulo) % (modulo - 1)) - 1ll + modulo) * pw(bs - 1, modulo - 2) % modulo) % modulo << endl;
		//cout << ((rival - leval + 1ll + modulo) * pw(bs, (rival - leval + 1 + modulo) % (modulo - 1)) - (rival - leval + 2ll + modulo) * pw(bs, (riphi - lephi + modulo) % (modulo - 1)) + 1) % modulo * pw(bs - 1, modulo - 2) % modulo * pw(bs - 1, modulo - 2) % modulo << endl;
		//cout << ((rival + 1ll) * ((pw(bs, (riphi - lephi + modulo) % (modulo - 1)) - 1ll + modulo) * pw(bs - 1, modulo - 2) % modulo) % modulo - ((rival - leval + 1ll + modulo) * pw(bs, (rival - leval + 1 + modulo) % (modulo - 1)) - (rival - leval + 2ll + modulo) * pw(bs, (riphi - lephi + modulo) % (modulo - 1)) + 1) % modulo * pw(bs - 1, modulo - 2) % modulo * pw(bs - 1, modulo - 2) % modulo) << endl;
		int val = (((rival + 1ll) * ((pw(bs, (riphi - lephi + modulo) % (modulo - 1)) - 1ll + modulo) * pw(bs - 1, modulo - 2) % modulo) % modulo - ((rival - leval + 1ll + modulo) * pw(bs, (riphi - lephi + 1 + modulo) % (modulo - 1)) - (rival - leval + 2ll + modulo) * pw(bs, (riphi - lephi + modulo) % (modulo - 1)) + 1) % modulo * pw(bs - 1, modulo - 2) % modulo * pw(bs - 1, modulo - 2) % modulo) + modulo) % modulo;
		int mul = pw(bs, (riphi - lephi + modulo) % (modulo - 1));
		res.val = ((LL)res.val * mul + val) % modulo;
		res.mul = (LL)res.mul * mul % modulo;
		//cout << val << ' ' << mul << endl;
		cur = cur * 10ll % modulo;
		curphi = curphi * 10ll % (modulo - 1);
	}
	return res;
}
int main() {
	scanf("%s", st);
	int len(strlen(st));
	for(int i(0); i < len; i++) {
		if(isDigit(st[i])) {
			string s;
			int j(i);
			for( ; isDigit(st[j]); j++)
				s.push_back(st[j]);
			if(st[j] == '-') {
				string t;
				for(j++; isDigit(st[j]); j++)
					t.push_back(st[j]);
				opads.push_back(calc(s, t));
			}else {
				opads.push_back(calc(s));
			}
			i = j - 1;
		}else if(st[i] == '(') {
			opers.push_back('(');
		}else if(st[i] == '+') {
			opers.push_back('+');
		}else if(st[i] == ')') {
			while(opers.back() != '(') {
				operate();	
			}
			operate();
		}
	}
	while(opers.size())
		operate();
	cout << opads.back().val << endl;
}