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
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
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

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

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
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
const int N = 23;
const int LOG = 20;
const int mod = 998244353;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
const int A = 26;
int dy[4] = {0, 1, 0, -1};
short cnt[1 << N][A];
int ans[1 << N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		static char st[22222];
		scanf("%s", st);
		int len = strlen(st);
		for(int j = 0; j < len; j++) {
			cnt[1 << i][st[j] - 'a']++;
		}
	}
	for(int msk = 1; msk < (1 << n); msk++) {
		int lb = (msk & (-msk));
		if(msk != lb) {
			for(int j = 0; j < A; j++) {
				cnt[msk][j] = min(cnt[lb][j], cnt[msk - lb][j]);	
			}
		}
		ans[msk] = 1;
		for(int j = 0; j < A; j++) {
			ans[msk] = (ans[msk] * (LL)(cnt[msk][j] + 1)) % mod;
		}
		//printf("%d %d\n", msk, ans[msk]);
		if(__builtin_popcount(msk) & 1) {
			
		}else ans[msk] = (mod - ans[msk]) % mod;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (1 << n); j++) {
			if(j & (1 << i)) {
				ans[j] = (ans[j] + ans[j - (1 << i)]) % mod;
			}
		}
	}
	LL tot =0;
	for(int j = 0; j < (1 << n); j++) {
		//printf("%d %d\n", j, ans[j]);
		
		LL tmp = 0;
		for(int i = 0; i < n; i++) {
			if(j & (1 << i)) {
				tmp = tmp + i + 1;
			}
		}
		tmp = tmp * __builtin_popcount(j);
		tmp = tmp * ans[j];
		tot ^= tmp;
	}
	cout << tot << endl;
}