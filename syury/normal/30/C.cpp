#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;
typedef long long int ll;
typedef long double dbl;
typedef unsigned long long uli;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i > r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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

struct item{
	int x, y, t;
	dbl p;
};

bool operator < (const item & a, const item & b){
	return a.t < b.t;
}

const int MAXN = 1e3 + 3;

item a[MAXN];
dbl dp[MAXN];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		dp[i] = a[i].p;
		for(int j = 0; j < i; j++){
			if((a[i].t - a[j].t) * 1ll * (a[i].t - a[j].t) >= (a[i].x - a[j].x) * 1ll * (a[i].x - a[j].x) + (a[i].y - a[j].y) * 1ll * (a[i].y - a[j].y)){
				dp[i] = max(dp[i], dp[j] + a[i].p);
			}
		}
	}
	dbl ans = 0;
	for(int i = 0; i < n; i++)ans = max(ans, dp[i]);
	cout.precision(12);
	cout << fixed << ans;
	return 0;
}