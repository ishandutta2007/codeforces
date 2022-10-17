#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int repr[2*300005], sL[2*300005], sR[2*300005];
std::stack<PII> stack;
int Find(int a){
	while(a != repr[a]) a = repr[a];
	return a;
}
ll Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b){
		stack.push(MP(-1, -1));
		return 0;
	}
	if(sL[a] + sR[a] > sL[b] + sR[b]) std::swap(a, b);
	ll last = 1ll*sL[a]*sR[a]+1ll*sL[b]*sR[b];
	stack.push(MP(a, b));
	sL[b] += sL[a];
	sR[b] += sR[a];
	repr[a] = b;
	return 1ll*sL[b]*sR[b]-last;
}
ll Revert(){
	PII c = stack.top();
	stack.pop();
	if(c.X == -1) return 0;
	ll last = 1ll*sL[c.Y]*sR[c.Y];
	sL[c.Y] -= sL[c.X];
	sR[c.Y] -= sR[c.X];
	repr[c.X] = c.X;
	return 1ll*sL[c.X]*sR[c.X]+1ll*sL[c.Y]*sR[c.Y]-last;
}

const int LOG = 19;
std::vector<PII> t[1<<(LOG+1)];
void add(int a, int b, PII ed){
	a += 1<<LOG;
	b += (1<<LOG)+1;
	while(a<b){
		if(a&1) t[a++].push_back(ed);
		if(b&1) t[--b].push_back(ed);
		a>>=1;b>>=1;
	}
}

int q;
ll ans = 0;
void dfs(int v=1, int lo=0, int hi=(1<<LOG)-1){
	TRAV(i, t[v]) ans += Union(i.X, i.Y);
	if(lo == hi){
		if(lo >= q) std::exit(0);
		std::cout << ans << " ";
	}else{
		dfs(v<<1, lo, (lo+hi)/2);
		dfs((v<<1)+1, (lo+hi)/2+1, hi);
	}
	FOR(i, SZ(t[v])) ans += Revert();
}

std::map<PII, int> map;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	FOR(i, 3*100000){
		repr[i] = i;
		sL[i] = 1;
	}
	FOR(i, 3*100000){
		repr[3*100000+i] = 3*100000+i;
		sR[3*100000+i] = 1;
	}
	std::cin >> q;
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		b += 3*100000;
		if(map.count(MP(a, b))){
			add(map[MP(a, b)], i-1, MP(a, b));
			map.erase(MP(a, b));
		}else{
			map[MP(a, b)] = i;
		}
	}
	TRAV(pr, map){
		add(pr.Y, q, pr.X);
	}
	dfs();
	return 0;
}