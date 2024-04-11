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

const int N = 7007;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
LL a[N], b[N];
int ind[N];
bool mp[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) cin >> a[i];
	for(int j(1); j <= n; j++) cin >> b[j];
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= n; j++) {
			if(j == i) continue;
			mp[j][i] = (a[i] & a[j]) == a[i];
			ind[i] += mp[j][i];
			//cout << i << ' ' << ind[i] << endl;
		}
	}
	vector<int> q;
	q.clear();

	for(int i(1); i <= n; i++) if(ind[i] == 0) {
		q.push_back(i);
	}
	for(int op(0); op < (int)q.size(); op++) {
		int v = q[op];
		for(int j(1); j <= n; j++) {
			if(!mp[v][j]) continue;
			if(!--ind[j]) {
				q.push_back(j);
			}
		}
	}
	LL ans = 0;
	for(int i(1); i <= n; i++) ans += b[i];
	for(int i : q) ans -= b[i];
	cout << ans << endl;
}