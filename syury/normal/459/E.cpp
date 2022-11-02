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

struct edge{
	int f, s;
	int w;
};

auto comp = [](const edge & a, const edge & b) -> bool{
	ret a.w < b.w;
};

int n, m;
vector<int> mx;
vector<edge> e;
queue<pair<int, int> > q;
int ans = 0;

void modify(){
	while(!q.empty()){
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();
		mx[x] = max(mx[x], y);
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	e.rs(m);
	mx.rs(n); mx.asg(n, 0);
	F(i, 0, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w); v--; u--;
		e[i].f = v; e[i].s = u; e[i].w = w;
	}
	sort(all(e), comp);
	F(i, 0, m){
		if(i > 0 && e[i].w > e[i - 1].w){modify();}
		int curr = mx[e[i].f] + 1;
		ans = max(ans, curr);
		q.push(mk(e[i].s, curr));
	}
	printf("%d", ans);
	ret 0;
}