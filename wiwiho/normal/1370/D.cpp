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

bool check(int n, int k, int m, vector<int>& a, int tmp){
//    cerr << "test " << m << " ";

    queue<int> g, l;
    for(int i = 0; i < n; i++){
        if(a[i] <= m) l.push(i);
        else g.push(i);
    }
//    cerr << g.size() << " " << l.size() << "\n";

    if(l.size() >= k) return true;
    if(l.empty()) return false;

    int lst = -1;
    for(int i = 0; i < k; i++){
        while(!l.empty() && l.front() < lst) l.pop();
        while(!g.empty() && g.front() < lst) g.pop();
        if(l.empty() && g.empty()) return false;
//        cerr << i << " " << g.size() << " " << l.size() << "\n";
        if(i % 2 == tmp % 2){
            if(!l.empty() && (g.empty() || l.front() < g.front())){
                lst = l.front();
                l.pop();
//                cerr << i << " " << lst << "\n";
            }
            else{
                lst = g.front();
                g.pop();
//                cerr << i << " " << lst << "\n";
            }
            continue;
        }
        if(l.empty()) return false;
        lst = l.front();
        l.pop();
//        cerr << i << " " << lst << "\n";
    }

    return true;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = 1000000000;
    while(l < r){
        int m = (l + r) / 2;
//        bool aaa = check(n, k, m, a);
//        cerr << "check " << m << " " << aaa << "\n";
        if(check(n, k, m, a, 1) || check(n, k, m, a, 0)) r = m;
        else l = m + 1;
    }

    cout << l << "\n";

    return 0;
}