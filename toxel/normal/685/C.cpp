#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;
using pii = std::pair <ll, ll>;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct P{
    ll x, y, z;

    explicit P(ll x = 0, ll y = 0, ll z = 0):x(x), y(y), z(z){}

    bool operator <(const P &p)const{return x < p.x;}

    void read(){
        scanf("%lld%lld%lld", &x, &y, &z);
    }
};

pii merge(pii p1, pii p2){
    return {std::max(p1.first, p2.first), std::min(p1.second, p2.second)};
}

ll divide_up(ll n){
    return (n & 1) + (n >> 1);
}

void solve(){
    int n;
    scanf("%d", &n);
    std::vector <P> ps(n);
    for (int i = 0; i < n; ++ i){
        ps[i].read();
    }
    std::sort(ps.begin(), ps.end());
    std::multiset <ll> set[8];
    for (int i = 0; i < n; ++ i){
        set[0].insert(ps[i].y + ps[i].z + ps[i].x);
        set[1].insert(ps[i].y + ps[i].z - ps[i].x);
        set[4].insert(ps[i].y - ps[i].z + ps[i].x);
        set[5].insert(ps[i].y - ps[i].z - ps[i].x);
    }
    ll ans = INF;
    P pos;
    auto check = [&](ll a, ll b, ll c, ll d, ll dis) -> pii{
        pii ret = {-INF, INF};
        if (a != -INF && c != -INF){
            if (c - dis > b + dis || a - dis > d + dis){
                return {INF, -INF};
            }
        }
        if (a != -INF){
            ret.first = std::max(ret.first, divide_up(a - b - 2 * dis));
        }
        if (c != -INF){
            ret.second = std::min(ret.second, (d - c + 2 * dis) >> 1);
        }
        return ret;
    };
    auto update = [&](ll x1, ll x2){
        ll a[2] = {-INF, -INF}, b[2] = {INF, INF};
        ll c[2] = {-INF, -INF}, d[2] = {INF, INF};
        for (int i = 0; i < 8; i += 4){
            if (!set[0 + i].empty()){
                a[i / 4] = *(-- set[0 + i].end());
                b[i / 4] = *(set[1 + i].begin());
            }
            if (!set[2 + i].empty()){
                c[i / 4] = *(-- set[2 + i].end());
                d[i / 4] = *(set[3 + i].begin());
            }
        }
        ll left = 0, right = INF;
        while (left < right){
            ll mid = (left + right) / 2;
            pii p = check(a[0], b[0], c[0], d[0], mid);
            p = merge(p, check(a[1], b[1], c[1], d[1], mid));
            p = merge(p, {x1, x2});
            if (p.first <= p.second){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        auto check1 = [&](ll x1, ll mid){
            ll y1 = std::max(a[0] - mid - x1, c[0] - mid + x1);
            ll y2 = std::min(b[0] + mid + x1, d[0] + mid - x1);
            ll z1 = std::max(a[1] - mid - x1, c[1] - mid + x1);
            ll z2 = std::min(b[1] + mid + x1, d[1] + mid - x1);
            if (((y1 + z1) & 1) == 1){
                if (y1 < y2){
                    ++ y1;
                }
                else if (z1 < z2){
                    ++ z1;
                }
                else{
                    return false;
                }
            }
            pos = P(x1, (y1 + z1) / 2, (y1 - z1) / 2);
            return true;
        };
        auto check2 = [&](ll mid){
            pii p = check(a[0], b[0], c[0], d[0], mid);
            p = merge(p, check(a[1], b[1], c[1], d[1], mid));
            p = merge(p, {x1, x2});
            if (p.first <= p.second && mid < ans){
                if (check1(p.first, mid) || (p.first < p.second && check1(p.first + 1, mid))){
                    ans = mid;
                }
            }
        };
        check2(left);
        check2(left + 1);
    };
    auto erase = [&](std::multiset <ll> &set, ll value){
        auto u = set.find(value);
        if (u != set.end()){
            set.erase(u);
        }
    };
    update(-INF, ps[0].x);
    for (int i = 0; i < n; ++ i){
        erase(set[0], ps[i].y + ps[i].z + ps[i].x);
        erase(set[1], ps[i].y + ps[i].z - ps[i].x);
        erase(set[4], ps[i].y - ps[i].z + ps[i].x);
        erase(set[5], ps[i].y - ps[i].z - ps[i].x);
        set[2].insert(ps[i].y + ps[i].z - ps[i].x);
        set[3].insert(ps[i].y + ps[i].z + ps[i].x);
        set[6].insert(ps[i].y - ps[i].z - ps[i].x);
        set[7].insert(ps[i].y - ps[i].z + ps[i].x);
        update(ps[i].x, i < n - 1 ? ps[i + 1].x : INF);
    }
    printf("%lld %lld %lld\n", pos.x, pos.y, pos.z);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}