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

const int N = (int)1e3 + 3;

struct Kek{
	int l, r, id;
	bool operator < (const Kek & i)const{return l + r > i.l + i.r;}
};

int n;
Kek a[N];
int val[N];
pii lol[N];

void fail(){
	cout << "NO";
	exit(0);
}

signed main(){
	sync;
	cin >> n;
	F(i, 0, n)cin >> lol[i].X;
	F(i, 0, n)cin >> lol[i].Y;
	F(i, 0, n){
		a[i].id = i;
		tie(a[i].l, a[i].r) = lol[i];
	}
	sort(a, a + n);
	int curr = 1;
	val[a[0].id] = 1;
	F(i, 1, n){
		if(a[i].l + a[i].r < a[i - 1].l + a[i - 1].r)
			++curr;
		val[a[i].id] = curr;
	}
	F(i, 0, n){
		F(j, 0, i){
			if(val[j] > val[i])--lol[i].X;
		}
		F(j, i + 1, n)
			if(val[j] > val[i])--lol[i].Y;
		if(lol[i] != mp(0, 0))
			fail();
	}
	cout << "YES\n";
	F(i, 0, n)cout << val[i] << ' ';
	ret 0;
}