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

const int MAXN = 1e5 + 5;
const ldb shift = 0.5;

int a[9];
int y[MAXN], x[MAXN];
pair<int, int> pt[MAXN];
bool used[9];
int p[9];
int n;
vector<int> t[4 * MAXN];

void build(int v, int l, int r){
	if(l == r){
		t[v].rs(1); t[v][0] = pt[l].Y;
		ret;
	}
	int mid = (l + r) >> 1;
	build(2*v, l, mid);
	build(2*v + 1, mid + 1, r);
	t[v].rs(t[2*v].size() + t[2*v + 1].size());
	merge(all(t[2*v]), all(t[2*v + 1]), t[v].begin());
}

int get(int v, int l, int r, int ul, int ur, int bnd, bool le){
	if(ul > ur)ret 0;
	if(l == ul && r == ur){
		if(le){
			auto it = upper_bound(all(t[v]), bnd);
			ret it - t[v].begin();
		}
		else{
			auto it = lower_bound(all(t[v]), bnd);
			ret t[v].end() - it;
		}
	}
	int mid = (l + r) >> 1;
	ret get(2*v, l, mid, ul, min(ur, mid), bnd, le) + get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, bnd, le);
}

bool check(){
	int s1 = a[p[0]] + a[p[3]] + a[p[6]];
	int s2 = a[p[1]] + a[p[4]] + a[p[7]];
	if(x[s1 - 1] == x[s1])ret false;
	if(x[s1 + s2 - 1] == x[s1 + s2])ret false;
	ldb x1, x2;
	x1 = x[s1 - 1] + shift; x2 = x[s1 + s2 - 1] + shift;
	s1 = a[p[6]] + a[p[7]] + a[p[8]];
	s2 = a[p[3]] + a[p[4]] + a[p[5]];
	if(y[s1 - 1] == y[s1])ret false;
	if(y[s1 + s2 - 1] == y[s1 + s2])ret false;
	ldb y1, y2;
	y1 = y[s1 - 1] + shift; y2 = y[s1 + s2 - 1] + shift;
	int ps1 = a[p[0]] + a[p[3]] + a[p[6]];
	int ps2 = a[p[1]] + a[p[4]] + a[p[7]];
	if(get(1, 0, n - 1, 0, ps1 - 1, y[s1 + s2 - 1] + 1, false) != a[p[0]])ret false;
	if(get(1, 0, n - 1, ps1 + ps2, n - 1, y[s1 + s2 - 1] + 1, false) != a[p[2]])ret false;
	if(get(1, 0, n - 1, 0, ps1 - 1, y[s1 - 1], true) != a[p[6]])ret false;
	if(get(1, 0, n - 1, ps1 + ps2, n - 1, y[s1 - 1], true) != a[p[8]])ret false;
	printf("%.15lf %.15lf\n%.15lf %.15lf", (double)x1, (double)x2, (double)y1, (double)y2);
	ret true;
}

bool solve(int pos){
	if(pos == 9)ret check();
	F(i, 0, 9){
		if(used[i])cont;
		p[pos] = i; used[i] = true;
		if(solve(pos + 1))ret true;
		used[i] = false;
	}
	ret false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fi0(used);
	scanf("%d", &n);
	F(i, 0, n){
		scanf("%d%d", &x[i], &y[i]);
		pt[i] = mk(x[i], y[i]);
	}
	sort(pt, pt + n);
	build(1, 0, n - 1);
	sort(x, x + n); sort(y, y + n);
	F(i, 0, 9)scanf("%d", &a[i]);
	if(!solve(0))printf("-1");
	ret 0;
}