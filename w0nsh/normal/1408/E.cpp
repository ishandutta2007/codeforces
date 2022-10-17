#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

VI repr;

int Find(int a){
    if(repr[a] == a) return a;
    return repr[a] = Find(repr[a]);
}

bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return false;
    repr[a] = b;
    return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    int m, n;
    std::cin >> m >> n;
    VI A(m), B(n);
    FOR(i, m) std::cin >> A[i];
    FOR(i, n) std::cin >> B[i];

    repr.resize(n+m);
    FOR(i, n+m) repr[i] = i;
    std::vector<PR<int, PII> > edges;

    FOR(i, m){
        int s;
        std::cin >> s;
        FOR(j, s){
            int x;
            std::cin >> x;
            x--;
            edges.push_back(MP(B[x]+A[i], MP(i, m+x)));
        }
    }

    std::sort(edges.begin(), edges.end());
    std::reverse(edges.begin(), edges.end());
    ll ans =0;
    TRAV(ed, edges){
        if(!Union(ed.Y.X, ed.Y.Y)) ans += ed.X;
    }

    std::cout << ans;

	return 0;
}