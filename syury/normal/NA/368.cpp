//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;

int n;
int idx[N];
vector<pair<int, char> > out[N];
map<char, int> mout[N];
map<char, int> nout[N];
vector<int> depth[N];
int sub[N];
int tot;

void dfs(int v, int d = 0){
    depth[d].pb(v);
    sub[v] = 1;
    I(e, out[v]){
        dfs(e.X, d + 1);
        sub[v] += sub[e.X];
    }
}

void add(int v, int p, char c){
    int id = nout[idx[p]].count(c) ? nout[idx[p]][c] : tot++;
    idx[v] = id;
    nout[idx[p]][c] = id;
    I(e, out[v]){
        add(e.X, v, e.Y);
    }
}

void cl(int v){
    I(e, nout[v])
        cl(e.Y);
    nout[v].clear();
}

int pardfs(int v, int u){
    int cnt = 1;
    I(e, nout[v]){
        if(mout[u].count(e.X)){
            cnt += pardfs(e.Y, mout[u][e.X]);
        }
    }
    return cnt;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n;
    F(i, 0, n - 1){
        int v, u;
        char c;
        cin >> v >> u >> c;
        --v; --u;
        mout[v][c] = u;
        out[v].pb({u, c});
    }
    dfs(0);
    int sz = N;
    int pos = -1;
    F(d, 0, N){
        if(depth[d].empty())break;
        int curr = n;
        I(v, depth[d]){
            if(out[v].empty())cont;
            curr -= sub[v];
            int big = -1;
            I(e, out[v]){
                if(big == -1 || sub[big] < sub[e.X])big = e.X;
            }
            tot = 1;
            idx[v] = 0;
            I(e, out[v]){
                if(e.X == big)cont;
                I(e1, out[e.X])
                    add(e1.X, v, e1.Y);
            }
            curr += tot;
            curr += sub[big];
            curr -= pardfs(0, big);
            cl(0);
        }
        if(curr < sz){
            sz = curr;
            pos = d + 1;
        }
    }
    cout << sz << endl << pos << endl;
	return 0;
}