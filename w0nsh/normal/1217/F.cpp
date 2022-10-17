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

PII swp(PII a){
	if(a.X <= a.Y) return a;
	return MP(a.Y, a.X);
}

int n, m;
int last;
std::vector<PR<int, PII> > que;
std::vector<std::vector<PII> > t;
int BOTTOM;
std::map<PII, VI> map;
std::map<PII, bool> status;

std::string str(PII a){
	return "(" + std::to_string(a.X) + ", " + std::to_string(a.Y) + ")";
}

VI repr, size;
std::stack<PII> stack, szstack;
int Find(int a){
	if(a == repr[a]) return a;
	return Find(repr[a]);
}
void Union(int a, int b){
	//std::cout << "adding edge " << a << " " << b << std::endl;
	a = Find(a);
	b = Find(b);
	if(size[a] > size[b]) std::swap(a, b);
	szstack.push(MP(b, size[b]));
	if(a == b) stack.push(MP(-1, -1));
	else{
		stack.push(MP(a, repr[a]));
		repr[a] = b;
		size[b] += size[a];
	}
}
void Revert(){
	//std::cout << "removing edge " << std::endl;
	assert(SZ(szstack) == SZ(stack));
	assert(SZ(szstack) > 0);
	auto xd = stack.top();
	stack.pop();
	size[szstack.top().X] = szstack.top().Y;
	szstack.pop();
	if(xd.X == -1) return;
	repr[xd.X] = xd.Y;
}


void build(int sz){
	BOTTOM = 1;
	while(BOTTOM < sz) BOTTOM *= 2;
	t.resize(BOTTOM*2);
}

void add(int a, int b, PII edge, int v=1, int lo=0, int hi=-2){
	if(hi==-2) hi = BOTTOM-1;
	if(a > b) return;
	if(a == lo && b == hi){
		t[v].push_back(edge);
		return;
	}
	int mid = (lo+hi)/2;
	add(a, std::min(b, mid), edge, v<<1, lo, mid);
	add(std::max(a, mid+1), b, edge, (v<<1)+1, mid+1, hi);
}

void dfs(int v=1, int lo=0, int hi=-2){
	if(hi==-2) hi = BOTTOM-1;
	
	TRAV(i, t[v]) Union(i.X, i.Y);

	if(lo == hi){
		int ind = v-BOTTOM;
		//std::cout << "handling ind " << ind << std::endl;
		if(ind >= m) return;
		PII my = swp(MP((que[ind].Y.X+last-1)%n+1, (que[ind].Y.Y+last-1)%n+1));
		PII other = swp(MP((que[ind].Y.X-last)%n+1, (que[ind].Y.Y-last)%n+1));
	//	std::cout << "my " << str(my) << " other " << str(other) << std::endl;
		if(que[ind].X == 1){
			if(!status[my]){
				int next = *std::upper_bound(map[my].begin(), map[my].end(), ind);
	//			std::cout << "adding " << str(my) <<  " on " << ind+1 << " " << next << std::endl;
				add(ind+1, next, my);
				status[my] = true;
	//			std::cout << "added " << std::endl;
			}else status[my] = false;
			if(other.X >= 1 && other.X <= n && other.Y >= 1 && other.Y <= n){
				if(status[other]){
					int next = *std::upper_bound(map[other].begin(), map[other].end(), ind);
	//				std::cout << "adding " << str(other) <<  " on " << ind+1 << " " << next << std::endl;
					add(ind+1, next, other);
	//				std::cout << "added " << std::endl;
				}
			}
		}else{
	//		std::cout << "ans " << std::flush;
			if(Find(my.X) == Find(my.Y)) last = 1;
			else last = 0;
			std::cout << last;
	//		std::cout << std::endl;
		}
	}else{
		int mid = (lo+hi)/2;
		dfs(v<<1, lo, mid);
		dfs((v<<1)+1, mid+1, hi);
	}

	FOR(i, SZ(t[v])) Revert();
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	build(m+1);
	repr.resize(n+1);
	FOR(i, n+1) repr[i] = i;
	size.resize(n+1, 1);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		que.push_back(MP(a, MP(b, c)));
		if(a==1){
			PII m1 = MP((b-1)%n+1, (c-1)%n+1);
			PII m2 = MP((b)%n+1, (c)%n+1);
			if(m1.X >= 1 && m1.X <= n && m1.Y >= 1 && m1.Y <= n) map[swp(m1)].push_back(i);
			if(m2.X >= 1 && m2.X <= n && m2.Y >= 1 && m2.Y <= n) map[swp(m2)].push_back(i);
		}
	}
	TRAV(i, map) i.Y.push_back(m);
	dfs();
	return 0;
}