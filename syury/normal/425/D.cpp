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

const int MAXN = 1e5 + 5;

int n;
vector<pair<int, int> > xv[MAXN], yv[MAXN];
int xi[MAXN], yi[MAXN];
pair<int, int> a[MAXN];

int main(){
	scanf("%d", &n);
	F(i, 0, n){
		int x, y;
		scanf("%d%d", &x, &y);
		xv[x].pb(mk(y, i));
		yv[y].pb(mk(x, i));
		a[i] = mk(x, y);
	}
	F(i, 0, MAXN){
		if(!xv[i].empty())sort(all(xv[i]));
		F(j, 0, (int)xv[i].size())xi[xv[i][j].Y] = j;
	}
	F(i, 0, MAXN){
		if(!yv[i].empty())sort(all(yv[i]));
		F(j, 0, (int)yv[i].size())yi[yv[i][j].Y] = j;
	}
	int ans = 0;
	F(i, 0, n){
		if(xv[a[i].X].size() - xi[i] < yv[a[i].Y].size() - yi[i]){
			F(j, xi[i] + 1, (int)xv[a[i].X].size()){
				int d = xv[a[i].X][j].X - a[i].Y;
				if(a[i].X + d > MAXN || xv[a[i].X + d].empty())cont;
				auto it = lower_bound(all(xv[a[i].X + d]), mk(a[i].Y, 0));
				auto jt = lower_bound(all(xv[a[i].X + d]), mk(a[i].Y + d, 0));
				if(it == xv[a[i].X + d].end() || it->X != a[i].Y || jt == xv[a[i].X + d].end() || jt->X != a[i].Y + d)cont;
				ans++;
			}
		}
		else{
			F(j, yi[i] + 1, (int)yv[a[i].Y].size()){
				int d = yv[a[i].Y][j].X - a[i].X;
				if(a[i].Y + d > MAXN || yv[a[i].Y + d].empty())cont;
				auto it = lower_bound(all(yv[a[i].Y + d]), mk(a[i].X, 0));
				auto jt = lower_bound(all(yv[a[i].Y + d]), mk(a[i].X + d, 0));
				if(it == yv[a[i].Y + d].end() || it->X != a[i].X || jt == yv[a[i].Y + d].end() || jt->X != a[i].X + d)cont;
				ans++;
			}
		}
	}
	printf("%d", ans);
	ret 0;
}