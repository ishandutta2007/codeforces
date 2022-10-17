#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int N = 4050;
int n;
std::vector<int> G[N<<1];
bool mark[N<<1];
int S[N<<1],c;


bool dfs(int x)
{
	if(mark[x^1]) return 0;
	if(mark[x]) return 1;
	mark[x]=1;
	S[c++]=x;
	for(int i = 0; i < G[x].size(); ++i)
		if(!dfs(G[x][i])) return 0;
	return 1;
}

void init(int xd)
{
	n=xd;
	for(int i = 0; i < 2*n; ++i) G[i].clear();
	memset(mark,0,sizeof(mark));
}

void add_clause(int x,int xval,int y,int yval)
{
	x=(x<<1)+xval;
	y=(y<<1)+yval;
	G[x^1].push_back(y);
	G[y^1].push_back(x);
}

void add_xor(int x, int y){
	add_clause(x, 0, y, 0);
	add_clause(x, 1, y, 1);
}

void add_xnor(int x, int y){
	add_clause(x, 1, y, 0);
	add_clause(x, 0, y, 1);
}

void add_true(int x){
	add_clause(x, 1, x, 1);
}
void add_false(int x){
	add_clause(x, 0, x, 0);
}

bool solve()
{
	for(int i = 0; i < 2*n; i += 2) if(!mark[i]&&!mark[i+1])
	{
		c=0;
		if(!dfs(i))
		{
			while(c) mark[S[--c]]=0;
			if(!dfs(i+1)) return 0;
		}
	}
	return 1;
}

void fail(){
	std::cout << -1 << "\n";
	std::exit(0);
}

int mat[2005][2005];
int tab[2005];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int X;
	std::cin >> X;
	FOR(i, X){
		FOR(j, X){
		char x;
		std::cin >> x;
		mat[i][j] = (int)(x == '1');
		}
	}
	FOR(i, X){
		FOR(j, X){
			char a;
			std::cin >> a;
			mat[i][j] ^= (int)(a == '1');
		}
	}
	FOR(i, X){
		char x;
		std::cin >> x;
		tab[i] = (int)(x == '1');
	}
	init(2*X);
	FOR(i, X){
		FOR(j, X){
			int a = tab[j];
			int b = tab[i];
			if(mat[i][j] == 1){
				if(a == 0 && b == 0) fail();
				if(a == 1 && b == 0) add_true(i);
				if(a == 0 && b == 1) add_true(X+j);
				if(a == 1 && b == 1) add_xor(i, X+j);
			}else{
				if(a == 1 && b == 0) add_false(i);
				if(a == 0 && b == 1) add_false(X+j);
				if(a == 1 && b == 1) add_xnor(i, X+j);
			}
		}
	}
	if(solve() == false) std::cout << -1 << "\n";
	else{
		std::vector<PII> ans;
		FOR(i, X) if(mark[(i<<1)+1]) ans.push_back(MP(0, i));
		FOR(i, X) if(mark[((i+X)<<1)+1]) ans.push_back(MP(1, i));
		std::cout << SZ(ans) << "\n";
		TRAV(i, ans){
			if(i.X == 0) std::cout << "row " << i.Y << "\n";
			else std::cout << "col " << i.Y << "\n";
		}
	}
	
	return 0;
}