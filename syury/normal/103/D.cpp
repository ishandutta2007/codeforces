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
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 3e5 + 5;

int n;
int w[MAXN];
vector<lint> cnt[MAXN];
vector<int> qs[MAXN];
short b[MAXN];
lint ans[MAXN];

int main(){
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &w[i]);
	int cut = (int)sqrt(n);
	cut = max(1, cut);
	int q;
	scanf("%d", &q);
	F(i, 0, q){
		int v, s;
		scanf("%d%d", &v, &s); v--;
		b[i] = s;
		ans[i] = 0;
		if(s >= cut){
			for(int j = v; j < n; j += s)ans[i] += w[j];
		}
		else{
			qs[v].pb(i);
		}
	}
	Df(i, n - 1, -1){
		cnt[i].rs(cut);
		if(i + cut < n)vector<lint>().swap(cnt[i + cut]);
		F(j, 1, cut)cnt[i][j] = w[i] + ((i + j < n) ? cnt[i + j][j] : 0);
		I(v, qs[i])ans[v] = cnt[i][b[v]];
	}
	F(i, 0, q)printf("%lld\n", ans[i]);
	ret 0;
}