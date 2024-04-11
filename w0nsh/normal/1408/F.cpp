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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    int n;
    std::cin >> n;

    if(n <= 2){
        std::cout << 0 << "\n";
        return 0;
    }

    std::vector<PII> ans;
    int pot = 1;
    while(pot*2 <= n){
        std::vector<bool> vis(n);
        FOR(s, n){
            if(s+pot >= n || vis[s] || vis[s+pot]) continue;
            vis[s] = true;
            vis[s+pot] = true;
            ans.push_back(MP(s, s+pot));
        }
        pot *= 2;
    }

    if(pot != n){
        assert(__builtin_popcount(n) != 1);
        int off = 0;
        while(__builtin_popcount(n-off) != 1){
            off++;
        }

        pot = 1;
        n = n-off;
        while(pot*2 <= n){
            std::vector<bool> vis(n);
            FOR(s, n){
                if(s+pot >= n || vis[s] || vis[s+pot]) continue;
                vis[s] = true;
                vis[s+pot] = true;
                ans.push_back(MP(s+off, s+pot+off));
            }
            pot *= 2;
        }
    }

    std::cout << SZ(ans) << "\n";
    TRAV(i, ans) std::cout << i.X+1 << " " << i.Y+1 << "\n";

	return 0;
}