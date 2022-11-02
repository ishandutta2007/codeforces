#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i >= r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg
#define link kekekeke

const int maxn = 1e6 + 6;

int n, a, b;
int p[maxn];

void output(int cnta, int cntb){
	int ptr = 0;
	F(i, 0, cnta){
		F(j, 0, a)if(j == a - 1)p[ptr + j] = ptr + 1; else p[ptr + j] = ptr + j + 2;
		ptr += a;
	}
	swap(a, b); swap(cnta, cntb);
	F(i, 0, cnta){
		F(j, 0, a)if(j == a - 1)p[ptr + j] = ptr + 1; else p[ptr + j] = ptr + j + 2;
		ptr += a;
	}
	swap(a, b); swap(cnta, cntb);
	F(i, 0, n)cout << p[i] << " ";
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	F(i, 0, n + 1){
		ll x = a * 1ll * i;
		ll y = n - x;
		if(y < 0)cont;
		if(y%b != 0)cont;
		output(i, y/b);
	}
	cout << -1;
	return 0;
}