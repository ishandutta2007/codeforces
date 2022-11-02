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
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 2e5 + 5;

lint t[MAXN];
int p[MAXN];
pair<int, pair<int, int> > qu[MAXN];
lint ans[MAXN];
vector<int> rs[MAXN];
int pos[MAXN];
int n, q;

void inc(int r){
	for(; r < n; r = r|(r + 1))t[r]++;
}

lint sum(int l, int r){
	lint ans = 0ll;
	l--;
	for(; l >= 0; l = (l&(l + 1)) - 1)ans -= t[l];
	for(; r >= 0; r = (r&(r + 1)) - 1)ans += t[r];
	ret ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &q);
	F(i, 0, n){
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	F(i, 0, n){
		for(int j = p[i]; j <= n; j += p[i]){
			int k = pos[j];
			int l = min(i, k), r = max(i, k);
			rs[l].pb(r);
		}
	}
	fi0(t);
	F(i, 0, q){
		scanf("%d%d", &qu[i].X, &qu[i].Y.X);
		qu[i].X--; qu[i].Y.X--; qu[i].Y.Y = i;
	}
	sort(qu, qu + q);
	int ptr = q - 1;
	Df(i, n - 1, -1){
		I(v, rs[i])inc(v);
		while(ptr > -1 && qu[ptr].X == i){ans[qu[ptr].Y.Y] = sum(i, qu[ptr].Y.X); ptr--;}
	}
	F(i, 0, q)printf("%lld\n", ans[i]);
	ret 0;
}