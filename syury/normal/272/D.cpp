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
#define tm afhdhn

const int MAXN = 2e5 + 5;

lint f[MAXN], pw[MAXN];
int n, m;
vector<pair<int, int> > a;

lint p2(int a){
	if(a == 0)ret 1ll;
	lint pr = p2(a >> 1);
	if(a&1)ret 2 * pr * pr % m;
	else ret pr * pr % m;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(2 * n);
	F(i, 0, n)scanf("%d", &a[i].X), a[i].Y = i + 1;
	F(i, 0, n)scanf("%d", &a[i + n].X), a[i + n].Y = i + 1;
	scanf("%d", &m);
	f[0] = 1ll; pw[0] = 0;
	F(i, 1, 2 * n + 1){
		pw[i] = pw[i - 1];
		int t = i;
		while(!(t&1)){t >>= 1; pw[i]++;}
		f[i] = f[i - 1] * t % m;
	}
	lint ans = 1ll;
	sort(all(a));
	int c = 0, c2 = 0;
	F(i, 0, 2 * n){
		if(i > 0 && a[i].X != a[i - 1].X){
			if(c > 1){
				lint curr = f[c] * p2(pw[c] - c2) % m;
				ans = ans * curr % m;
			}
			c = 1; c2 = 0; cont;
		}
		c++;
		if(i > 0 && a[i].Y == a[i - 1].Y)c2++;	
	}
	if(c > 1){
		lint curr = f[c] * p2(pw[c] - c2) % m;
		ans = ans * curr % m;
	}
	printf("%lld", ans);
	ret 0;
}