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

int f(int y){
	int kek = 1;
	while(y){
		int c = y%10;
		if(c)kek *= c;
		y /= 10;
	}
	return kek;
}

int g(int x){
	return x < 10 ? x : g(f(x));
}

const int maxn = 1e6 + 6;
int pref[maxn][10];

void precalc(){
	F(i, 1, maxn){
		int curr = g(i);
		F(j, 1, 10)pref[i][j] = pref[i - 1][j];
		if(curr >= 1 && curr <= 9)
			++pref[i][curr];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	precalc();
	int q;
	cin >> q;
	F(i, 0, q){
		int l, r, k;
		cin >> l >> r >> k;
		cout << pref[r][k] - pref[l - 1][k] << '\n';
	}
	return 0;
}