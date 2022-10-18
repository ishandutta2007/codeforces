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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, m;
    cin >> n>> m;

    map<int, int> s;
    priority_queue<pii, vector<pii>, greater<>> pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s[x] = -1;
        if(s[x - 1] == 0){
            s[x - 1] = 1;
            pq.emplace(mp(1, x - 1));
        }
        if(s[x  + 1] == 0){
            s[x + 1] = 1;
            pq.emplace(mp(1, x + 1));
        }
    }
    //cerr << pq.size() << "\n";

    vector<int> y(m);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        //cerr << i << " " << pq.size() << "\n";

        while(s[pq.top().S] == -1) pq.pop();
        y[i] = pq.top().S;
        int x = y[i];
        int t = pq.top().F;
        ans += t;
        pq.pop();

        if(s[x - 1] > t + 1 || s[x - 1] == 0){
            s[x - 1] = t + 1;
            pq.emplace(mp(t + 1, x - 1));
        }
        if(s[x  + 1] > t + 1|| s[x + 1] == 0){
            s[x + 1] = t + 1;
            pq.emplace(mp(t + 1, x + 1));
        }

    }

    cout << ans << "\n";
    printv(y, cout);

    return 0;
}