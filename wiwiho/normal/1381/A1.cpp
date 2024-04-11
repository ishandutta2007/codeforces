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

void flip(string& s, int p){
    for(int i = 0; i <= p; i++) s[i] = s[i] == '0' ? '1' : '0';
    reverse(s.begin(), s.begin() + p + 1);
}

int main(){
    StarBurstStream

    int T;
    cin >>  T;
    while(T--){

        int n;
        cin >> n;
        string s, b;
        cin >> s >> b;

        vector<int> ans;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0') continue;
            if(s[0] != '1'){
                ans.eb(1);
                flip(s, 0);
            }
            ans.eb(i + 1);
            flip(s, i);
        }

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == b[i]) continue;
            ans.eb(i + 1);
            flip(s, i);
        }
//        cerr << s << " " << b << "\n";

        cout << ans.size() << " ";
        printv(ans, cout);

    }

    return 0;
}