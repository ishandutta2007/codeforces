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

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
    }
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    BIT.resize(n + 1);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        modify(a, 1);
    }

    while(q--){
        int k;
        cin >> k;
        if(k > 0){
            modify(k, 1);
            continue;
        }
        k = -k;
        int t = 0;
        int now = 0;
        for(int i = __lg(n); i >= 0; i--){
            if(t + (1 << i) <= n && now + BIT[t + (1 << i)] < k){
                t += 1 << i;
                now += BIT[t];
            }
        }
//        cerr << t << " " << now << "\n";
        modify(t + 1, -1);
    }

    for(int i = 1; i <= n; i++){
        if(query(i)){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "0\n";

    return 0;
}