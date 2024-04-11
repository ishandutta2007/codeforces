#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
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
#define tm shjfhg

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	vector<int> x;
	cin >> n;
	x.resize(n);
	F(i, 0, n)cin >> x[i];
	cin >> a >> b;
	sort(all(x));
	n = unique(all(x)) - x.begin();
	int ans = 0;
	while(a > b){
		int delta = 1;
		DF(i, n - 1, 0){
			if(a - a%x[i] < b)cont;
			delta = max(delta, a%x[i]);
		}
		a -= delta;
		++ans;
		while(n && (a - a%x[n - 1] < b))--n;
	}
	cout << ans;
	return 0;
}