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

const int MAXN = 5e5 + 5;
const dbl eps = 1e-12;

int n;
pair<int, int> a[MAXN];

inline bool can(dbl T){
	dbl m = 3e18;
	DF(i, n - 1, -1){
		if(a[i].Y < 0){
			m = min(m, a[i].X + T * a[i].Y);
		}
		else{
			if(m < a[i].X + T * a[i].Y + eps)ret true;
		}
	}
	ret false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n){
		cin >> a[i].X >> a[i].Y;
	}
	sort(a, a + n);
	dbl l = 0, r = 2e9 + 9;
	F(i, 0, 70){
		dbl mid = (l + r)/2;
		if(can(mid))r = mid;
		else l = mid;
	}
	if(r > 2e9 + 5){cout << -1; ret 0;}
	cout.precision(12);
	cout << fixed << (l + r)/2;
	return 0;
}