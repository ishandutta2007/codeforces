#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; i++)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; i--)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

int getall(ll x, int n){
	if(x > n)ret 0;
	return 1 + getall(x * 10 + 4, n) + getall(x * 10 + 7, n);
}	

bool is_good(int x){
	if(!x)ret 0;
	while(x){
		if(x%10 != 4&& x%10 != 7)ret 0;
		x /= 10;
	}
	ret 1;
}

vector<int> kth(int n, int k){
	vector<ll> f(n);
	f[0] = 1;
	F(i, 1, n)f[i] = i * f[i - 1];
	vector<int> perm(n), u(n, 0);
	F(i, 0, n){
		F(j, 0, n){
			if(u[j])cont;
			ll add = f[n - 1 - i];
			if(add < k){k -= add; cont;}
			perm[i] = j;
			brk;
		}
		u[perm[i]] = 1;
	}
	ret perm;
}


signed main() {
    sync;
	int n, k;
	cin >> n >> k;
	ll fac = 1;
	int cnt;
	F(i, 1, n + 1){
		fac *= i;
		cnt = i;
		if(fac >= k)break;
	}
	if(fac < k){cout << -1; ret 0;}
	int tot = getall(0, n) - 1;
	vector<int> perm = kth(cnt, k);
	F(i, 0, cnt){
		int pos = n - cnt + 1 + i, val = perm[i] + n - cnt + 1;
		if(is_good(val) && !is_good(pos))--tot;
	}
	cout << tot;
}