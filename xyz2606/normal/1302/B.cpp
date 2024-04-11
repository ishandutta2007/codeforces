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

inline int fastpo(int x, int n, int mod) {
	int res(1);
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

const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ext[N];
deque<int> q;
int t[N];
int debug = 0;
void reset() {
	if(debug) {
		q.clear();
	}else {
		cout << "R" << endl;
	}
}
int cq = 0;
int ask(int i) {
	if(debug) {
		cq++;
		bool res = find(q.begin(), q.end(), t[i]) != q.end();
		q.push_back(t[i]);
		if((int)q.size() > k) q.pop_front();
		return res;
	}else {
		cout << "? " << i << endl;
		string st;
		cin >> st;
		return st == "Y";
	}
}
void calc(int le, int ri) {

	if(ri == k) {
		for(int i(1); i <= k; i++) {
			ext[i] = !ask(i);
		}
		return;
	}
	for(int delta(1); delta <= n / k - 1; delta++) {
		reset();
		for(int s = 0; s < delta; s++) {
			if(le + s * k + delta * k > ri) continue;
			for(int i(le + s * k); i <= ri; i += delta * k) {
				for(int l = i; l <= min(i + k - 1, ri); l++) {	
					if(ext[l]) ext[l] = !ask(l);	
				}
			}
		}
		//cout << cq << endl;
	}
	for(int delta(1); delta <= n / k - 1; delta++) {
		reset();
		for(int s = 0; s < delta; s++) {
			if(le + s * k + delta * k > ri) continue;
			for(int i(le + s * k); i <= ri; i += delta * k) {
				for(int l = min(i + k - 1, ri); l >= i; l--) {
					if(ext[l]) ext[l] = !ask(l);
				}
			}
		}
	}
}
int main() {
	if(debug) {
		n = 16; k = 1;
		for(int i(1); i <= n; i++) {
			t[i] = i;//gene() % n + 1;
			printf("t[%d] = %d\n", i, t[i]);
		}
		for(int i(1); i <= n; i++) {
			ext[t[i]] = 1;
		}
		int ans = 0;
		for(int i(1); i <= n; i++) ans += ext[i];
		printf("std = %d\n", ans);
	}else {
		cin >> n >> k;
	}	
	for(int i(1); i <= n; i++) ext[i] = 1;
	calc(1, n);
	int cnt = 0;
	for(int i(1); i <= n; i++) cnt += ext[i];
	cout << "! " << cnt << endl;
	if(debug) cout << "cq = " << cq << endl;
}