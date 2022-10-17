#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

std::string remove(const std::string &s, char z){
        std::string ret;
        TRAV(i, s) if(i != z) ret.push_back(i);
        return ret;
}

void solve(){
        std::string s;
        std::cin >> s;
        std::string ans;
        while(SZ(s)){
                for(int i = 25; i >= 0; --i){
                        VI mam(26);
                        TRAV(j, s) mam[j-'a']++;
                        if(!mam[i]) continue;

                        VI mam2(26);
                        int pos = 0;
                        while(s[pos] != 'a' + i) pos++;
                        REP(j, pos, SZ(s)) mam2[s[j]-'a']++;
                        bool bad = false;
                        FOR(j, 26) if(mam2[j] == 0 && mam[j] != 0) bad = true;
                        if(bad) continue;

                        ans.push_back(i+'a');
                        s = remove(s.substr(pos), i+'a');
                        break;
                }
        }
        std::cout << ans << "\n";
}

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        int t;
        std::cin >> t;
        while(t--) solve();

        return 0;
}