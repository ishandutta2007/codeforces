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
const int B = 200;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int nxt[N], prv[N], a[N];
char st[N];
int main() {
	scanf("%s", st + 1);
//for(int i(1); i <= 200000; i++) st[i] = '1';
//st[200001] = 0;
	int n = strlen(st + 1);
	for(int i(1); i <= n; i++) {
		a[i] = a[i - 1] + (st[i] == '1');
	}
	nxt[n + 1] = n + 1;
	for(int i(n); i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		if(st[i] == '1') nxt[i] = i;
	}
	prv[0] = 0;
	for(int i = 1; i <= n; i++) {
		prv[i] = prv[i - 1];
		
		if(st[i] ==  '1') prv[i] = i;
		//printf("prv[%d] = %d\n", i, prv[i]);
	}
	LL ans = 0;
	for(int i(1); i <= n; i++) {
		int cnt = 1;
		for(int j = nxt[i]; j <= n && cnt * B <= n; j = nxt[j + 1], cnt++) {
			//cout << i << ' ' << j << endl;
			int len = j  - i + 1;
			int l1 = len;
			len += nxt[j + 1] - j - 1;
			//len += i - 1 - prv[i - 1];
			//cout << len << endl;
			int le = (j - i + 1 + cnt - 1) / cnt;
			int ri = len / cnt;
			le = max(le, B);
			if(ri >= le) {
				//x: min(x * cnt - l1 + 1, len - x * cnt + 1)
				ans += ri - le + 1;
			}

		}
	}
	//cout << ans << endl;
	for(int i = 1; i < B; i++) {
		static vector<LL> vec;
		vec.clear();
		for(int j = 0; j <= n; j++) {
			vec.push_back((LL)a[j] * i - j);
			//cout << a[j] * i - j << endl;
		}
		sort(vec.begin(), vec.end());
		for(int j = 0, k; j <= n; j = k) {
			for(k = j; k <= n && vec[j] == vec[k]; k = k + 1);
			ans += (LL)(k - j) * (k - j - 1ll) / 2;
		}
	}
	cout << ans << endl;
}