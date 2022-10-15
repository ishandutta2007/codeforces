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
LL a[N], b[N];
LL LIM = 2e5;
void no() {
	printf("IMPOSSIBLE\n");
	exit(0);
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	if(n == 1) {
		if(b[1] == a[1]) {
			printf("SMALL\n0\n\n");
		}else printf("IMPOSSIBLE\n");
		return 0;
	}
	vector<pair<LL, char> > seq;
	LL ans = 0;
	
	if(n == 2) {
		while(!(b[1] == a[1] && b[2] == a[2])) {
			LL delta = b[1] + b[2] - a[1] - a[2];
			//cout << delta << endl;
			if(delta <= 0) break;
			if(b[1] > b[2]) {
				LL t = min(delta / b[2], b[1] / b[2]);
				b[1] -= t * b[2];
				if(t == 0 || b[1] == 0) break;
				ans += t;
				seq.pb({t, 'T'});
			}else if(b[1] < b[2]) {
				LL t = min(delta / b[1], b[2] / b[1]);
				b[2] -= t * b[1];
				if(t == 0 || b[2] == 0) break;
				ans += t;
				seq.pb({t, 'S'});
			}else break;
		}
	}else {
		LL sum = 0;
		for(int i = 1; i <= n; i++) sum += a[i];
		for(;;) {
			LL sb = 0;
			for(int i = 1; i <= n; i++) sb += b[i];
			if(sb <= sum) break;
			if(b[1] == b[2]) no();

			for(int i = 2; i < n; i++) {
				if(b[i] == b[i + 1]) no();
				if((b[i] < b[i + 1]) != (b[1] < b[2])) no();
			}
			ans++;
			if(b[1] < b[2]) {
				seq.pb({1, 'S'});
				for(int i = n; i >= 2; i--) b[i] -= b[i - 1];
			}else {
				seq.pb({1, 'T'});
				for(int i = 1; i < n; i++) b[i] -= b[i + 1];
			}

		}
	}
	bool flag1 = true, flag2 = 1;
	for(int i = 1; i <= n; i++) {
		flag1 &= a[i] == b[i];
		flag2 &= a[i] == b[n - i + 1];
	}
	if(flag2) seq.pb({1, 'R'});
	else if(!flag1) no();
	if(ans > LIM) printf("BIG\n%I64d\n", ans);
	else {
		printf("SMALL\n");
		string t;
		for(int i = (int)seq.size() - 1; i >= 0; i--) {
			if(seq[i].se == 'R') t.pb('R');
			else {
				for(int j = 0; j < seq[i].fi; j++) {
					if(seq[i].se == 'T') {
						if(!t.empty() && t.back() == 'R') t.pop_back();
						else t.pb('R');
						t.pb('P');
						t.pb('R');
					}else t.pb('P');
				}
			}
		}
		printf("%d\n", t.size());
		cout << t << endl;
		return 0;
	}

}