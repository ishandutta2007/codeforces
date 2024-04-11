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


int main(){
    StarBurstStream

    ll u, v;
    cin >> u >> v;

    vector<int> ans(70);
    int now = 0;
    while(u > 0 || v > 0){
        if((u & 1) && (v & 1)){
            ans[now]++;
        }
        else if(!(u & 1) && !(v & 1)){
        }
        else if(!(u & 1) && (v & 1)){
            if(now != 0) ans[now - 1] += 2;
            else{
                cout << "-1\n";
                return 0;
            }
        }
        else{
            if(now != 0){
                ans[now]++;
                ans[now - 1] += 2;
                v -= 2;
            }
            else{
                cout << "-1\n";
                return 0;
            }
        }
        if(v < 0){
            cout << "-1\n";
            return 0;
        }
        now++;
        u >>= 1; v >>= 1;
    }

    vector<ll> a;
    while(*max_element(iter(ans))){
        a.eb();
        for(int i = 0; i < 70; i++){
            if(ans[i]) a.back() += (1LL << i), ans[i]--;
        }
    }

    cout << a.size() << "\n";
    printv(a, cout);

    return 0;
}