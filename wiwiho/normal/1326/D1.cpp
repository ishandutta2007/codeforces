//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

#define t(x) ((x) % 2 ? s[(x) / 2] : '.')

int main(){
    StarBurstStream
    cerr.tie(0);

    int T;
    cin >> T;

    while(T--){
//        cerr << "test\n";

        string s;
        cin >> s;

        int n = s.size();
        string ans;
        ans += s[0];

        vector<int> r(2 * n + 1);
        for(int i = 0; i < 2 * n + 1; i++){
            int j = 0;
            for(; i - j > 0 && i + j < 2 * n && t(i - j - 1) == t(i + j + 1); j++);
            r[i] = j;
        }
//        printv(r, cerr);

        for(int i = -1; i < 2 * n + 1 && i < 2 * n - i; i++){
            if(i >= 0 && t(i) != t(2 * n - i)) break;
            int mx = i;
            for(int j = mx + 1; j - i <= 2 * n - i - j; j++){
                if(j - r[j] <= i + 1) mx = j;
            }
            int rmx = min(r[mx], mx - i - 1);
            string tmp;
            for(int j = 0; j < 2 * n + 1; j++){
                if(j % 2 == 0) continue;
                if(j <= i || j >= 2 * n - i || (mx != i && j >= mx - rmx && j <= mx + rmx)) tmp += t(j);
            }
//            cerr << i << " " << mx << "\n";
            if(tmp.size() > ans.size()) ans = tmp;
        }

        reverse(iter(s));
        reverse(iter(r));
        for(int i = -1; i < 2 * n + 1 && i < 2 * n - i; i++){
            if(i >= 0 && t(i) != t(2 * n - i)) break;
            int mx = i;
            for(int j = mx + 1; j - i <= 2 * n - i - j; j++){
                if(j - r[j] <= i + 1) mx = j;
            }
            int rmx = min(r[mx], mx - i - 1);
            string tmp;
            for(int j = 0; j < 2 * n + 1; j++){
                if(j % 2 == 0) continue;
                if(j <= i || j >= 2 * n - i || (mx != i && j >= mx - rmx && j <= mx + rmx)) tmp += t(j);
            }
//            cerr << i << " " << mx << "\n";
            reverse(iter(tmp));
            if(tmp.size() > ans.size()) ans = tmp;
        }

        cout << ans << '\n';
    }

    return 0;
}