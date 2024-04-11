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

const int N = 5555;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], s[N], c[N], le[N], ri[N];
vector<pair<int, int> >  cows[N];
vector<int> pos[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	for(int i(1); i <= m; i++) {
		scanf("%d%d", &s[i], &c[i]);
		if(c[i]  > pos[s[i]].size()) {
			le[i] = ri[i] = inf;
		}else {
			le[i] = pos[s[i]][c[i] - 1];
			ri[i] = pos[s[i]][pos[s[i]].size() - c[i]];
		}
		if(le[i] != inf) cows[s[i]].pb({le[i], ri[i]});
	}
	le[0] = 0;
	int mx = 0, mxc = 0;
	for(int i(0); i <= m; i++) {
		
		if(le[i] == inf) continue;
		
		int ans = 0,  c = 1;
		for(int j(1); j <= n; j++) {

			int cl = 0, cr = 0, cb = 0;
			for(auto tmp : cows[j]) {
				if(tmp.fi == le[i] && tmp.se == ri[i]) {
				}else if(tmp.fi < le[i] && tmp.se > le[i]) {
					cb++;
				}else if(tmp.fi < le[i]) {
					cl++;
				}else if(tmp.se > le[i]) cr++;
			}
			if(i == 0 || i > 0 && j == s[i]) {
				cl = 0;
				cr += cb;
				cb = 0;
			}
			if(cb == 0 && cl == 0 &&  cr== 0) {
				
			}else if(cb == 0 && cl == 0) {
				ans += 1;
				c = (LL)c * cr % mod;
			}else if(cb == 0 && cr == 0) {
				ans += 1;
				c  = (LL)c * cl % mod;
			}else if(cb == 1 && cl == 0 && cr ==  0) {
				ans += 1;
				c  = (LL)c * 2 % mod;
			}else {
				ans += 2;
				int tmp = 0;
				tmp = tmp + cl * (cr + cb);
				tmp = tmp + cb * (cb + cr - 1);
				c = (LL)c * tmp % mod;
			}
		}
		if(i) ans++;
		//cout << ans << ' ' << c << endl;
		if(ans > mx) {
			mx = ans, mxc = c;
		}else if(ans == mx) {
			mxc = (mxc + c) % mod;
		}
	}
	printf("%d %d\n", mx, mxc);
}