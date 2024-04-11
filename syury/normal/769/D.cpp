#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

typedef vector<lint> poly;

void wht(poly & p, bool inv){
	int n = p.size();
	for(int len = 1; len + len <= n; len <<= 1){
		for(int i = 0; i < n; i += len + len){
			F(j, 0, len){
				lint u = p[i + j];
				lint v = p[i + j + len];
				p[i + j] = u + v;
				p[i + j + len] = u - v;
			}
		}
	}
	if(inv){
		F(i, 0, n)p[i] /= n;
	}
}

poly mp(poly & a, poly & b){
	wht(a, false);
	wht(b, false);
	F(i, 0, (int)a.size())a[i] *= b[i];
	wht(a, true);
	ret a;
}

int n;
int k;
const int MAXN = 1e5 + 5;
const int POW = 1 << 14;
int a[MAXN];
poly fp, sp, ap;

int main(){
	scanf("%d %d", &n, &k);
	fp.rs(POW); fp.asg(POW, 0);
	F(i, 0, n){
		scanf("%d", &a[i]);
		fp[a[i]]++;
	}
	sp = fp;
	ap = mp(fp, sp);
	lint ans = 0;
	F(i, 0, POW){
		if(__builtin_popcount(i) == k)ans += ap[i];
	}
	if(k == 0)ans -= n;
	printf("%lld", ans/2);
	ret 0;
}