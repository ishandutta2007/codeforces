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

lint gcdex(lint a, lint b, lint & x, lint & y){
	if(a == 0){x = 0; y = 1; ret b;}
	lint x1, y1;
	lint g = gcdex(b % a, a, x1, y1);
	y = x1;
	x = y1 - x1 * (b/a);
	ret g;
}

int inv(int a, int mod){
	lint x, y;
	gcdex(a, mod, x, y);
	x = ((x % mod) + mod) % mod;
	ret (int)x;
}

int n, dx, dy, m;
vector<pair<int, int> > a;
map<int, int> cnt;
int best = 0;
int bx, by;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	if(n == 1){printf("%d %d", 0, 0); ret 0;}
	a.rs(m);
	F(i, 0, m)
		scanf("%d%d", &a[i].X, &a[i].Y);
	F(i, 0, m){
		lint r = (-a[i].X) * 1ll * inv(dx, n);
		r %= n;
		lint cy = a[i].Y + r * 1ll * dy;
		cy %= n;
		cy = (cy + n)%n;
		//printf("For i = %d cy = %d\n", i, (int)cy);
		cnt[(int)cy]++;
		if(cnt[(int)cy] > best){best = cnt[(int)cy]; by = (int)cy;}
	}
	printf("%d %d", 0, by);
	ret 0;
}