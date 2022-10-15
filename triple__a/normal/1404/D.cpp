//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		for (int i=2;i<sz(li);++i) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		for (int i=0;i<2*N;++i) if (!comp[i]) dfs(i);
		for (int i=0;i<N;++i) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

const int maxn=1000007;

int n;
int p[maxn<<1];
bool vis[maxn];
int fs[maxn],tr[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    if (n&1){
        cout<<"Second"<<endl;
        rep(i,2*n){
            cin>>p[i];
            p[i]--;
            if (vis[p[i]]) fs[p[i]]=i,p[i]=~p[i];
            else vis[p[i]]=1, tr[p[i]]=i;
        }
        TwoSat ts(n);
        rep(i,n) ts.either(p[i],p[i+n]);
        rep(i,n) ts.either(~p[i],~p[i+n]);
        ts.solve();
        int sum=0;
        rep(i,n) if (ts.values[i]) sum+=fs[i]+1; else sum+=tr[i]+1;
        if (sum%(2*n)!=0){
            rep(i,n) ts.values[i]=1-ts.values[i];
        }
        rep(i,n) if (ts.values[i]) cout<<fs[i]+1<<" ";
        else cout<<tr[i]+1<<" ";
        cout<<endl;
    }
    else{
        cout<<"First"<<endl;
        rep(i,2*n) cout<<i%n+1<<" ";
        cout<<endl;
    }
    int u;
    cin>>u;
    return 0; 

}