#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(indx, a, b) for (int indx = a; indx < b; indx++)
#define ForE(indx, a, b) for (int indx = a; indx <= b; indx++)
#define Ford(indx, a, b) for (int indx = a; indx > b; indx--)
#define FordE(indx, a, b) for (int indx = a; indx >= b; indx--)
#define Fora(indx, a) for (auto indx : a)

#define PrintV(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << ' ';
#define PrintVl(x) for (int indx = 0; indx < x.size(); indx++) cout << x[indx] << endl;
#define Ptest(x) return cout << x, 0;
#define Pmtest(x) cout << x << endl; continue;
#define isvowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
#define gl(x) getline(cin, x)
#define mset(x) memset(x, 0, sizeof(x));

#define pque priority_queue
#define mts multiset
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

struct edge{
    int u, v, c;
    bool operator< (const edge &rhs) const{
        return c < rhs.c;
    }
} e[N];

bool imp[N];
int n, m, k;

struct DSU{
	int n, p[N], sz[N], cntimp[N];
	void init(int n2){
		n = n2;
        For(i, 0, n){
            p[i] = i;
            sz[i] = 1;
            cntimp[i] = imp[i];
        }
	}
    int par(int u){
        return ((u == p[u]) ? (u) : (p[u] = par(p[u])));
    }
	bool joint(int u, int v){
		u = par(u);
		v = par(v);
        if (u == v){
            return 0;
        }
		p[v] = u;
		sz[u] += sz[v];
		cntimp[u] += cntimp[v];
		return (cntimp[u] == k);
	}
} dsu;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
	int x;
	memset(imp, 0, sizeof imp);
    For(i, 0, k){
        cin >> x;
        x--;
        imp[x] = 1;
    }
    For(i, 0, m){
        cin >> e[i].u >> e[i].v >> e[i].c;
        e[i].u--;
        e[i].v--;
    }
	sort(e, e + m);
	int ans;
	dsu.init(n);
	For(i, 0, m){
		if (dsu.joint(e[i].u, e[i].v)){
			ans = e[i].c;
			break;
		}
	}
	For(i, 0, k){
	    cout << ans << ' ';
	}
	return 0;
}

/*
==================================+
INPUT:                            |
------------------------------    |
2 3 2
2 1
1 2 3
1 2 2
2 2 1
------------------------------    |
4 5 3
1 2 3
1 2 5
4 2 1
2 3 2
1 4 4
1 3 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2 2
------------------------------    |
3 3 3
------------------------------    |
==================================+
*/