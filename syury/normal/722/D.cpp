#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
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
#define y1 adjf

vector<int> y;
vector<vector<int> > g;
vector<int> pos;
int n;
int sz;
int tmp[102];
set<pair<int, int>, greater<pair<int, int> > > s;
set<int> was;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	y.rs(n); g.rs(n);
	pos.rs(n); pos.asg(n, 0);
	F(i, 0, n){
		scanf("%d", &y[i]);
		sz = 0;
		int t = y[i];
		while(true){
			tmp[sz++] = t;
			if(t == 1)
				brk;
			if(t&1){t--;}
			t >>= 1;
		}
		g[i].rs(sz);
		F(j, 0, sz)
			g[i][j] = tmp[j];
		s.ins(mk(y[i], i));
		was.ins(y[i]);
	}
	while(!s.empty()){
		int i = s.begin()->Y;
		s.era(s.begin());
		int curr = pos[i];
		while(curr < (int)g[i].size() && was.find(g[i][curr]) != was.end()){curr++;}
		if(curr == (int)g[i].size()){cont;}
		was.ins(g[i][curr]);
		pos[i] = curr;
		s.ins(mk(g[i][curr], i));	
	}
	F(i, 0, n){
		printf("%d ", g[i][pos[i]]);
	}
	ret 0;
}