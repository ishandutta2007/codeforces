#include <bits/stdc++.h>

const int N = 1000010;
using pii = std::pair <int, int>;

int dis[N];
int a[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    int s, d;
    scanf("%d%d", &s, &d);
    -- s;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::set <pii> set;
    std::priority_queue<pii> pq;
    for (int i = 0; i < n; ++ i){
        set.insert({a[i], 0});
    }
    memset(dis, -1, sizeof(dis));
    auto valid = [&](int pos, int round){
        dis[pos] = round;
        auto it = set.find({pos, 0});
        auto nxt = set.erase(it);
        auto insert = [&](pii p1, pii p2){
            if (p1.second + p2.second == 1){
                if (p1.second == 1){
                    std::swap(p1, p2);
                }
                pq.push({-std::abs(p1.first - p2.first), p1.first});
            }
        };
        if (nxt != set.end() && nxt != set.begin()){
            auto prv = std::prev(nxt);
            insert(*prv, *nxt);
        }
        auto insert1 = [&](int pos){
            auto pair = set.insert({pos, 1});
            if (!pair.second){
                return;
            }
            auto it = pair.first;
            if (it != set.end()){
                auto nxt = std::next(it);
                if (nxt != set.end()){
                    insert(*it, *nxt);
                }
            }
            if (it != set.begin()){
                auto prv = std::prev(it);
                insert(*it, *prv);
            }
        };
        insert1(pos - d);
        insert1(pos + d);
    };
    valid(a[s], 0);
    for (int i = 0; i <= 1000000; ++ i){
        while (!pq.empty() && -pq.top().first <= i){
            pii p = pq.top();
            pq.pop();
            if (dis[p.second] == -1){
                valid(p.second, i);
            }
        }
    }
    while (q --){
        int i, k;
        scanf("%d%d", &i, &k);
        -- i;
        assert(dis[a[i]] != -1);
        if (dis[a[i]] <= k){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return 0;
}

/*
2 1 2 500000
206639 775237
1 123834
 */