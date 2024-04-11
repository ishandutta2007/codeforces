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

bool check(int x, int a, int y, int b, ll k, vector<int>& p, int c){
    int xc = 0, yc = 0, xyc = 0;
    for(int i = 1; i <= c; i++){
        if(i % a == 0 && i % b == 0) xyc++;
        else if(i % a == 0) xc++;
        else if(i % b == 0) yc++;
    }

    ll t = 0;
    for(int i = 0; i < c; i++){
        if(xyc) t += p[i] * (x + y), xyc--;
        else if(xc) t += p[i] * x, xc--;
        else if(yc) t += p[i] * y, yc--;
        else break;
    }

    return t >= k;
}

int main(){
    StarBurstStream

    int q;
    cin >> q;

    while(q--){

        int n;
        cin >> n;

        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i], p[i] /= 100;
        gsort(p);

        ll x, a, y, b, k;
        cin >> x >> a >> y >> b >> k;

        if(x < y) swap(x, y), swap(a, b);

        int l = 1, r = n;
        while(l < r){
            int m = (l + r) / 2;
            if(check(x, a, y, b, k, p, m)) r = m;
            else l = m + 1;
        }

        if(check(x, a, y, b, k, p, l)) cout << l << "\n";
        else cout << "-1\n";
    }

    return 0;
}