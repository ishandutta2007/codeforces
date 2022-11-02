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
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

const int MAXN = 1e5 + 5;

int n, m;
int bcnt = 0;
int a[MAXN];
int leb[MAXN];
int reb[MAXN];
lint sum[MAXN];
set<pair<int, int> > bs[MAXN];
int buf[MAXN];
int bufptr = 0;

bool inside(int x, int l, int r){
	ret (l <= x) && (x <= r);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, n)scanf("%d", &a[i]);
	int bsz = 1;
	while(bsz * bsz < n)bsz++;
	bsz = min(bsz, n);
	lint cs = 0;
	int csz = 0, bg = 0;
	F(i, 0, n){
		bs[bcnt].ins(mk(a[i], i));
		cs += a[i];
		csz++;
		if(csz == bsz || i == n - 1){
			leb[bcnt] = bg;
			reb[bcnt] = i;
			sum[bcnt] = cs;
			cs = 0;
			csz = 0;
			bg = i + 1;
			bcnt++;
		}
	}
	F(i, 0, m){
		int type;
		scanf("%d", &type);
		if(type == 1){
			int l, r;
			scanf("%d%d", &l, &r); l--; r--;
			lint ans = 0ll;
			F(j, 0, bcnt){
				if(inside(leb[j], l, r) && inside(reb[j], l, r)){ans += sum[j]; cont;}
				if(inside(l, leb[j], reb[j])){
					F(k, l, min(reb[j], r) + 1)ans += a[k];
					cont;
				}
				if(inside(r, leb[j], reb[j])){
					F(k, max(leb[j], l), r + 1)ans += a[k];
				}
			}
			printf("%lld\n", ans); cont;
		}
		if(type == 2){
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x); l--; r--;
			F(j, 0, bcnt){
				if(inside(leb[j], l, r) && inside(reb[j], l, r)){
					auto it = bs[j].end(); it--;
					bufptr = 0;
					while(true){
						if(it->X < x)brk;
						buf[bufptr++] = it->Y;
						if(it == bs[j].begin())brk;
						it--;
					}
					F(k, 0, bufptr){
						bs[j].era(mk(a[buf[k]], buf[k]));
						sum[j] -= a[buf[k]];
						a[buf[k]] %= x;
						sum[j] += a[buf[k]];
						bs[j].ins(mk(a[buf[k]], buf[k]));
					}
					cont;
				}
				if(inside(l, leb[j], reb[j])){
					F(k, l, min(reb[j], r) + 1){
						if(a[k] < x)cont;
						bs[j].era(mk(a[k], k));
						sum[j] -= a[k];
						a[k] = a[k]%x;
						sum[j] += a[k];
						bs[j].ins(mk(a[k], k));
					}
					cont;
				}
				if(inside(r, leb[j], reb[j])){
					F(k, max(leb[j], l), r + 1){
						if(a[k] < x)cont;
						bs[j].era(mk(a[k], k));
						sum[j] -= a[k];
						a[k] = a[k]%x;
						sum[j] += a[k];
						bs[j].ins(mk(a[k], k));
					}
				}
			}
		}
		if(type == 3){
			int id, x;
			scanf("%d%d", &id, &x); id--;
			F(j, 0, bcnt)
				if(inside(id, leb[j], reb[j])){
					bs[j].era(mk(a[id], id));
					sum[j] -= a[id];
					a[id] = x;
					sum[j] += x;
					bs[j].ins(mk(x, id));
					brk;	
				}
		}
	}
	ret 0;
}