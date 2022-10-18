#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if(n % k){
            cout << "-1\n";
            continue;
        }

        vector<int> cnt(26);
        for(int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
        }
        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(cnt[i] % k) ok = false;
        }
        if(ok){
            cout << s << "\n";
            continue;
        }

        for(int i = n - 1; i >= 0; i--){
            cnt[s[i] - 'a']--;
            if(s[i] == 'z') continue;

            int total = 0;
            vector<int> tmp(26);
            for(int j = 0; j < 26; j++){
                tmp[j] = iceil(cnt[j], k) * k - cnt[j];
                total += tmp[j];
            }
            if(total > n - i) continue;

            int owo = -1;
            if(i + total < n) owo = s[i] - 'a' + 1;
            else{
                for(int j = s[i] - 'a' + 1; j < 26; j++){
                    if(tmp[j]){
                        owo = j;
                        break;
                    }
                }
                if(owo == -1) continue;
            }

            if(tmp[owo] == 0){
                tmp[owo] = k;
                total += k;
            }
            tmp[0] += n - i - total;

            string ans = s.substr(0, i);
            ans += 'a' + owo;
            tmp[owo]--;
            for(int j = 0; j < 26; j++){
                while(tmp[j]--) ans += 'a' + j;
            }
            cout << ans << "\n";
            break;

        }

    }

    return 0;
}