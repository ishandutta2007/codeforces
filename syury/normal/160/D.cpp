#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;
typedef long long int ll;
typedef long double dbl;
typedef unsigned long long uli;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i > r; i--)
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

struct edge{
	int v, u, w, id;
	bool operator < (const edge & a)const{
		return w < a.w;
	}
};

int n, m;
edge e[MAXN];
int p[MAXN];
int state[MAXN];
int gt = 0;
int tm[MAXN], val[MAXN];
set<pii> s;
set<int> con[MAXN];

inline void inc(int pos){
	if(tm[pos] < gt){val[pos] = 0; tm[pos] = gt;}
	val[pos]++;
}

inline int get(int pos){
	if(tm[pos] < gt){val[pos] = 0; tm[pos] = gt;}
	return val[pos];
}

int find_set(int v){
	return (p[v] == v) ? p[v] : p[v] = find_set(p[v]);
}

void unite(int v, int u){
	v = find_set(v); u = find_set(u);
	if(v == u)ret;
	p[v] = u;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> e[i].v >> e[i].u >> e[i].w;
		e[i].v--; e[i].u--;
		e[i].id = i;
	}
	F(i, 0, n)p[i] = i;
	sort(e, e + m);
	int l = 0;
	while(l < m){
		int r = l;
		while(r < m && e[r].w == e[l].w)r++;
		F(i, l, r){
			e[i].v = find_set(e[i].v); e[i].u = find_set(e[i].u);
			if(e[i].v == e[i].u){state[e[i].id] = -1;}
		}
		gt++;
		F(i, l, r){
			if(state[e[i].id] == -1)cont;
			inc(e[i].v); inc(e[i].u);
			con[e[i].v].insert(i);
			con[e[i].u].insert(i);
		}
		F(i, l, r){
			if(state[e[i].id] == -1)cont;
			s.insert({get(e[i].v), e[i].v});
			s.insert({get(e[i].u), e[i].u});
		}
		while(!s.empty()){
			int v = s.begin()->Y, d = s.begin()->X;
			if(d > 1)break;
			if(d == 0){s.erase(s.begin()); con[v].clear(); cont;}
			s.erase(s.begin());
			int i = *con[v].begin();
			state[e[i].id] = 1;
			con[v].clear();
			int u = ((v == e[i].v) ? e[i].u  : e[i].v);
			con[u].erase(i);
			s.erase(make_pair(get(u), u));
			val[u]--;
			s.insert(make_pair(get(u), u));
		}
		for(auto p : s)con[p.Y].clear();
		s.clear();
		F(i, l, r)unite(e[i].v, e[i].u);
		l = r;
	}
	F(i, 0, m){
		if(state[i] == -1)cout << "none\n";
		if(state[i] == 0)cout << "at least one\n";
		if(state[i] == 1)cout << "any\n";
	}
	return 0;
}