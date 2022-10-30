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

const int maxn = 2e5 + 5;

int a[maxn];
int n, m;
vector<int> ans;
int s[4 * maxn];
int z[4 * maxn];

inline int sub(int x, int y){
	x -= y;
	return x < 0 ? x + m : x;
}

void calcz(){
	int sz = 3 * n + 1;
	for(int i = 1, l = 0, r = 0; i < sz; i++){
		if(i <= r)z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < sz && s[i + z[i]] == s[z[i]])++z[i];
		if(i + z[i] - 1 > r){
			r = i + z[i] - 1;
			l = i;
		}
	}
}

int main() {
    sync;
	cin >> n >> m;
	F(i, 0, n)cin >> a[i];
	int C = a[0] + a[0];
	set<int> kek;
	bool g = true;
	F(i, 1, n)kek.insert(a[i]);
	F(i, 1, n){
		int d = C - a[i];
		d = (d%m + m)%m;
		if(!kek.count(d))
			g = false;
	}
	if(g)ans.pb(0);
	int ptr = 0;
	F(i, 0, n){
		s[ptr++] = sub(a[(i+1)%n], a[i]);
	}
	s[ptr++] = -1;
	DF(i, n - 1, 0)s[ptr++] = sub(a[(i+1)%n], a[i]);
	DF(i, n - 1, 0)s[ptr++] = sub(a[(i+1)%n], a[i]);
	calcz();
	DF(i, n - 1, 1){
		int pos = n + 2 + (n - 1 - i);
		if(z[pos] >= n)ans.pb(i);
	}
	if(ans.empty()){cout << 0; ret 0;}
	for(auto & i : ans){
		i = (a[i] + a[0])%m;
	}
	sort(all(ans));
	cout << ans.size() << endl;
	I(c, ans)cout << c << ' ';
}