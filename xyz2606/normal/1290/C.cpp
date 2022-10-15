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
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int fix[N], val[N], cnt[2][N], rela[N], delta[N];
vector<int> vec[N];
char st[N];
int getr(int x) {
	int p = x, sum = 0;
	while(p != rela[p]) {
		sum ^= delta[p];
		p = rela[p];
	}
	int p1 = p; p = x;
	while(p != rela[p]) {
		int p2 = rela[p];
		swap(delta[p], sum);
		sum = delta[p] ^ sum;
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", st + 1);
	for(int i(1); i <= k; i++) {
		int m;
		scanf("%d", &m);
		for(int j(1); j <= m; j++) {
			int x;
			scanf("%d", &x);
			vec[x].push_back(i);
		}
	}
	for(int i(1); i <= k; i++) {
		rela[i] = i;
	}
	int ans = 0;
	auto calc = [&](int x) {
		assert(x == rela[x]);
		if(fix[x]) {
			return cnt[val[x] ^ 1][x];
		}else return min(cnt[0][x], cnt[1][x]);
	};
	for(int i(1); i <= k; i++) {
		cnt[0][i] = 1; cnt[1][i] = 0;
	}
	for(int i(1); i <= n; i++) {
		if(vec[i].size() == 0) {
		}else if(vec[i].size() == 1) {
			int x = vec[i][0];
			int fx = getr(x);
			int valx = (st[i] == '0');
			//if(fix[fx] == 0) {
			ans -= calc(fx);
			//assert(fix[fx] == false || val[fx] == (valx ^ delta[x]));
			fix[fx] = true;
			val[fx] = valx ^ delta[x];
			ans += calc(fx);
			//}
		}else {
			int x = vec[i][0], y = vec[i][1];
			int fx = getr(x), fy = getr(y);
			int dif = (st[i] == '0');
			if(fx == fy) {
				ans -= calc(fx);
			}else {
				ans -= calc(fx) + calc(fy);
			}
			if(fx != fy) {
				rela[fy] = fx;
				delta[fy] = delta[x] ^ delta[y] ^ dif;
				if(fix[fy]) {
					fix[fx] = true;
					val[fx] = val[fy] ^ delta[fy];
				}
				for(int d = 0; d < 2; d++) {
					//cout << cnt[d][fx] << ' ' << cnt[d ^ delta[fy]][fy] << endl;
					cnt[d][fx] += cnt[d ^ delta[fy]][fy];
				}

			}
			//cout << cnt[0][fx] << ' ' << cnt[1][fx] << endl;
			//cout << cnt[0][fy] << ' ' << cnt[1][fy] << endl;
			ans += calc(fx);
		}
		printf("%d\n", ans);
	}
}