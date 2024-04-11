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
#define tm afhdhn

const int MAXN = 1e5 + 5;

int n, q;
lint ans[MAXN];
int a[MAXN];
lint pref[MAXN];

lint get(int l, int r){
	if(l == 0)ret pref[r]; else ret pref[r] - pref[l - 1];
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &a[i]);
	sort(a, a + n);
	F(i, 0, n){
		pref[i] = a[i];
		if(i > 0)pref[i] += pref[i - 1];
	}
	if(n == 1)ans[0] = 0;
	F(i, 1, n){
		int r = n - 1;
		lint k = i;
		lint mul = 1;
		ans[i] = 0;
		while(r > 0){
			int l = max(0ll, r - k);
			ans[i] += mul * get(l, r - 1);
			k *= i;
			mul++;
			r = l;
		}
	}
	scanf("%d", &q);
	F(i, 0, q){
		int k;
		scanf("%d", &k);
		k = min(k, n - 1);
		printf("%lld ", ans[k]);
	}
	ret 0;
}