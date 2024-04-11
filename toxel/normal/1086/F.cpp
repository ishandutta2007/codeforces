#include<bits/stdc++.h>

const int moder = 998244353;
const int inv2 = (moder + 1) >> 1;
const int inv3 = (moder + 1) / 3;
const int inv6 = 1ll * inv2 * inv3 % moder;
const int N = 60;
typedef std::pair <int, int> pii;

int sum1(int n){
    return 1ll * n * (n + 1) % moder * inv2 % moder;
}

int sum2(int n){
    return 1ll * n * (n + 1) % moder * (2 * n + 1) % moder * inv6 % moder;
}

int calc(int a, int b, int c, int t){
    return (1ll * a * t % moder * t + 1ll * b * t + c) % moder;
}

int ntime;
pii p[N];
bool vis[N];

struct event{
    int sit;
    int id;
    bool type;

    int getsit()const{
        return (sit << 1 | 1) + (type ? ntime + 1 : -ntime - 1);
    }

    bool operator < (const event &t){
        return getsit() < t.getsit() || (getsit() == t.getsit() && (type < t.type));
    }

    bool operator == (const event &t){
        return sit == t.sit && type == t.type;
    }
};

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    std::vector <event> xvec;
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
        xvec.push_back({x, i, true});
        xvec.push_back({x, i, false});
    }
    std::vector <int> times;
    times.push_back(0);
    times.push_back((t + 1) << 1);
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            int x = std::abs(p[j].first - p[i].first);
            if (x <= t << 1){
                times.push_back(x);
            }
            x = std::abs(p[j].second - p[i].second);
            if (x <= (t + 1) << 1){
                times.push_back(x);
            }
        }
    }
    std::sort(times.begin(), times.end());
    times.erase(std::unique(times.begin(), times.end()), times.end());
    int prevarea = 0;
    int ans = 0;
    for (int i = 0, sz = times.size(); i < sz - 1; ++ i){
        ntime = times[i];
        int left = ntime + (ntime & 1);
        int right = (times[i + 1] - 1) >> 1 << 1;
        if (left > right){
            continue;
        }
        std::sort(xvec.begin(), xvec.end());
        int a = 0, b = 0, c = 0;
        for (int j = 0, k = 0, sz1 = xvec.size(); j < sz1; j = k){
            while (k < sz1 && xvec[k] == xvec[j]){
                vis[xvec[k].id] = !xvec[k].type;
                ++ k;
            }
            if (k == sz1){
                break;
            }
            int a1 = (xvec[k].type ? 1 : -1) - (xvec[j].type ? 1 : -1);
            int b1 = (xvec[k].sit << 1 | 1) - (xvec[j].sit << 1 | 1);
            b1 += (xvec[k].type ? 1 : -1) - (xvec[j].type ? 1 : -1);
            a1 += a1 < 0 ? moder : 0;
            b1 += a1 < 0 ? moder : 0;
            int a2 = 0, b2 = 0;
            std::vector <event> yvec;
            for (int i = 0; i < n; ++ i){
                if (vis[i]){
                    yvec.push_back({p[i].second, i, true});
                    yvec.push_back({p[i].second, i, false});
                }
            }
            std::sort(yvec.begin(), yvec.end());
            int level = 0;
            for (int u = 0, sz2 = yvec.size(); u < sz2 - 1; ++ u){
                level += yvec[u].type ? -1 : 1;
                if (level){
                    a2 += (yvec[u + 1].type ? 1 : -1) - (yvec[u].type ? 1 : -1);
                    b2 += (yvec[u + 1].sit << 1 | 1) - (yvec[u].sit << 1 | 1);
                    b2 += (yvec[u + 1].type ? 1 : -1) - (yvec[u].type ? 1 : -1);
                    a2 %= moder;
                    b2 %= moder;
                }
            }
            a2 += a2 < 0 ? moder : 0;
            b2 += b2 < 0 ? moder : 0;
            a = (a + 1ll * a1 * a2) % moder;
            b = (b + 1ll * a1 * b2 + 1ll * a2 * b1) % moder;
            c = (c + 1ll * b1 * b2) % moder;
        }
        ans = (ans + 1ll * (calc(a, b, c, left) - prevarea) * left) % moder;
        int coe1 = 16ll * a % moder;
        int coe2 = (4ll * b - 8ll * a) % moder;
        ans = (ans + 1ll * coe1 * (sum2(right >> 1) - sum2(left >> 1))) % moder;
        ans = (ans + 1ll * coe2 * (sum1(right >> 1) - sum1(left >> 1))) % moder;
        ans += ans < 0 ? moder : 0;
        prevarea = calc(a, b, c, right);
    }
    for (int i = 0; i < 3; ++ i){
        ans = 1ll * ans * inv2 % moder;
    }
    printf("%d\n", ans);
    return 0;
}