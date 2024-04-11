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

struct Node{
    int one = -1;
    int zero = -1;
    int cnt = 0;
};

vector<Node> tr;
int ts = 1;

vector<ll> one(30), zero(30);
int add(string& s, int now, int id){
    if(id == -1) id = ts++;
    tr[id].cnt++;
//    cerr << s << " " << now << " " << id << " " << tr[id].cnt << "\n";
    if(now == s.size()){
        return id;
    }
    if(s[now] == '0'){
        if(tr[id].one != -1) zero[now] += tr[tr[id].one].cnt;
        tr[id].zero = add(s, now + 1, tr[id].zero);
    }
    else{
        if(tr[id].zero != -1) one[now] += tr[tr[id].zero].cnt;
        tr[id].one = add(s, now + 1, tr[id].one);
    }
    return id;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    tr.resize(n * 32);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        string s = bitset<30>(a).to_string();
        add(s, 0, 0);
    }
//    printv(one, cerr);
//    printv(zero, cerr);

    ll ans = 0;
    ll cnt = 0;
    for(int i = 0; i < 30; i++){
        if(zero[i] <= one[i]) cnt += zero[i];
        else{
//            cerr << "test " << i << " " << zero[i] << " " << one[i] << "\n";
            cnt += one[i];
            ans |= 1 << (29 - i);
        }
    }

    cout << cnt << " " << ans << "\n";

    return 0;
}