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
const int inf = 1e9 + 9;

int n;
int a[MAXN];
lint dp[MAXN];
int t[2][3 + 4 * MAXN];
lint best = 0;
int minu[MAXN], maxu[MAXN];
int pmin = 0, pmax = 0;

void build(int v, int l, int r){
	t[0][v] = -inf;
	t[1][v] = inf;
	if(l == r)ret;
	int mid = (l + r) >> 1;
	build(v + v, l, mid);
	build(v + v + 1, mid + 1, r);
}

int get(int id, int v, int l, int r, int ul, int ur){
	if(ul > ur)ret (id) ? inf : (-inf);
	if(l == ul && r == ur)ret t[id][v];
	int mid = (l + r) >> 1;
	if(id) ret min(get(id, v + v, l, mid, ul, min(ur, mid)), get(id, v + v + 1, mid + 1, r, max(ul, mid + 1), ur));
	else ret max(get(id, v + v, l, mid, ul, min(ur, mid)), get(id, v + v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

void upd(int id, int v, int l, int r, int pos, int nval){
	if(id)t[id][v] = min(t[id][v], nval); else t[id][v] = max(t[id][v], nval);
	if(l == r)ret;
	int mid = (l + r) >> 1;
	if(pos <= mid)upd(id, v + v, l, mid, pos, nval);
	else upd(id, v + v + 1, mid + 1, r, pos, nval);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 0;
	scanf("%d", &n);
	build(1, 0, n);
	F(i, 0, n)scanf("%d", &a[i]);
	dp[1] = 0;
	upd(0, 1, 0, n, 0, a[0]);
	upd(1, 1, 0, n, 0, a[0]);
	minu[pmin++] = 0; maxu[pmax++] = 0;
	F(i, 1, n){
		dp[i + 1] = best;
		upd(0, 1, 0, n, i, a[i]);
		upd(1, 1, 0, n, i, a[i]);
		if(a[i] == a[i - 1]){best = max(best, dp[i + 1]); minu[pmin++] = i; maxu[pmax++] = i; cont;}
		if(a[i] < a[i - 1]){
			int it = pmin - 1;
			bool allc = false;
			int bid = minu[it];
			while(get(1, 1, 0, n, minu[it], i - 1) > a[i]){
				dp[minu[it]] += get(1, 1, 0, n, minu[it], i - 1) - a[i];
				if(dp[minu[it]] > dp[bid])bid = minu[it];
				best = max(best, dp[minu[it]]);
				if(it == 0){allc = true; brk;}
				it--;
			}
			if(!allc)it++;
			int cutm = minu[it];
			while(pmin != 0 && minu[pmin - 1] >= cutm)pmin--;
			minu[pmin++] = bid;
			dp[i + 1] = max(dp[i + 1], dp[bid]);
		}
		else{
            int it = pmax - 1;
			bool allc = false;
			int bid = maxu[it];
			while(get(0, 1, 0, n, maxu[it], i - 1) < a[i]){
				dp[maxu[it]] += a[i] - get(0, 1, 0, n, maxu[it], i - 1);
				if(dp[maxu[it]] > dp[bid])bid = maxu[it];
				best = max(best, dp[maxu[it]]);
				if(it == 0){allc = true; brk;}
				it--;
			}
			if(!allc)it++;
			int cutm = maxu[it];
			while(pmax != 0 && maxu[pmax - 1] >= cutm)pmax--;
			maxu[pmax++] = bid;
			dp[i + 1] = max(dp[i + 1], dp[bid]);		
		}
		best = max(best, dp[i + 1]);
		minu[pmin++] = i; maxu[pmax++] = i;
	}
	//F(i, 0, n + 1)printf("%lld ", dp[i]);
	printf("%lld", dp[n]);
	ret 0;
}