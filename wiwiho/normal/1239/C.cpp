//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

#define tlll tuple<ll, ll, ll>

int main(){
    StarBurstStream

    ll n, p;
    cin >> n >> p;

    vector<ll> ans(n);

    priority_queue<tlll, vector<tlll>, greater<>> event;
    priority_queue<ll, vector<ll>, greater<>> want;
    set<ll> inq;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        event.push(make_tuple(t, 1, i));
    }

    ll cur = 0, qt = 0;

    while(!event.empty()){

        ll tmp = get<0>(event.top());
        while(!event.empty() && get<0>(event.top()) == tmp){
            ll time = get<0>(event.top());
            ll type = get<1>(event.top());
            ll id = get<2>(event.top());
            event.pop();

            if(type) want.push(id);
            else{
                ans[id] = time;
                inq.erase(id);
            }

            cur = time;
        }

        //cerr << want.top() << "\n";
        //printv(inq, cerr);
        while(!want.empty() && (inq.empty() || want.top() < *inq.begin())){
            inq.insert(want.top());
            ll t = max(cur, qt) + p;
            event.push(make_tuple(t, 0, want.top()));
            qt = max(qt, t);
            want.pop();
        }
    }

    printv(ans, cout);

    return 0;
}