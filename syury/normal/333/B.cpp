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

int n, m;
bool xfail[MAXN], yfail[MAXN];

bool by_x(pair<int, int> c){
	ret c.X == 0 || c.X == n - 1;
}

bool by_y(pair<int, int> c){
	ret c.Y == 0 || c.Y == n - 1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	fi0(xfail); fi0(yfail);
	F(i, 0, m){
		int x, y;
		scanf("%d%d", &x, &y); x--; y--;
		xfail[x] = true; yfail[y] = true;
	}
	int ans = 0;
	if(n - 1 > 1)
		F(i, 1, n - 1){
			int _i = n - 1 - i;
			if(_i < i)brk;
			if(_i == i){
				if(!xfail[i] || !yfail[i])ans++;
				cont;
			}
			int d = 0;
			pair<int, int> cd[8] = {{i, 0}, {_i, 0}, {n - 1, i}, {n - 1, _i}, {_i, n - 1}, {i, n - 1}, {0, _i}, {0, i}};
			F(mask, 0, 1 << 8){
				bool bad = false;
				F(j, 0, 8){
					if(mask&(1 << j)){
						if((by_x(cd[j]) && yfail[cd[j].Y]) || (by_y(cd[j]) && xfail[cd[j].X]))bad = true;
					}
				}
				if(bad)cont;
				F(j, 0, 8){
					F(k, 0, 8){
						if(!(mask&(1 << j)) || !(mask&(1 << k)) || k == j)cont;
						if(by_x(cd[j]) && by_x(cd[k]) && cd[j].Y == cd[k].Y){bad = true; brk;}
						if(by_y(cd[j]) && by_y(cd[k]) && cd[j].X == cd[k].X){bad = true; brk;}
						if(by_x(cd[j]) == by_x(cd[k]))cont;
						pair<int, int> f, s;
						f = cd[j], s = cd[k];
						if(by_y(cd[j]))swap(f, s);
						pair<int, int> inter = mk(s.X, f.Y);
						int df, ds;
						if(f.X == 0)df = inter.X; else df = n - 1 - inter.X;
						if(s.Y == 0)ds = inter.Y; else ds = n - 1 - inter.Y;
						if(df == ds){bad = true; brk;}
					}
					if(bad)brk;
				}
				if(!bad)d = max(d, (int)__builtin_popcount(mask));
			}
			ans += d;
		}
	printf("%d", ans);
	ret 0;
}