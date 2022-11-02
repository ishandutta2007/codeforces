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

const int MAXN = 5e3 + 3;
const int MAXM = 1e5 + 5;
const ldb eps = 1e-7;

struct edge{
	ldb c;
	int v, u;
	int id;
	bool gg = false;
	edge(){}
	edge(int _v, int _u, int _c, int _id){v = _v; u = _u; c = _c; id = _id;}
};

auto comp = [](const edge & a, const edge & b){
	ret (b.c - a.c > eps) || (fabs(a.c - b.c) < eps && a.id > b.id);
};

int n, m, k;
edge defe[MAXM];
edge ne[MAXM];
edge tot[MAXM];
int p[MAXN];
int rnk[MAXN];
int ans[MAXN];
int ptr = 0;
int necnt, mcnt;

int find_set(int v){
	ret (v == p[v]) ? v : p[v] = find_set(p[v]);
}

bool unite(int v, int u){
	v = find_set(v); u = find_set(u);
	if(v == u)ret false;
	if(rnk[v] > rnk[u])swap(v, u);
	p[v] = u;
	if(rnk[v] == rnk[u])rnk[u]++;
	ret true;
}

int solve(ldb x){
	ptr = 0;
	F(i, 0, necnt){ne[i].c += x; ne[i].gg = true;}
	F(i, 0, n){p[i] = i; rnk[i] = 0;}
	merge(ne, ne + necnt, defe, defe + mcnt, tot, comp);
	int crr = 0;
	F(i, 0, m){
		if(unite(tot[i].v, tot[i].u)){
			ans[ptr++] = tot[i].id;
			if(tot[i].gg)crr++;
		}
	}
	F(i, 0, necnt){ne[i].c -= x;}
	ret crr;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	necnt = 0;
	mcnt = 0;
	F(i, 0, m){
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c);
		v--; u--;
		if(v == 0 || u == 0)ne[necnt++] = edge(v, u, c, i + 1);
		else defe[mcnt++] = edge(v, u, c, i + 1);
	}
	sort(defe, defe + mcnt, comp);
	sort(ne, ne + necnt, comp);
	if(necnt < k){printf("-1"); ret 0;}
	ldb l = -1e6, r = 1e6;
	F(STEPS, 0, 50){
		ldb mid = (l + r)/2;
	//	printf("%d %.15lf\n", solve(mid), (double)mid);
		if(solve(mid) < k)r = mid;
		else l = mid;
	}
	if(solve(l) == k)r = l;
	if(solve(r) != k){printf("-1"); ret 0;};
	printf("%d\n", n - 1);
	F(i, 0, ptr)printf("%d ", ans[i]);
	ret 0;
}