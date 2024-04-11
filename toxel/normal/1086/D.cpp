#include<bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;
typedef std::pair <int, int> pii;

int seg[3][MAX << 1];

void add(int *seg, int sit, int value){
    seg[sit += MAX] += value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    }
}

int query(int *seg, int l, int r){
    int ret = 0;
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret += seg[l ++];
        if (r & 1) ret += seg[-- r];
    }
    return ret;
}

int id[N];
char s[N], tmp[N];
std::set <int> set[3];
int n, q;

int solve(){
    int ans = 0;
    for (int i = 0; i < 3; ++ i){
        int big = (i + 1) % 3;
        if (set[big].empty()){
            ans += query(seg[i], 0, n - 1);
            continue;
        }
        std::vector <pii> vec;
        int begin = *(set[big].begin());
        int small = (i + 2) % 3;
        if (set[small].empty()){
            vec.push_back({0, begin - 1});
        }
        else{
            int end = *(set[small].begin());
            if (begin >= end){
                vec.push_back({0, n - 1});
            }
            else{
                vec.push_back({0, begin - 1});
                vec.push_back({end, n - 1});
            }
        }
        begin = *(-- set[big].end());
        if (set[small].empty()){
            vec.push_back({begin + 1, n - 1});
        }
        else{
            int end = *(-- set[small].end());
            if (begin <= end){
                vec.push_back({0, n - 1});
            }
            else{
                vec.push_back({begin + 1, n - 1});
                vec.push_back({0, end});
            }
        }
        std::map <int, int> map;
        for (auto u : vec){
            ++ map[u.first];
            -- map[u.second + 1];
        }
        int now = 0, presit = 0;
        for (auto u : map){
            if (now == 2){
                ans += query(seg[i], presit, u.first - 1);
            }
            now += u.second;
            presit = u.first;
        }
    }
    return ans;
}

int main(){
    id['S'] = 0, id['R'] = 1, id['P'] = 2;
    scanf("%d%d%s", &n, &q, s);
    for (int i = 0; i < n; ++ i){
        int x = id[s[i]];
        add(seg[x], i, 1);
        set[x].insert(i);
    }
    printf("%d\n", solve());
    while (q --){
        int x;
        scanf("%d%s", &x, tmp);
        -- x;
        int y = id[s[x]];
        add(seg[y], x, -1);
        set[y].erase(x);
        s[x] = tmp[0];
        y = id[s[x]];
        add(seg[y], x, 1);
        set[y].insert(x);
        printf("%d\n", solve());
    }
    return 0;
}