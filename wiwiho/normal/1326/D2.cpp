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

string s;

int ex(int l, int r){
    int i = 0;
    while(l - i >= 0 && r + i < 2 * s.size() + 1 && t(l - i) == t(r + i)) i++;
//    cerr << s << " " << l << " " << r << " " << i << " " << t(l - i) << " " << t(l + i) << "\n";
    return i;
}

vector<int> lps(){
    int l = 2 * s.size() + 1;

    int mx = 0;
    int center = 0;
    vector<int> r(l);
    r[0] = 1;
    for(int i = 1; i < l; i++){
//        cerr << "test " << i << " " << center << "\n";
        int ii = center - (i - center);
        int len = mx - i + 1;
        if(i > mx){
            r[i] = ex(i, i);
            center = i;
            mx = i + r[i] - 1;
        }
        else if(r[ii] == len){
            r[i] = len + ex(i - len, i + len);
            center = i;
            mx = i + r[i] - 1;
        }
        else r[i] = min(r[ii], len);
    }

    return r;
}

int main(){
    StarBurstStream
    cerr.tie(0);

    int T;
    cin >> T;

    while(T--){
//        cerr << "test\n";

        cin >> s;

        int n = s.size();
        string ans;
        ans += s[0];

        vector<int> r = lps();
        vector<int> lp(2 * n + 1, -1);
        for(int i = 0; i <= n; i++){
            r[i]--;
            lp[i - r[i]] = i;
        }

//        printv(r, cerr);
//        printv(lp, cerr);

        int mx = -1;
        int anslen = 1;
        pii ansv = mp(-1, -1);
        for(int i = -1; i < n; i++){
            if(i >= 0 && t(i) != t(2 * n - i)) break;
            mx = max(mx, lp[i + 1]);
            int rmx = min(r[mx], mx - i - 1);
            int len = rmx + (i + 1) / 2 * 2;
            if(len > anslen){
                anslen = len;
                ansv = mp(i, mx);
            }
        }

        if(ansv != mp(-1, -1)){
            string tmp;
            int i = ansv.F, mx = ansv.S;
            for(int j = 0; j < 2 * n + 1; j++){
                if(j % 2 == 0) continue;
                if(j <= i || j >= 2 * n - i || (mx != i && j >= mx - r[mx] && j <= mx + r[mx])) tmp += t(j);
            }
            if(tmp.size() > ans.size()) ans = tmp;
        }

        reverse(iter(s));
        reverse(iter(r));
        lp.clear();
        lp.resize(2 * n + 1, -1);
        for(int i = 0; i <= n; i++){
            r[i]--;
            lp[i - r[i]] = i;
        }
        mx = -1;
        ansv = mp(-1, -1);
        anslen = ans.size();
        for(int i = -1; i < n; i++){
            if(i >= 0 && t(i) != t(2 * n - i)) break;
            mx = max(mx, lp[i + 1]);
            int rmx = min(r[mx], mx - i - 1);
            int len = rmx + (i + 1) / 2 * 2;
            if(len > anslen){
                anslen = len;
                ansv = mp(i, mx);
            }
        }

        if(ansv != mp(-1, -1)){
            string tmp;
            int i = ansv.F, mx = ansv.S;
            for(int j = 0; j < 2 * n + 1; j++){
                if(j % 2 == 0) continue;
                if(j <= i || j >= 2 * n - i || (mx != i && j >= mx - r[mx] && j <= mx + r[mx])) tmp += t(j);
            }
            reverse(iter(tmp));
            if(tmp.size() > ans.size()) ans = tmp;
        }

        cout << ans << '\n';
    }

    return 0;
}