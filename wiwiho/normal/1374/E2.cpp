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
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
    int l = -1, r = -1, sum = 0, pri = rnd(), sz = 1;
    pii v = mp(-1, -1);
};

vector<Node> tr(1000000);

void pull(int r){
    if(r != -1){
        tr[r].sum = tr[r].v.F;
        tr[r].sz = 1;
        if(tr[r].l != -1){
            tr[r].sum += tr[tr[r].l].sum;
            tr[r].sz += tr[tr[r].l].sz;
        }
        if(tr[r].r != -1){
            tr[r].sum += tr[tr[r].r].sum;
            tr[r].sz += tr[tr[r].r].sz;
        }
    }
}

void printtr(int now){
    if(now == -1) return;
    printtr(tr[now].l);
    cerr << tr[now].v << " ";
    printtr(tr[now].r);
}

void merge(int a, int b, int& r){
    if(a == -1 && b == -1) r = -1;
    else if(a == -1) r = b;
    else if(b == -1) r = a;
    else{
        if(tr[a].pri > tr[b].pri){
            r = a;
            merge(tr[a].r, b, tr[a].r);
        }
        else{
            r = b;
            merge(a, tr[b].l, tr[b].l);
        }
    }
    pull(r);
}

void split1(int a, pii k, int& r1, int& r2){
    if(a == -1){
        r1 = r2 = -1;
        return;
    }
    if(tr[a].v < k){
        r1 = a;
        split1(tr[a].r, k, tr[a].r, r2);
    }
    else{
        r2 = a;
        split1(tr[a].l, k, r1, tr[a].l);
    }
    pull(a);
}

void split2(int a, int k, int& r1, int& r2){
    if(a == -1){
        r1 = r2 = -1;
        return;
    }
    if(k == 0){
        r1 = -1;
        r2 = a;
        return;
    }
    if(tr[a].l == -1 || tr[tr[a].l].sz < k){
        r1 = a;
        if(tr[a].l != -1) split2(tr[a].r, k - tr[tr[a].l].sz - 1, tr[a].r, r2);
        else split2(tr[a].r, k - 1, tr[a].r, r2);
    }
    else{
        r2 = a;
        split2(tr[a].l, k, r1, tr[a].l);
    }
    pull(a);
}
int ts = 0;

int node(int v, int id){
    int r = ts++;
    tr[r].v = mp(v, id);
    return r;
}

void rmv(pii a, int& r){
//    cerr << "rmv " << a << "\n";
    int r1 = -1, r2 = -1;
    split1(r, a, r1, r2);
    int r3 = -1;
    split2(r2, 1, r3, r2);
//    printtr(r1);
//    cerr << "\n";
//    printtr(r2);
//    cerr << "\n";
//    printtr(r3);
//    cerr << "\n";
    merge(r1, r2, r);
//    printtr(r);
//    cerr << "\n";
}

void add(pii a, int& r){
    int r1 = -1, r2 = -1;
    split1(r, a, r1, r2);
    int nd = node(a.F, a.S);
    merge(r1, nd, r1);
    merge(r1, r2, r);
}

int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> all(1), a(1), b(1), no;
    int r = -1;

    for(int i = 1; i <= n; i++){
        int t, aa, bb;
        cin >> t >> aa >> bb;
        if(aa && bb) all.eb(mp(t, i));
        else if(aa) a.eb(mp(t, i));
        else if(bb) b.eb(mp(t, i));
        else no.eb(mp(t, i));
        add(mp(t, i), r);
    }
//    printtr(r);
//    cerr << "\n";

    lsort(all);
    lsort(a);
    lsort(b);

    int now = 0;
    int ans = MAX;
    int p = -1;
    for(int i = 1; i <= k; i++){
        if(i >= a.size() || i >= b.size()) break;
        rmv(a[i], r);
        rmv(b[i], r);
        now += a[i].F;
        now += b[i].F;
    }
//    printtr(r);
//    cerr << "\n";
    for(int i = 0; i < all.size() && i <= k; i++){
        if(i){
            rmv(all[i], r);
            now += all[i].F;
        }
        if(k - i >= a.size() || k - i >= b.size()) continue;
        if(i && k - i + 1 < a.size() && k - i + 1 < b.size()){
            add(a[k - i + 1], r);
            add(b[k - i + 1], r);
            now -= a[k - i + 1].F;
            now -= b[k - i + 1].F;
        }
        if(i + 2 * (k - i) > m) continue;
//        cerr << i << "  ";
//        printtr(r);
//        cerr << "\n";
        int r1 = -1, r2 = -1;
        split2(r, m - i - 2 * (k - i), r1, r2);
        if(tr[r1].sum + now < ans){
            ans = tr[r1].sum + now;
            p = i;
        }
        merge(r1, r2, r);
    }

    if(p == -1){
        cout << "-1\n";
        return 0;
    }
//    cerr << p << "\n";

    cout << ans << "\n";
    vector<pii> tmp;
    vector<int> id;

    for(pii i : no) tmp.eb(i);
    for(int i = 1; i < all.size(); i++){
        if(i <= p) id.eb(all[i].S);
        else tmp.eb(all[i]);
    }
    for(int i = 1; i < a.size(); i++){
        if(i <= k - p) id.eb(a[i].S);
        else tmp.eb(a[i]);
    }
    for(int i = 1; i < b.size(); i++){
        if(i <= k - p) id.eb(b[i].S);
        else tmp.eb(b[i]);
    }
    lsort(tmp);
//    printv(id, cerr);
//    printv(tmp, cerr);
    for(int i = 0; id.size() < m; i++) id.eb(tmp[i].S);
    printv(id, cout);

    return 0;
}