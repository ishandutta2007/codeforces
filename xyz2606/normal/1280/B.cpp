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

const int N = 66;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int s[N][N];
char a[N][N];
int main() {
	int tests;
	scanf("%d", &tests);
	for(int qq = 1; qq <= tests; qq++) {
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt = 0;
		for(int i(1); i <= n; i++) {
			scanf("%s", a[i] + 1);
			for(int j = 1; j <= m; j++) {
				cnt += a[i][j] == 'A';
			}
		}
		if(!cnt) {
			printf("MORTAL\n");
			continue;
		}
		
		for(int i(1); i <= n; i++) {
			for(int j(1); j <= m; j++) {
				s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + (a[i][j] == 'A');
			//	printf("%d ", s[i][j]);
			}
			//printf("\n");
		}
		int ans = 4;

		if(s[1][m] == m || s[n][1] == n || (s[n][m] - s[n - 1][m] == m) || (s[n][m] - s[n][m - 1] == n)) {
			ans = 1;
		}else if(a[1][1] == 'A' || a[1][m] == 'A' || a[n][1] == 'A' || a[n][m] == 'A') {
			ans = 2;
		}else {
			for(int i(1); i <= n; i++) {
				if(s[i][m] - s[i - 1][m] == m) {
					ans = 2;
				}
			}
			for(int i(1); i <= m; i++) {
				if(s[n][i] - s[n][i - 1] == n) {
					ans = 2;
				}
			}
		}
		if(ans == 4 && (s[1][m] || s[n][1] || (s[n][m] - s[n - 1][m]) || (s[n][m] - s[n][m - 1]))) ans = 3;
		if(s[n][m] == n * m) ans = 0;
		printf("%d\n", ans);
	}
}