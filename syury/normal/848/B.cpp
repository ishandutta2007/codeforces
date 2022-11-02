#include<bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

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
#define ws ajhdhfh

const int MAXN = 1e5 + 5;

struct item{
	int id;
	int dir, t, x, val;
};

auto comp = [](const item & a, const item & b){
	if(a.dir < b.dir)ret true;
	if(a.dir > b.dir)ret false;
	ret a.x > b.x;
};

int n, w, h;
item a[MAXN];
set<int> ayy;
map<int, int> lmao;
int cid = 0;
map<int, int> co, ot;
pair<int, int> ans[MAXN];
vector<int> b[3][MAXN];
pair<int, int> out[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n, &w, &h);
	F(i, 0, n){
		scanf("%d%d%d", &a[i].dir, &a[i].x, &a[i].t);
		a[i].val = a[i].t - a[i].x;
		ayy.ins(a[i].val);
		a[i].id = i;
	}
	I(c, ayy)lmao[c] = cid++;
	F(i, 0, n)a[i].val = lmao[a[i].val];
	sort(a, a + n, comp);
	Df(i, n - 1, -1){
		b[a[i].dir][a[i].val].pb(a[i].x);
	}
	F(i, 0, n)if(a[i].dir == 1)ot[a[i].val]++;
	F(i, 0, n){
		if(a[i].dir == 1)cont;
		int cot = ot[a[i].val], cu = co[a[i].val];
		if(cot > cu){
			ans[i].Y = h; ans[i].X = b[1][a[i].val][cu];
		}
		else{
			ans[i].X = w; ans[i].Y = b[2][a[i].val][(int)b[2][a[i].val].size() - cu + cot - 1];
		}
		co[a[i].val]++;
	}
	ot.clear();
	I(c, co)ot[c.X] = c.Y;
	co.clear();	
	F(i, 0, n){
		if(a[i].dir == 2)cont;
		int cot = ot[a[i].val], cu = co[a[i].val];
		if(cot > cu){
			ans[i].X = w; ans[i].Y = b[2][a[i].val][cu];
		}
		else{
			ans[i].Y = h; ans[i].X = b[1][a[i].val][(int)b[1][a[i].val].size() - cu + cot - 1];
		}
		co[a[i].val]++;
	}
	F(i, 0, n)out[a[i].id] = ans[i];
	F(i, 0, n)printf("%d %d\n", out[i].X, out[i].Y);
	ret 0;
}