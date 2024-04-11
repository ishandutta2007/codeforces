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
#define y1 adjf

int n, m;
vector<pair<int, int> > a;
vector<vector<pair<int, int> > > h, v, d1, d2;
vector<int> cnt;
int out[9];

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	h.rs(n); v.rs(n); d1.rs(n + n + 2); d2.rs(n + n + 2);
	cnt.rs(m); cnt.asg(m, 0);
	a.rs(m);
	fi0(out);
	F(i, 0, m){
		scanf("%d%d", &a[i].X, &a[i].Y);
		h[a[i].X - 1].pb(mk(a[i].Y, i));
		v[a[i].Y - 1].pb(mk(a[i].X, i));
		int d = min(a[i].Y, a[i].X) - 1;
		a[i].Y -= d; a[i].X -= d;
		if(a[i].Y == 1){d1[n - a[i].X].pb(mk(a[i].Y + d, i));}
		else{d1[n + a[i].Y - 2].pb(mk(a[i].Y + d, i));}
		a[i].Y += d; a[i].X += d;
		a[i].Y = n + 1 - a[i].Y;
		d = min(a[i].Y, a[i].X) - 1;
		a[i].Y -= d; a[i].X -= d;
		if(a[i].Y == 1){d2[n - a[i].X].pb(mk(a[i].Y + d, i));}
		else{d2[n + a[i].Y - 2].pb(mk(a[i].Y + d, i));}
		a[i].Y += d; a[i].X += d;
		a[i].Y = n + 1 - a[i].Y;

	}
	F(i, 0, n){
		sort(all(h[i]));
		sort(all(v[i]));
		F(j, 0, (int)h[i].size()){
			if(j != (int)h[i].size() - 1)cnt[h[i][j].Y]++;
			if(j != 0)cnt[h[i][j].Y]++;
		}
		F(j, 0, (int)v[i].size()){
			if(j != (int)v[i].size() - 1)cnt[v[i][j].Y]++;
			if(j != 0)cnt[v[i][j].Y]++;
		}
	}
	F(i, 0, n + n + 2){
		sort(all(d1[i]));
		sort(all(d2[i]));
		F(j, 0, (int)d1[i].size()){
			if(j != (int)d1[i].size() - 1)cnt[d1[i][j].Y]++;
			if(j != 0)cnt[d1[i][j].Y]++;
		}
		F(j, 0, (int)d2[i].size()){
			if(j != (int)d2[i].size() - 1)cnt[d2[i][j].Y]++;
			if(j != 0)cnt[d2[i][j].Y]++;
		}
	}
	F(i, 0, m){
	//printf("cnt[%d] = %d\n", i, cnt[i]);
	out[cnt[i]]++;
	}
	F(i, 0, 9)printf("%d ", out[i]);
	ret 0;
}