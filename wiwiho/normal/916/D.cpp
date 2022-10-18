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



struct Trie1{

    struct Node{
        vector<int> c;
        int v = -1;
        Node(){
            c.resize(26);
        };
        int& operator[](char t){
            return c[t - 'a'];
        }
    };

    vector<Node> tr;
    int ts = 0;

    int setv(int now, string& s, int v, int oid){
        int id = ts++;
        if(oid != -1) tr[id] = tr[oid];
        if(now == s.size()){
            tr[id].v = v;
            return id;
        }
        tr[id][s[now]] = setv(now + 1, s, v, tr[id][s[now]]);
        return id;
    }

    int query(int now, string& s, int id){
        if(id == -1) return -1;
        if(now == s.size()) return tr[id].v;
        return query(now + 1, s, tr[id][s[now]]);
    }

};

struct Trie2{

    struct Node{
        int o = -1, z = -1, v = 0;
        int& operator[](char i){
            return i - '0' ? o : z;
        }
    };

    vector<Node> tr;
    int ts = 0;

    int addv(int now, string& s, int v, int oid){
        int id = ts++;
        if(oid != -1) tr[id] = tr[oid];
        tr[id].v += v;
        if(now == s.size()){
            return id;
        }
        tr[id][s[now]] = addv(now + 1, s, v, tr[id][s[now]]);
        return id;
    }

    int query(int now, string& s, int id){
        if(id == -1) return 0;
        if(now == s.size()) return 0;
        int ans = 0;
        if(s[now] == '1' && tr[id]['0'] != -1) ans += tr[tr[id]['0']].v;
        ans += query(now + 1, s, tr[id][s[now]]);
        return ans;
    }

};

int main(){
    StarBurstStream
    cerr.tie(0);

    Trie1 tr1;
    tr1.tr.resize(2e6);
    Trie2 tr2;
    tr2.tr.resize(6.3e6);

    int q;
    cin >> q;
    vector<int> rt1(q + 1), rt2(q + 1);
    rt1[0] = -1;
    rt2[0] = -1;
    for(int i = 1; i <= q; i++){
        string s;
        cin >> s;

//        cerr << "test " << i << "\n";
//        printv(rt1, cerr);
//        printv(rt2, cerr);
        if(s == "set"){
            int x;
            string a;
            cin >> a >> x;

            int v = tr1.query(0, a, rt1[i - 1]);
            int tmprt = rt2[i - 1];
            if(v != -1){
                string b = bitset<30>(v).to_string();
                tmprt = tr2.addv(0, b, -1, rt2[i - 1]);
            }

            rt1[i] = tr1.setv(0, a, x, rt1[i - 1]);
            string b = bitset<30>(x).to_string();
            rt2[i] = tr2.addv(0, b, 1, tmprt);
        }
        else if(s == "remove"){
            string a;
            cin >> a;
            int v = tr1.query(0, a, rt1[i - 1]);
            rt1[i] = tr1.setv(0, a, -1, rt1[i - 1]);
            if(v != -1){
                string b = bitset<30>(v).to_string();
                rt2[i] = tr2.addv(0, b, -1, rt2[i - 1]);
            }
            else rt2[i] = rt2[i - 1];
        }
        else if(s == "query"){
            string a;
            cin >> a;
            rt1[i] = rt1[i - 1];
            rt2[i] = rt2[i - 1];
            int tmp = tr1.query(0, a, rt1[i]);
            if(tmp == -1){
                cout << "-1\n" << flush;
                continue;
            }
            string b = bitset<30>(tmp).to_string();
//            cerr << "qry " << a << " " << tmp << " " << b << "\n";
            cout << tr2.query(0, b, rt2[i]) << "\n" << flush;
        }
        else{
            int d;
            cin >> d;
            rt1[i] = rt1[i - 1 - d];
            rt2[i] = rt2[i - 1 - d];
        }

    }

    return 0;
}