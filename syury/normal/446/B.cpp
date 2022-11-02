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

const int MAXN = 1e3 + 4;
const int MAXK = 1e6 + 4;

int p, k;
lint ans = -1e18;
int n, m;
int a[MAXN][MAXN];
int sumr[MAXN];
int sumc[MAXN];
lint pr[MAXK], pc[MAXK];
set<pair<lint, int>, greater<pair<lint, int> > > s;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d%d", &n, &m, &k, &p);
	F(i, 0, n)
		F(j, 0, m)scanf("%d", &a[i][j]);
	fi0(sumr); fi0(sumc);
	F(i, 0, n){
		F(j, 0, m)sumr[i] += a[i][j];
		s.ins(mk(sumr[i], i));
	}
	F(i, 0, k + 1){
		if(i == 0){pr[i] = 0; cont;}
		pr[i] = pr[i - 1];
		int curr = s.begin()->X, y = s.begin()->Y;
		pr[i] += curr;
		s.era(s.begin());
		s.ins(mk(curr - p * m, y));
	}
	s.clear();
	F(j, 0, m){
		F(i, 0, n)sumc[j] += a[i][j];
		s.ins(mk(sumc[j], j));
	}
	F(i, 0, k + 1){
		if(i == 0){pc[i] = 0; cont;}
		pc[i] = pc[i - 1];
		int curr = s.begin()->X, y = s.begin()->Y;
		pc[i] += curr;
		s.era(s.begin());
		s.ins(mk(curr - p * n, y));
	}
	s.clear();
	F(l, 0, k + 1){
		lint curr = 0ll;
		curr = pc[l] + pr[k - l] - p * l * 1ll * (k - l);
		ans = max(ans, curr);
	}
	printf("%lld", ans);
	ret 0;
}