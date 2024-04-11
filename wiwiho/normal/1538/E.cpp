
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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

bool check(string& s, int pos){
    if(pos + 3 >= s.size()) return false;
    return s[pos] == 'h' && s[pos + 1] == 'a' && s[pos + 2] == 'h' && s[pos + 3] == 'a';
}

struct haha{
    ll mid = -1;
    string pre, suf;
    string all;
    haha(){}
    haha(string s){
        if(s.size() < 6){
            all = s;
            return;
        }
        mid = 0;
        for(int i = 0; i + 3 < s.size(); i++){
            mid += check(s, i);
        }
        pre = s.substr(0, 3);
        suf = s.substr((int)s.size() - 3);
    }
    ll cnt(){
        if(mid != -1) return mid;
        ll ans = 0;
        for(int i = 0; i + 3 < all.size(); i++){
            ans += check(all, i);
        }
        return ans;
    }
};

ostream& operator<<(ostream& o, haha& h){
    return o << '(' << h.mid << ',' << h.pre << ',' << h.suf << ',' << h.all << ')';
}

haha operator+(haha& a, haha& b){
    if(a.mid == -1 && b.mid == -1){
        return haha(a.all + b.all);
    }
    else if(b.mid == -1){
        string ns = a.suf + b.all;
        haha h;
        h.mid = a.mid;
        h.pre = a.pre;
        for(int i = 0; i + 3 < ns.size(); i++){
            h.mid += check(ns, i);
        }
        h.suf = ns.substr((int)ns.size() - 3);
        return h;
    }
    else if(a.mid == -1){
        string ns = a.all + b.pre;
        haha h;
        h.mid = b.mid;
        h.suf = b.suf;
        for(int i = 0; i + 3 < ns.size(); i++){
            h.mid += check(ns, i);
        }
        h.pre = ns.substr(0, 3);
        return h;
    }
    else{
        string ns = a.suf + b.pre;
        haha h;
        h.mid = a.mid + b.mid;
        h.pre = a.pre;
        h.suf = b.suf;
        for(int i = 0; i + 3 < ns.size(); i++){
            h.mid += check(ns, i);
        }
        return h;
    }
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;

        map<string, haha> t;

        ll ans = 0;
        for(int i = 0; i < n; i++){
            string name;
            cin >> name;
            string op;
            cin >> op;
            if(op == ":="){
                string v;
                cin >> v;
                t[name] = haha(v);
//                printv(t, cerr);
                ans = t[name].cnt();
                continue;
            }

            string v1, v2;
            cin >> v1 >> op >> v2;
            t[name] = t[v1] + t[v2];
            ans = t[name].cnt();
//            printv(t, cerr);
        }

        cout << ans << "\n";

    }

    return 0;
}