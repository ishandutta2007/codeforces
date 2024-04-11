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

VI A;
int tick = 2;

struct Tree{
    int bottom;
    VI t, cz;
    
    void build(){
        bottom = 1;
        while(bottom < SZ(A)/2) bottom *= 2;
        t.resize(2*bottom, -1);
        cz.resize(2*bottom, -1);
        FOR(i, SZ(A)/2){
            t[bottom+i] = SZ(A)/2 + i;
            cz[bottom+i] = 1;
        }
    }
    
    void update(int a, int b, int k, int v=1, int lo=0, int hi=-2){
        if(hi == -2) hi = bottom-1;
        if(a > b) return;
        if(a == lo && b == hi){
            t[v] = k;
            cz[v] = tick;
            return;
        }
        int mid = (lo+hi)/2;
        update(a, std::min(b, mid), k, v<<1, lo, mid);
        update(std::max(mid+1, a), b, k + std::max(mid+1, a)-a, (v<<1)+1, mid+1, hi);
    }
    
    int ans(int v){
        v += bottom;
        int besttim = cz[v];
        int ret = A[t[v]];
        int plus = 0;
        int pw = 1;
        while(v > 1){
            if(v & 1) plus += pw;
            v >>= 1;
            pw <<= 1;
            if(cz[v] > besttim){
                besttim = cz[v];
                ret = A[t[v]+plus];
            }
        }
        return ret;
    }
    
};
   
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
    
    int n, m;
    std::cin >> n >> m;
    A.resize(2*n);
    FOR(i, 2*n) std::cin >> A[i];
    Tree tree;
    tree.build();
    FOR(i, m){
        int what;
        std::cin >> what;
        if(what == 1){
            int x, y, k;
            std::cin >> x >> y >> k;
            x--;y--;
            tree.update(y, y+k-1, x);
            tick++;
        }else{
            int x;
            std::cin >> x;
            std::cout << tree.ans(--x) << "\n";
        }
    }
    
	return 0;
}