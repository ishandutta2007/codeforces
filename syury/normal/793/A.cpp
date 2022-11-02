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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e5 + 5;
const int inf = 1e9 + 9;

int n, k;
int a[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	F(i, 0, n)scanf("%d", &a[i]);
	int cmin = inf;
	F(i, 0, n)cmin = min(cmin, a[i]);
	lint ans = 0ll;
	F(i, 0, n){
		if(a[i]%k != cmin%k){printf("-1"); return 0;}
		ans += (a[i] - cmin)/k;
	}
	printf("%lld", ans);
	ret 0;
}