#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
using tuplis = array<ll, 3>;
const ll LINF = 0x1fffffffffffffff;

struct T{
    ll plus, minus;
    void operator+=(const T& a){
        if(plus == LINF) plus = a.plus;
        if(minus == LINF) minus = a.minus;
    }
    T filp(ll c) const {
        return {minus == LINF ? LINF : c - minus, plus == LINF ? LINF : c - plus};
    }
    bool operator==(const T& a) const {
        return plus == a.plus && minus == a.minus;
    }
    ll solve() const {
        return (minus - plus) / 2;
    }
};
int main(){
    ll n, m;
    cin >> n >> m;
    vector<tuplis> edge(m);
    vector<vector<pll>> g(n);
    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--; c *= 2;
        edge[i] = {a, b, c};
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    vector potential(n, T{LINF,LINF});
    vector ans(n, LINF);
    vector<ll> q;
    for(ll i = 0; i < n; i++){
        if(ans[i] != LINF) continue;
        q.push_back(i);
        potential[i].plus = 0;
        ll x = LINF;
        vector<ll> p;
        while(q.size()){
            ll at = q.back();
            q.pop_back();
            if(potential[at].plus == LINF) p.push_back(potential[at].minus);
            else p.push_back(-potential[at].plus);
            for(auto [i, c] : g[at]){
                if(potential[i] == T{LINF,LINF}) q.push_back(i);
                potential[i] += potential[at].filp(c);
                if(potential[i].plus != LINF && potential[i].minus != LINF) x = potential[i].solve();
            }
        }
        if(x == LINF){
            auto cen = p.begin() + p.size() / 2;
            nth_element(p.begin(), cen, p.end());
            x = *cen;
        }
        q.push_back(i);
        ans[i] = x;
        while(q.size()){
            ll at = q.back();
            q.pop_back();
            for(auto [i, c] : g[at]){
                if(ans[i] == LINF){
                    q.push_back(i);
                    if(potential[i].plus == LINF) ans[i] = potential[i].minus - x;
                    else ans[i] = potential[i].plus + x;
                }
            }
        }
    }
    for(auto [a, b, c] : edge) if(ans[a] + ans[b] != c) return puts("NO") & 0;
    puts("YES");
    for(ll i = 0; i < n; i++) printf("%.1f%c", ans[i] / 2.0, " \n"[i + 1 == n]);
}