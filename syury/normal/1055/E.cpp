//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = 1500 + 5;

int R[N];
int n, s, m, k;
int a[N];
int b[N];
pii seg[N];
int dp[N][N];
int pref[N];

int getsum(int l, int r){
	if(l)return pref[r] - pref[l - 1];
	else return pref[r];
}

bool can(int x){
	F(i, 0, n)
		b[i] = a[i] <= x ? 1 : 0;
	F(i, 0, N)F(j, 0, N)
		dp[i][j] = 0;
	F(i, 0, n){
		pref[i] = b[i];
		if(i)
			pref[i] += pref[i - 1];
	}
	F(cnt, 1, m + 1){
		DF(i, n - 1, 0){
			dp[cnt][i] = dp[cnt][i + 1];
			int mx = R[i];
			if(mx == -1){
				dp[cnt][i] = dp[cnt][i + 1];
				cont;
			}
			++mx;
			dp[cnt][i] = max(dp[cnt][i], dp[cnt - 1][mx] + getsum(i, mx - 1));
		}
	}
	F(cnt, 1, m + 1)
		F(i, 0, n)
			if(dp[cnt][i] >= k)ret 1;
	ret 0;
}

int SR[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> m >> k;
	F(i, 0, n)cin >> a[i];
	F(i, 0, n)SR[i] = a[i];
	SR[n] = 0;
	int sz;
	sort(SR, SR + n + 1);
	sz = unique(SR, SR + n + 1) - SR;
	fill(R, R + n, -1);
	F(i, 0, s){
		int x, y;
		cin >> x>> y;
		--x; --y;
		seg[i] = {x, y};
		F(j, x, y + 1)
			R[j] = max(R[j], y);
	}
	int l = 0, r = sz-1;
	if(!can(SR[r])){cout << -1; ret 0;}
	while(r - l > 1){
		int mid = (l + r)/2;
		if(can(SR[mid]))
			r = mid;
		else
			l = mid;
	}
	cout << SR[r];
	return 0;
}