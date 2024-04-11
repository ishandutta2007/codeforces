#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;
typedef std::pair <int, ll> pii;

int a[N];
ll cnt[N];
ll pre[N], precnt[N];

ll calc(int a, ll b, int c, ll n){
    ll m = (a * n + b) / c;
    if (!m){
        return 0;
    }
    if (!a){
        return (b / c) * (n + 1);
    }
    if (a >= c || b >= c){
        ll ret = (n * (n + 1) / 2) * (a / c);
        ret += (n + 1) * (b / c);
        ret += calc(a % c, b % c, c, n);
        return ret;
    }
    return n * m - calc(c, c - b - 1, a, m - 1);
}

ll calc(ll l, ll r, int a, ll b, int c){
    if (l > r) return 0;
    int x = std::abs(a) / c + 1;
    a += c * x;
    ll ans = calc(a, b, c, r) - calc(a, b, c, l - 1);
    ans -= (r + l) * (r - l + 1) * x / 2;
    return ans;
}

ll calc(ll mid, std::vector <pii> vec){
    ll ans = 0;
    int n = vec.size();
    for (int i = 1, j = 1; i < n; ++ i, j = std::max(i, j)){
        ll cnti = vec[i].second;
        int vi = vec[i].first;
        if (j > i){
            ans += cnti * (cnti + 1) / 2;
            ans += (precnt[j - 1] - precnt[i]) * cnti;
        }
        while (j < n){
            ll cntj = vec[j].second;
            int vj = vec[j].first;
            ll tmp = 0;
            if (j == i){
                ll x = std::min(cnti, mid / vi);
                tmp = 1ll * x * (x + 1) / 2 + x * (cnti - x);
            }
            else{
                ll num = mid - (pre[j - 1] - pre[i]);
                if (num <= 0){
                    break;
                }
                ll up = std::max(0ll, std::min(cnti, (num - vj * cntj) / vi));
                tmp = up * cntj;
                ll down = std::min(cnti, num / vi);
                tmp += calc(up + 1, down, -vi, num, vj);
            }
            ans += tmp;
            if (!tmp){
                break;
            }
            ++ j;
        }
        -- j;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::map <int, int> map;
    map[a[0]] = 1;
    for (int i = 1; i < n; ++ i){
        std::map <int, int> tmp;
        for (auto u : map){
            tmp[std::__gcd(u.first, a[i])] += u.second;
            cnt[u.first] += u.second;
        }
        ++ tmp[a[i]];
        map = tmp;
    }
    for (auto u : map){
        cnt[u.first] += u.second;
    }
    std::vector <pii> vec = {{0, 0}};
    for (int i = 1; i < N; ++ i){
        if (cnt[i]){
            vec.push_back({i, cnt[i]});
        }
    }
    for (int i = 1, sz = vec.size(); i < sz; ++ i){
        pre[i] = pre[i - 1] + vec[i].first * vec[i].second;
        precnt[i] = precnt[i - 1] + vec[i].second;
    }
    ll left = 1, right = 1ll * N * N * N;
    ll x = 1ll * n * (n + 1) / 2;
    x = x * (x + 1) / 2;
    x = (x + 1) / 2;
    while (left < right){
        ll mid = (left + right) >> 1;
        if (calc(mid, vec) < x){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    printf("%lld\n", left);
    return 0;
}