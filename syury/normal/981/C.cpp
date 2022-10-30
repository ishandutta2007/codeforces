#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 1e5 + 5;

int n;
int deg[maxn];
vector<int> gr[maxn];

void fail(){
	cout << "No";
	exit(0);
}

void output(int v, int pv){
	int nxt = -1;
	I(u, gr[v])if(u != pv){nxt = u;}
	if(nxt == -1){cout << v + 1; return;}
	output(nxt, v);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n - 1){
		int v, u;
		cin >> v >> u;
		--v; --u;
		deg[v]++; deg[u]++;
		gr[v].pb(u); gr[u].pb(v);
	}
	int pos = -1;
	F(i, 0, n){
		if(deg[i] > 2){
			if(pos != -1)fail();
			pos = i;
		}
	}
	if(pos == -1){
		cout << "Yes\n";
		cout << 1 << '\n';
		int v = -1;
		F(i, 0, n)if(deg[i] == 1){v = i; break;}
		cout << v + 1 << ' ';
		output(v, -1);
		return 0;
	}
	cout << "Yes\n";
	cout << gr[pos].size() << '\n';
	I(u, gr[pos]){
		cout << pos + 1 << ' ';
		output(u, pos);
		cout << '\n';
	}
	return 0;
}