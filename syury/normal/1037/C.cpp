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

string s, t;
int n;

signed main(){
	sync;
	cin >> n;
	cin >> s >> t;
	int ans = 0;
	int i = 0;
	while(i < n){
		if(s[i] == t[i]){++i; cont;}
		if(i + 1 == n || s[i + 1] == t[i + 1] || s[i + 1] == s[i]){++ans; ++i; cont;}
		++ans;
		i += 2;
	}
	cout << ans;
	ret 0;
}