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

const int N = 1000011;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq = 1; qq <= tests; qq++) {
		int x;
		scanf("%d", &x);
		static char st[N];
		scanf("%s", st + 1);
		int len = strlen(st + 1);
		int lm = len;
		for(int i(1); i <= x; i++) {
			if(st[i] == '1') {
			}else {
				int nw = lm;
				for(int j = lm + 1; j <= min(x, lm + (lm - i) * (st[i] - '0' - 1)); j++) {
					nw = j;
					st[j] = st[i + 1 + (j - lm - 1) % (lm - i)];
				}
				lm = nw;
			}
			//cout << len - i << ' ' << (st[i] - '0') << endl;
			len = (i + (LL)(len - i + mod) * (st[i] - '0')) % mod;
		}
		cout << len << endl;
	}
}