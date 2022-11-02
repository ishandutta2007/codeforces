#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
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

const int MAXN = 1e6 + 6;

int n;
int a[MAXN];
set<int> ss;
map<int, int> id;
int cid = 0;

lint t[2][MAXN];

void inc(int ti, int x, lint num){
	for(int i = x; i < MAXN; i = i|(i + 1))t[ti][i] += num;
}

lint get(int ti, int l, int r){
	lint ans = 0ll;
	for(int i = r; i >= 0; i = (i&(i + 1)) - 1)ans += t[ti][i];
	if(l == 0)ret ans;
	for(int i = l - 1; i >= 0; i = (i&(i + 1)) - 1)ans -= t[ti][i];
	ret ans;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(t);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &a[i]);
	F(i, 0, n)ss.ins(a[i]);
	I(v, ss)id[v] = cid++;
	F(i, 0, n)a[i] = id[a[i]];
	lint ans = 0ll;
	F(i, 0, n){
		inc(0, a[i], 1);
		inc(1, a[i], get(0, a[i] + 1, cid));
		ans += get(1, a[i] + 1, cid);
	}
	printf("%lld", ans);
	ret 0;
}