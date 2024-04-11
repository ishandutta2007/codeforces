#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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

const int MAXN = 1e5 + 5;
const ldb eps = 1e-9;

int l, v1, v2, n;
int a[MAXN];
ldb p[MAXN];
ldb t[MAXN];
vector<pair<ldb, int> > seg;

auto comp = [](const pair<ldb, int> & x, const pair<ldb, int> & y){
	ret (x.X < y.X - eps);
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d%d", &n, &l, &v1, &v2);
	F(i, 0, n)scanf("%d", &a[i]);
	ldb d = l * 1ll * v2/ldb(v1 + v2);
	int start = 0;
	F(i, 0, n){
		ldb le = a[i] - d, ri = a[i];
//		printf("%.15lf %.15lf\n", (double)le, (double)ri);
		if(le < -eps){start++; le += 2*l;}
		//if(fabs(ri) < eps)ri = 2*l;
		seg.pb(mp(le, 1));
		seg.pb(mp(ri, -1));
	}
	sort(all(seg), comp);
	int m = (int)seg.size();
//	int start = 0;
//	F(i, 0, m){start += seg[i].Y; start = max(0, start);}
	int bal = start;
	ldb prv = seg[m - 1].X;
	auto dist = [](ldb from, ldb to){
		to -= from;
		if(to < -eps)to += 2*l;
		ret to;
	};
//	F(i, 0, m)printf("%.15lf %d\n", (double)seg[i].X, seg[i].Y);
	F(i, 0, m){
		assert(bal >= 0);
		p[bal] += dist(prv, seg[i].X);
		bal += seg[i].Y;
//		if(i != m - 1 && fabs(seg[i].X - seg[i + 1].X) < eps)cont;
		prv = seg[i].X;
	}
	F(i, 0, n + 1)p[i] /= 2*l;
	F(i, 0, n + 1)printf("%.15lf\n", (double)p[i]);
	return 0;
}