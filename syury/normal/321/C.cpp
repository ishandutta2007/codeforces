#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned long long ull;
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
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg
#define link kekekeke

const int maxn = 1e5 + 5;

int n;
vector<int> gr[maxn];
char level[maxn];
bool used[maxn];
int sz[maxn];

void calc(int v, int p){
	sz[v] = 1;
	for(auto u : gr[v]){
		if(u == p || used[u])continue;
		calc(u, v);
		sz[v] += sz[u];
	}
}

void build(int v, int p = -1, char c = 'A'){
	calc(v, -1);
	int half = sz[v]>>1;
	int prv = -1;
	while(true){
		int msz = 0, mx = -1;
		for(auto u : gr[v]){
			if(u == prv || used[u])continue;
			if(sz[u] > msz){msz = sz[u]; mx = u;}
		}
		prv = v;
		if(mx == -1 || msz <= half)break;
		else v = mx;
	}
	if(v == -1)return;
	used[v] = true;
	level[v] = c;
	for(auto u : gr[v]){
		if(used[u])continue;
		build(u, v, c + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n - 1){
		int v, u;
		cin >> v >> u;
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	build(0);
	F(i, 0, n)cout << level[i] << ' ';
	return 0;
}