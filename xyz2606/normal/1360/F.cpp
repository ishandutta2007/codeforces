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

const int N = 15;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char a[N][N];
int dp[N][1024];

string u[N][1024];

int main() {
	int t;
	cin >> t;
	for(int qq = 1; qq <= t; qq++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("%s", a[i]);
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		u[0][0].clear();
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < (1 << n); j++) {
				if(dp[i][j] == 0) continue;
				for(char c = 'a'; c <= 'z'; c++) {
					int msk = 0;
					for(int k = 0; k < n; k++) {
						if(a[k][i] != c) {
							msk |= 1 << k;
						}
					}
					if((msk & j) == 0) {
						dp[i + 1][j | msk] = 1;
						u[i + 1][j | msk] = u[i][j] + c;
					}
				}
			}
		}
		string ans = "-1";
		for(int j = 0; j < (1 << n); j++) {
			if(dp[m][j]) {
				ans = u[m][j];
				break;
			}
		}
		cout << ans << endl;
	}
}