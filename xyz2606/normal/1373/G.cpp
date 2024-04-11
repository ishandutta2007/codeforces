#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
const int N = 400033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mx[N * 4], tag[N * 4];
const int L = 400000;
void pushdown(int k) {
	tag[k * 2] += tag[k];
	mx[k * 2] += tag[k];
	tag[k * 2 + 1] += tag[k];
	mx[k * 2 + 1] += tag[k];
	tag[k] = 0;
}
void build(int k, int le, int ri) {
	mx[k] = ri;
	if(le != ri) {
		int mid = (le + ri) / 2;
		build(k * 2, le, mid);
		build(k * 2 + 1, mid + 1, ri);
	}
}
void add(int k, int le, int ri, int pos, int delta) {
	if(ri <= pos) {
		mx[k] += delta;
		tag[k] += delta;
	}else {
		int mid = (le + ri) / 2;
		pushdown(k);
		add(k * 2, le, mid, pos, delta);
		if(pos > mid) add(k * 2 + 1, mid + 1, ri, pos, delta);
		mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
	}
}
int getmax(int k, int le, int ri, int qr) {
	if(ri <= qr) {
		return mx[k];
	}else {
		int mid = (le + ri) / 2;
		pushdown(k);
		int res = getmax(k * 2, le, mid, qr);
		if(qr >= mid + 1) res = max(res, getmax(k * 2 + 1, mid + 1, ri, qr));
		return res;
	}
}
int main() {
	int n, k, m;
	n = getInt(); k = getInt(); m = getInt();
	build(1, 1, L);
	map<int, int> sp;
	set<pair<int, int> > st;
	for(int i = 1; i <= m; i++) {
		int x, y;
		x = getInt();
		y = getInt();
		int pos = y + abs(x - k);
		if(st.count(make_pair(x, y))) {
			st.erase(make_pair(x, y));
			sp[pos]--;
			if(sp[pos] == 0) sp.erase(pos);
			add(1, 1, L, pos, -1);
		}else {
			st.insert(make_pair(x, y));
			sp[pos]++;
			add(1, 1, L, pos, 1);
		}
		//cout << sp.rbegin()->fi << endl;
		printf("%d\n", sp.size() == 0 ? 0 : max(0, getmax(1, 1, L, sp.rbegin()->fi) - n - 1));
	}
}