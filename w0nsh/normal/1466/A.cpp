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

int cross(PII a, PII b){
    return a.X*b.Y-a.Y*b.X;
}

int area(std::vector<PII> vec){
    int ans = 0;
    FOR(i, SZ(vec)){
        ans += cross(vec[i], vec[(i+1)%SZ(vec)]);
    }
    return std::abs(ans);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<PII> A(n);
        FOR(i, n) std::cin >> A[i].X;
        PII pt = MP(0, 1);
        std::set<int> set;
        FOR(i, n){
            REP(j, i+1, n){
                std::vector<PII> vec{
                    pt,
                    A[i],
                    A[j]
                };
                set.insert(area(vec));
            }
        }
        std::cout << SZ(set) << "\n";
    }

    return 0;
}