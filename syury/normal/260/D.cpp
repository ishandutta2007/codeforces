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

set<pair<int, int> > b, w;
int s[MAXN];
int n;
set<pair<int, pair<int, int> > > edges;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	int lab = -1, law = -1;
	F(i, 0, n){
		int c;
		scanf("%d%d", &c, &s[i]);
		if(c == 0)b.ins(mk(s[i], i)); else w.ins(mk(s[i], i));
	}
	int es = 0;
	while(!b.empty() && !w.empty()){
		if(b.begin()->X < w.begin()->X){
			int i = b.begin()->Y, j = w.begin()->Y;
			edges.ins(mk(i + 1, mk(j + 1, s[i])));
			b.era(b.begin());
			w.era(w.begin());
			s[j] -= s[i];
			if(lab == -1)lab = i;
			w.ins(mk(s[j], j));
		}
		else{
			int i = w.begin()->Y, j = b.begin()->Y;
			edges.ins(mk(i + 1, mk(j + 1, s[i])));
			w.era(w.begin());
			b.era(b.begin());
			s[j] -= s[i];
			if(law == -1)law = i;
			b.ins(mk(s[j], j));
		}
		es++;
	}
	if(!b.empty())b.era(b.begin()); else if(!w.empty())w.era(w.begin());
	while(es != n - 1 && !b.empty()){
		edges.ins(mk(law + 1, mk(1 + b.begin()->Y, 0)));
		b.era(b.begin()); es++;
	}
	while(es != n - 1 && !w.empty()){
		edges.ins(mk(lab + 1, mk(1 + w.begin()->Y, 0)));
		w.era(w.begin()); es++;
	}
	I(c, edges)printf("%d %d %d\n", c.X, c.Y.X, c.Y.Y);
	ret 0;
}