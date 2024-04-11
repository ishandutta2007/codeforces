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
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

const int MAXN = 2e5 + 5;

int n;
vector<pair<int, int> > a;
vector<int> pref;
pair<int, int> t[MAXN];
lint best = 2e18;

auto cmpy = [](const pair<int, int> & l, const pair<int, int> & r){
	ret (l.Y < r.Y) || (l.Y == r.Y && l.X < r.X);
};

void upd(const pair<int, int> & l, const pair<int, int> & r){
	lint crr = (l.X - r.X) * 1ll * (l.X - r.X) + (l.Y - r.Y) * 1ll * (l.Y - r.Y);
	best = min(best, crr);
}

void solve(int l, int r){
	if(r - l <= 3){
		F(i, l, r + 1)
			F(j, i + 1, r + 1)upd(a[i], a[j]);
		sort(a.begin() + l, a.begin() + r + 1, cmpy);
		ret;
	}
	int mid = (l + r) >> 1;
	int mx = a[mid].X;
	solve(l, mid);
	solve(mid + 1, r);
	merge(a.begin() + l, a.begin() + mid + 1, a.begin() + mid + 1, a.begin() + r + 1, t, cmpy);
	copy(t, t + r - l + 1, a.begin() + l);
	int tsz = 0;
	F(i, l, r + 1){
		if(abs(a[i].X - mx) * 1ll * abs(a[i].X - mx) < best){
			for(int j = tsz - 1;  j >= 0 && (a[i].Y - t[j].Y) * 1ll * (a[i].Y - t[j].Y) < best; j--)upd(a[i], t[j]);
			t[tsz++] = a[i];
		}
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	a.rs(n); pref.rs(n);
	F(i, 0, n){
		scanf("%d", &a[i].Y);
		if(i == 0)pref[i] = a[i].Y; else pref[i] = a[i].Y + pref[i - 1];
		a[i] = mk(i, pref[i]);
	}
	solve(0, n - 1);
	printf("%lld", best);
	ret 0;
}