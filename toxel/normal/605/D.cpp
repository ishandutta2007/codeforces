#include<bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;
typedef std::pair <int, int> pii;
//typedef std::pair <pii, int> piii;

int a[N], b[N], c[N], d[N], x[N];
std::vector <pii> vec[N];
pii seg[MAX << 1];
int sit[N];
int dis[N], pre[N];

void add(int sit, pii value){
    seg[sit + MAX] = value;
    for (sit += MAX, sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

pii query(int l, int r){
    pii ret = {INT_MAX, INT_MAX};
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::min(ret, seg[l ++]);
        if (r & 1) ret = std::min(ret, seg[-- r]);
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        x[cnt ++] = a[i];
        x[cnt ++] = c[i];
    }
    std::sort(x, x + cnt);
    cnt = std::unique(x, x + cnt) - x;
    for (int i = 1; i <= n; ++ i){
        a[i] = std::lower_bound(x, x + cnt, a[i]) - x;
        c[i] = std::lower_bound(x, x + cnt, c[i]) - x;
        vec[a[i]].push_back({b[i], i});
    }
    for (int i = 0; i < N; ++ i){
        std::sort(vec[i].begin(), vec[i].end());
        if (sit[i] == vec[i].size()){
            add(i, {INT_MAX, INT_MAX});
        }
        else{
            add(i, vec[i][sit[i] ++]);
        }
    }
    std::queue <int> queue;
    queue.push(0);
    memset(dis, -1, sizeof(dis));
    dis[0] = 0;
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        while (true){
            pii p = query(0, c[u]);
            if (p.first > d[u]){
                break;
            }
            pre[p.second] = u;
            dis[p.second] = dis[u] + 1;
            queue.push(p.second);
            int x = a[p.second];
            if (sit[x] == vec[x].size()){
                add(x, {INT_MAX, INT_MAX});
            }
            else{
                add(x, vec[x][sit[x] ++]);
            }
        }
    }
    printf("%d\n", dis[n]);
    if (!~dis[n]){
        return 0;
    }
    std::vector <int> ans;
    int now = n;
    while (now){
        ans.push_back(now);
        now = pre[now];
    }
    std::reverse(ans.begin(), ans.end());
    for (int i = 0, sz = ans.size(); i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}