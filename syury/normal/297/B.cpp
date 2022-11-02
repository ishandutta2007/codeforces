#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i > (r); i--)
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
#define sz(x) (int)(x).size()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 1e5 + 5;

int n, m, k;
int ka[maxn], kb[maxn];
pii a[maxn], b[maxn];

int main(){
	sync;
	cin >> n >> m >> k;
	F(i, 0, n)cin >> ka[i];
	F(i, 0, m)cin >> kb[i];
	sort(ka, ka + n);
	sort(kb, kb + m);
	n--; m--;
	while(n >= 0 && m >= 0){
		if(ka[n] == kb[m]){--n; --m; cont;}
		if(ka[n] > kb[m]){cout << "YES"; ret 0;}
		--n; --m;
	}
	if(n >= 0)cout << "YES";
	else cout << "NO";
	return 0;
}