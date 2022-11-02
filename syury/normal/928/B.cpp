#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 1e5 + 5;

int n, k;
int prv[maxn];
int dp[maxn];
pii seg[maxn];

int sz(int l, int r){ret r - l + 1;}

pii inter(pii l, pii r){
	if(l.Y < r.X || r.Y < l.X)ret {0, -1};
	else ret {max(l.X, r.X), min(l.Y, r.Y)};
}

int main(){
	sync;
	cin >> n >> k;
	F(i, 0, n){
		int x;
		cin >> x;
		--x;
		prv[i] = x;
	}
	F(i, 0, n){
		int l = max(0, i - k);
		int r = min(n - 1, i + k);
		seg[i] = {l, r};
		if(prv[i] == -1){
			dp[i] = sz(l, r);
		}
		else{
			int j = prv[i];
			auto kek = inter(seg[i], seg[j]);
			dp[i] = dp[j] + sz(seg[i].X, seg[i].Y) - sz(kek.X, kek.Y);
		}
		cout << dp[i] << " ";
	}
	ret 0;
}