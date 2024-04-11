#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<list>
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

const int N = 100011;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> e[N];
bool big[N];
vector<int> b[N];
LL od[N];
list<int>::iterator pos[340][N];
int a[N], num[N];
list<int> lk[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		od[max(x, y)]++;
	}
	LL ans = 0;
	for(int i(1); i <= n; i++) a[i] = i;
	for(int i(1); i <= n; i++) {
		ans = ans + (LL)od[i] * (e[i].size() - od[i]);
	}
	cout << ans << endl;
	int nb = 0;
	for(int i(1); i <= n; i++) {
		big[i] = e[i].size() >= 600;
		if(big[i]) num[i] = ++nb;
	}

	for(int i(1); i <= n; i++) {
		if(big[i]) {
			for(int j : e[i]) {
				lk[i].push_back(j);
				pos[num[i]][j] = lk[i].end();
				pos[num[i]][j]--;
			}
		}
		for(int j : e[i]) {
			if(big[j]) {
				b[i].push_back(j);
			}
		}
	}
	for(int i(1); i <= n; i++) {
		for(int j : b[i]) {
			lk[j].erase(pos[num[j]][i]);
			lk[j].push_back(i);
			(pos[num[j]][i] = lk[j].end())--;
		}
	}

	int Q;
	scanf("%d", &Q);
	for(int i(0); i < Q; i++) {
		int v;
		scanf("%d", &v);
		
		if(big[v]) {
			for(auto itr = lk[v].rbegin(); itr != lk[v].rend(); itr++) {
				if(a[*itr] < a[v]) break;
				ans = ans - (LL)(od[*itr]) * (e[*itr].size() - od[*itr]);
				od[*itr] -= 1;
				ans = ans + (LL)(od[*itr]) * (e[*itr].size() - od[*itr]);
			}
			a[v] = Q + i + 1;
			ans -= (LL)od[v] * (e[v].size() - od[v]);
			od[v] = e[v].size();
		}else {
			for(int u : e[v]) {
				if(a[u] < a[v]) continue;
				ans = ans - (LL)(od[u]) * (e[u].size() - od[u]);
				od[u] -= 1;
				ans = ans + (LL)(od[u]) * (e[u].size() - od[u]);
			}
			a[v] = Q + i + 1;
			ans -= (LL)od[v] * (e[v].size() - od[v]);
			od[v] = e[v].size();
		}
		for(int j : b[v]) {
			lk[j].erase(pos[num[j]][v]);
			lk[j].push_back(v);
			(pos[num[j]][v] = lk[j].end())--;
		}
		cout << ans << endl;
	}
}