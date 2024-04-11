//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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

int sol(string& s, int posa, int posb, int post){
    int n = s.size();

    int ans = post;
    ans += n - 1 - posa - (posa < posb) - (posa < post);
    ans += n - 1 - posb - (posb < post);
    return ans;
}

int main(){
    StarBurstStream

    string s;
    cin >> s;

    if(s.size() == 2){
        if(stoi(s) % 25 == 0) cout << "0\n";
        else if(((s[1] - '0') * 10 + (s[0] - '0')) % 25 == 0) cout << "1\n";
        else cout << "-1\n";
        return 0;
    }

    int ans = MAX;
    int n = s.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(j == i || i == k || j == k) continue;

                if(((s[i] - '0') * 10 + (s[j] - '0')) % 25 == 0 && s[k] != '0'){
                    ans = min(ans, sol(s, i, j, k));
                }
            }
        }
    }

    if(ans == MAX) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}