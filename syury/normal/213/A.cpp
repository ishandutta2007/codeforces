#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
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

const int MAXN = 2e2 + 2;

int n;
int c[MAXN];
vector<int> out[MAXN];
int deg[MAXN];
int old[MAXN];
queue<int> q[4];

int solve(int start){
	F(c, 1, 4)while(!q[c].empty())q[c].pop();
	F(i, 0, n){deg[i] = old[i]; if(!deg[i])q[c[i]].push(i);}
	int le = n;
	int res = 0;
	while(le){
		if(q[start].empty()){res++; start++; if(start == 4)start = 1; cont;}
		while(!q[start].empty()){
			le--;
			res++;
			int v = q[start].front();
			q[start].pop();
			I(u, out[v]){
				deg[u]--;
				if(deg[u] == 0)q[c[u]].push(u);
			}
		}
	}
	ret res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n)cin >> c[i];
	F(i, 0, n){
		int k;
		cin >> k;
		F(j, 0, k){int v; cin >> v; v--; out[v].pb(i); deg[i]++;}
	}
	F(i, 0, n)old[i] = deg[i];
	int ans = 1e9;
	F(c, 1, 4)ans = min(ans, solve(c));
	cout << ans;
	return 0;
}