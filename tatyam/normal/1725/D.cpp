#include <bits/extc++.h>
using namespace std;
using ll = long long;


using namespace __gnu_pbds;
template<class T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> cntA;
    {
        ll sum = 0;
        for(ll i = 2; sum < N; i++){
            cntA.push_back(i / 2);
            sum += i / 2;
        }
        cntA.back() -= sum - N;
    }
    {
        ll ans = 0;
        for(ll i = 0; i < cntA.size(); i++){
            ans += (i + 1) * cntA[i];
        }
        cout << ans << '\n';
    }
    const ll mx = *max_element(cntA.begin(), cntA.end());
    vector<pair<ll, ll>> odds; //  x 
    for(ll x = 0; x < mx; x++) odds.emplace_back(x * 2 + 1, cntA.size() - x * 2 - (cntA.back() <= x));
    vector<tuple<ll, double, ll>> events; //  / 
    {
        for(auto [odd, num] : odds){
            const double lg = log2(odd);
            const ll a = floor(lg);
            const double b = lg - a;
            events.emplace_back(a, b, odd);
            events.emplace_back(a + num, b, -odd);
        }
    }
    events.emplace_back(INT_MAX, 0, 0);
    sort(events.begin(), events.end(), greater<>{});
    // for(auto [a, b, c] : events) cerr << a << ' ' << b << ' ' << c << endl;
    vector<ll> P(Q);
    for(ll& p : P) cin >> p;
    reverse(P.begin(), P.end());
    gpp_map<double, ll> A; //  -> A 
    pair<ll, double> at = {0, 0};
    ll& offset = at.first;
    ll p_cnt = 0, order = 0;
    while(P.size()){
        while(1){
            auto [a, b, cost] = events.back();
            if(a > at.first) break;
            events.pop_back();
            // 
            if(cost > 0){
                A[b] = cost - offset;
            }
            // 
            else{
                A.erase(b);
            }
        }
        // 
        const ll jump = A.size() - order;
        // 
        if(p_cnt + jump >= P.back()){
            auto p = A.find_by_order(order + (P.back() - p_cnt - 1));
            cout << offset + p->second << '\n';
            order += P.back() - p_cnt;
            p_cnt = P.back();
            P.pop_back();
            at.second = nextafter(p->first, INFINITY);
            continue;
        }
        // 1 
        {
            offset++;
            at.second = 0;
            p_cnt += A.size() - order;
            order = 0;
            continue;
        }
    }
}