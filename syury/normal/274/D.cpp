#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define uF(i, l, r) for(i = l; i != r; i++)
#define uDf(i, l, r) for(i = l; i != r; i--)
#define I(a, x) for(auto a : x)
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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm fjfjfk
#define cset fhjfghjgfh

vector<int> cp;
int n, m;
vector<vector<int> > a;
vector<vector<pair<int, int> > > b;
vector<int> k;
set<pair<int, int>, greater<pair<int, int> > > ss;
int ptr;
vector<int> ans;
vector<int> mi;
vector<vector<int> > c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	a.rs(n); b.rs(n); cp.rs(n);
	k.rs(m); ans.rs(m);
	mi.rs(m); c.rs(n);
	ptr = m - 1;
	F(i, 0, n){
		a[i].rs(m); c[i].rs(m); b[i].rs(m);
		F(j, 0, m){scanf("%d", &a[i][j]); b[i][j] = mk(a[i][j], j);}
		cp[i] = m - 1;
	}
	F(i, 0, n)sort(all(b[i]));
	F(j, 0, m){
		k[j] = 0; mi[j] = 0;
		F(i, 0, n){
			if(a[i][j] == -1){mi[j]++; cont;}
			if(b[i].back().X == a[i][j])mi[j]++;
		}
		ss.ins(mk(mi[j], j));
	}
	while(!ss.empty()){
		int w = ss.begin()->X, j = ss.begin()->Y;
		ss.era(ss.begin());
		if(w != n){printf("-1"); ret 0;}
		ans[ptr--] = j;
		F(i, 0, n){
			if(a[i][j] == -1)cont;
			cp[i]--;
			if(cp[i] == -1)cont;
			if(b[i][cp[i]].X != a[i][j]){
				int l = cp[i];
				while(l != -1 && b[i][l].X != -1 && b[i][l].X == b[i][cp[i]].X){
					int nj = b[i][l].Y;
					ss.era(mk(mi[nj], nj)); mi[nj]++; ss.ins(mk(mi[nj], nj));
					l--;
				}
			}
		}
	}
	F(j, 0, m)printf("%d ", ans[j] + 1);
	ret 0;
}