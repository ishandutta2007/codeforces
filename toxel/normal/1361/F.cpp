#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    std::less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

const int N = 500010;
using ll = long long;

int p[N], w[N];
int e[N][2];
ll cnt[N];
ll total = 0;
ordered_set set[N];
int pcnt = 0;

void update(int u, int type){
    ll sum = 1ll * set[e[u][0]].size() * set[e[u][1]].size();
    total += type * std::min(cnt[u], sum - cnt[u]);
}

void complete(int u){
    if (e[u][0] == -1 && e[u][1] == -1){
        return;
    }
    if (e[u][0] == -1){
        e[u][0] = ++ pcnt;
    }
    else{
        complete(e[u][0]);
    }
    if (e[u][1] == -1){
        e[u][1] = ++ pcnt;
    }
    else{
        complete(e[u][1]);
    }
}

void insert(int u, int pos, int value){
    if (e[u][0] == -1){
        return;
    }
    if (pos <= u){
        update(u, -1);
        cnt[u] += set[e[u][1]].order_of_key(value);
        set[e[u][0]].insert(value);
        update(u, 1);
        insert(e[u][0], pos, value);
    }
    else{
        update(u, -1);
        cnt[u] += set[e[u][0]].size() - set[e[u][0]].order_of_key(value);
        set[e[u][1]].insert(value);
        update(u, 1);
        insert(e[u][1], pos, value);
    }
}

void erase(int u, int pos, int value){
    if (e[u][0] == -1){
        return;
    }
    if (pos <= u){
        update(u, -1);
        cnt[u] -= set[e[u][1]].order_of_key(value);
        set[e[u][0]].erase(value);
        update(u, 1);
        erase(e[u][0], pos, value);
    }
    else{
        update(u, -1);
        cnt[u] -= set[e[u][0]].size() - set[e[u][0]].order_of_key(value);
        set[e[u][1]].erase(value);
        update(u, 1);
        erase(e[u][1], pos, value);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i < n; ++ i){
        scanf("%d", &w[i]);
    }
    std::vector <int> stack;
    memset(e, -1, sizeof(e));
    int root = -1;
    for (int i = 1; i < n; ++ i){
        while (!stack.empty() && w[stack.back()] > w[i]){
            stack.pop_back();
        }
        if (stack.empty()){
            e[i][0] = root;
            root = i;
        }
        else{
            e[i][0] = e[stack.back()][1];
            e[stack.back()][1] = i;
        }
        stack.emplace_back(i);
    }
    pcnt = n - 1;
    complete(root);
    for (int i = 1; i <= n; ++ i){
        insert(root, i, p[i]);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int x, y;
        scanf("%d%d", &x, &y);
        erase(root, x, p[x]);
        erase(root, y, p[y]);
        insert(root, x, p[y]);
        insert(root, y, p[x]);
        std::swap(p[x], p[y]);
        printf("%lld\n", total);
    }
}