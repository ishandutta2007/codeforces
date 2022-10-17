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

struct Tree{
    int bottom;
    VI t, ile;
    void build(VI &a){
        bottom = 1;
        while(bottom < SZ(a)) bottom <<= 1;
        t.resize(bottom*2);
        ile.resize(bottom*2);
        FOR(i, SZ(a)) t[i+bottom] = a[i];
        FOR(i, SZ(a)) ile[i+bottom] = 1;
        for(int i = bottom-1; i >= 1; --i){
            t[i] = std::__gcd(t[i<<1], t[(i<<1)+1]);
            if(t[i] == t[i<<1]) ile[i] += ile[i<<1];
            if(t[i] == t[(i<<1)+1]) ile[i] += ile[(i<<1)+1];
        }
            
    }
    
    int query(int a, int b){
        a += bottom;
        b += bottom+1;
        int ret = 0;
        int il = 0;
        while(a < b){
            if(a & 1){
                int old = ret;
                int nile = 0;
                ret = std::__gcd(ret, t[a]);
                if(ret == old) nile += il;
                if(ret == t[a]) nile += ile[a];
                il = nile;
                a++;
            }
            if(b & 1){
                int old = ret;
                int nile = 0;
                ret = std::__gcd(ret, t[--b]);
                if(ret == old) nile += il;
                if(ret == t[b]) nile += ile[b];
                il = nile;
            }
            a >>= 1; b >>= 1;
        }
        return il;
    }
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
    
    int n;
    std::cin >> n;
    VI A(n);
    FOR(i, n) std::cin >> A[i];
    Tree tree;
    tree.build(A);
    int q;
    std::cin >> q;
    while(q--){
        int a, b;
        std::cin >> a >> b;
        a--;b--;
        std::cout <<  b-a+1-tree.query(a, b) << "\n";
    }
    
	return 0;
}