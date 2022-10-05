#include <bits/stdc++.h>
//#define debug

#if defined(debug)
const int MAX = (int) 1e8;
const int BOUND = (int) 8e3;
#else
const int MAX = (int) 1e8;
const int BOUND = (int) 8e3;
#endif

int randint(int n){
    return (rand() << 15 | rand()) % n;
}

#if defined(debug)
std::set <int> vertical_ans;
std::set <int> horizontal_ans;

int answer(int x, int y){
    int min = INT_MAX;
    auto u = vertical_ans.lower_bound(x);
    if (u != vertical_ans.end()){
        min = std::min(min, std::abs(x - *u));
    }
    if (u != vertical_ans.begin()){
        -- u;
        min = std::min(min, std::abs(x - *u));
    }
    u = horizontal_ans.lower_bound(y);
    if (u != horizontal_ans.end()){
        min = std::min(min, std::abs(y - *u));
    }
    if (u != horizontal_ans.begin()){
        -- u;
        min = std::min(min, std::abs(y - *u));
    }
    return min;
}
#endif

int query(int x, int y, bool need_swap = false){
    if (need_swap){
        std::swap(x, y);
    }
    using pii = std::pair <int, int>;
    static std::map <pii, int> map;
    if (map.count({x, y})){
        return map[{x, y}];
    }
    printf("0 %d %d\n", x, y);
    fflush(stdout);

    static int answer_count = 0;
    ++ answer_count;
    assert(answer_count <= 300000);

    int ret;
#if defined(debug)
    ret = answer(x, y);
    printf("%d\n", ret);
#else
    scanf("%d", &ret);
#endif

    return map[{x, y}] = ret;
}

void solve(int l, int r, int y, bool need_swap, std::set <int> &ans, int dis){
    if (l >= r - 1){
        return;
    }
    int mid = (l + r) / 2;
    int ret = query(mid, y, need_swap);
    if (ret == 0){
        ans.insert(mid);
        solve(l, mid, y, need_swap, ans, dis);
        solve(mid, r, y, need_swap, ans, dis);
        return;
    }
    if (ret < dis){
        if (mid - ret > l){
            if (query(mid - ret, y, need_swap) == 0){
                ans.insert(mid - ret);
                solve(l, mid - ret, y, need_swap, ans, dis);
                solve(mid - ret, r, y, need_swap, ans, dis);
                return;
            }
        }
        if (mid + ret < r){
            if (query(mid + ret, y, need_swap) == 0){
                ans.insert(mid + ret);
                solve(l, mid + ret, y, need_swap, ans, dis);
                solve(mid + ret, r, y, need_swap, ans, dis);
                return;
            }
        }
        return;
    }
    int x = mid + dis;
    while (x < r){
        ret = query(x, y, need_swap);
        if (ret < dis){
            ans.insert(x + ret);
            solve(x + ret, r, y, need_swap, ans, dis);
            break;
        }
        x += dis;
    }
    x = mid - dis;
    while (x > l){
        ret = query(x, y, need_swap);
        if (ret < dis){
            ans.insert(x - ret);
            solve(l, x - ret, y, need_swap, ans, dis);
            break;
        }
        x -= dis;
    }
}

int main(){
    srand((unsigned) time(nullptr));
#if defined(debug)
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 10000; ++ i){
        horizontal_ans.insert(randint(2 * MAX + 1) - MAX);
        vertical_ans.insert(randint(2 * MAX + 1) - MAX);
    }
#endif
    int x, y, dis;
    while (true){
        x = randint(2 * MAX + 1) - MAX;
        y = randint(2 * MAX + 1) - MAX;
        dis = query(x, y);
        if (dis > BOUND){
            break;
        }
    }
    std::set <int> vertical, horizontal;
    solve(-MAX - 1, MAX + 1, y, false, vertical, dis);
    solve(-MAX - 1, MAX + 1, x, true, horizontal, dis);

#if defined(debug)
    assert(vertical == vertical_ans);
    assert(horizontal == horizontal_ans);
#endif

    printf("1 %d %d\n", (int) vertical.size(), (int) horizontal.size());
    for (auto u : vertical){
        printf("%d ", u);
    }
    puts("");
    for (auto u : horizontal){
        printf("%d ", u);
    }
    puts("");
    return 0;
}