#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
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

const int maxn = 3e5 + 5;
int a[maxn];
int cnt[maxn];

const int MAXA = 2e7 + 7;
int least_prime[MAXA];
int prs[MAXA];
int prime_cnt = 0;

void sieve(){
	for(int i = 2; i < MAXA; i++){
		if(least_prime[i] == 0){
			least_prime[i] = i;
			prs[prime_cnt++] = i;
		}
		for(int j = 0; j < prime_cnt && prs[j] <= least_prime[i] && i * 1ll * prs[j] < MAXA; j++)
			least_prime[i * prs[j]] = prs[j];
	}
}

int main() {
    sync;
	int n;
	cin >> n;
	F(i, 0, n)cin >> a[i];
	int g = a[0];
	F(i, 1, n)g = __gcd(g, a[i]);
	F(i, 0, n)a[i] /= g;
	sieve();
	clean(prs);
	F(i, 0, n){
		int x = a[i];
		int old = 0;
		while(x > 1){
			int p = least_prime[x];
			if(p != old){
				++prs[p];
			}
			old = p;
			x /= p;
		}
	}
	int best = 0;
	F(i, 0, MAXA)best = max(best, prs[i]);
	cout << (best == 0 ? -1 : (n - best));
}