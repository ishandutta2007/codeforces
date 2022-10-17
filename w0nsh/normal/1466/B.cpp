#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
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

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> have(2*n+5);
        std::vector<bool> mam(2*n+5);
        FOR(i, n){
            int a;
            std::cin >> a;
            have[a]++;
        }
        int ans = 0;
        FOR(i, 2*n+3){
            if(mam[i]){
                ans++;
            }else{
                if(have[i]) ans++, have[i]--;
            }
            mam[i+1] = (have[i] > 0);
        }
        std::cout << ans << "\n";
    }

    return 0;
}