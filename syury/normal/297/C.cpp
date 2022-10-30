#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
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

int n;
pii s[maxn];
int a[maxn], b[maxn];

int main(){
	sync;
	cin >> n;
	F(i, 0, n){cin >> s[i].X; s[i].Y = i;}
	if(n == 2){
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << s[0].X << " " << s[1].X;
		ret 0;
	}
	sort(s, s + n);
	F(i, 0, n/3){
		int pos = s[i].Y;
		a[pos] = i; b[pos] = s[i].X - i;
	}
	int kek = (n%3 == 2) ? 1 : 0;
	F(i, n/3, n/3 + n/3 + kek){
		int pos = s[i].Y;
		b[pos] = i; a[pos] = s[i].X - i;
	}
	DF(i, n - 1, n/3 + n/3 + kek){
		int pos = s[i].Y;
		b[pos] = n - 1 - i; a[pos] = s[i].X - b[pos];
	}
	cout << "YES" << endl;
	F(i, 0, n)cout << a[i] << " ";
	cout << endl;
	F(i, 0, n)cout << b[i] << " ";
	return 0;
}