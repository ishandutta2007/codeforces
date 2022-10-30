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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double dbl;

void fail(int pos){
	cout << pos + 1 << endl;
	exit(0);
}

signed main(){
	sync;
	int cmax = -1;
	int n;
	cin >> n;
	F(i, 0, n){
		int x;
		cin >> x;
		if(x > cmax + 1)
			fail(i);
		cmax = max(cmax, x);
	}
	cout << -1;
	ret 0;
}