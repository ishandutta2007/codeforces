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
#define tm afhdhn

const int MAXN = 5005;

int last[MAXN], t[MAXN];
int ans = MAXN;
int n, m;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, n){
		int _t;
		double db;
		scanf("%d%f", &_t, &db);
		t[i] = _t;
	}
	fi0(last);
	F(i, 0, n){
		int curr = 0;
		F(j, 1, t[i] + 1)curr = max(curr, last[j] + 1);
		ans = min(ans, n - curr);
		last[t[i]] = max(last[t[i]], curr);
	}
	printf("%d", ans);
	ret 0;
}