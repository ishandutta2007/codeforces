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

const int MAXN = 1e5 + 5;

int ans = 1;
int n;
int cnt[MAXN];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(cnt);
	scanf("%d", &n);
	F(i, 0, n){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	F(g, 2, MAXN){
		int crr = 0;
		for(int x = g; x < MAXN; x += g)crr += cnt[x];
		ans = max(ans, crr);
	}
	printf("%d", ans);
	ret 0;
}