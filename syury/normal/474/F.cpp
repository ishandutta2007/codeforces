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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e5 + 5;
const int TSZ = 4 * MAXN;
const int inf = 1e9 + 9;

int tm[TSZ], cnt[TSZ], g[TSZ];
int n;
int s[MAXN];
int q;

void build(int v, int l, int r){
	if(l == r){
		tm[v] = s[l]; cnt[v] = 1; g[v] = s[l];
		ret;
	}
	int mid = (l + r) >> 1;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
	g[v] = __gcd(g[2*v], g[2*v + 1]);
	tm[v] = min(tm[2*v], tm[2*v + 1]);
	cnt[v] = 0;
	if(tm[v] == tm[2*v])cnt[v] += cnt[2*v];
	if(tm[v] == tm[2*v + 1])cnt[v] += cnt[2*v + 1];
}

pair<int, int> get_min(int v, int l, int r, int ul, int ur){
	if(ul > ur)ret mk(inf, 0);
	if(l == ul && r == ur)ret mk(tm[v], cnt[v]);
	int mid = (l + r) >> 1;
	pair<int, int> al = get_min(2*v, l, mid, ul, min(ur, mid));
	pair<int, int> ar = get_min(2*v + 1, mid + 1, r, max(ul, mid + 1), ur);
	if(al.X > ar.X)swap(al, ar);
	if(al.X == ar.X)al.Y += ar.Y;
	ret al;
}

int get_gcd(int v, int l, int r, int ul, int ur){
	if(ul > ur)ret 0;
	if(l == ul && r == ur)ret g[v];
	int mid = (l + r) >> 1;
	ret __gcd(get_gcd(2*v, l, mid, ul, min(ur, mid)), get_gcd(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &s[i]);
	build(1, 0, n - 1);
	scanf("%d", &q);
	F(i, 0, q){
		int l, r;
		scanf("%d%d", &l, &r); l--; r--;
		pair<int, int> a = get_min(1, 0, n - 1, l, r);
		int gg = get_gcd(1, 0, n - 1, l, r);
		printf("%d\n", (a.X == gg) ? (r - l + 1 - a.Y) : (r - l + 1));
	}
	ret 0;
}