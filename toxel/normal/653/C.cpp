#include<bits/stdc++.h>

const int N = 150010;
typedef std::pair <int, int> pii;

int t[N];
bool valid[N];
int cnt = 0, n;
std::set <pii> set;

bool check(int i){
    if (i & 1){
        return t[i] < t[i + 1];
    }
    return t[i] > t[i + 1];
}

void update(int sit, int value, int &cnt){
    int tmp = t[sit];
    if (sit > 1){
        cnt -= !check(sit - 1);
        t[sit] = value;
        cnt += !check(sit - 1);
    }
    t[sit] = tmp;
    if (sit < n){
        cnt -= !check(sit);
        t[sit] = value;
        cnt += !check(sit);
    }
    t[sit] = value;
}

bool check(pii p){
    if (p.first == p.second){
        return false;
    }
    int tmpcnt = cnt;
    int value1 = t[p.first], value2 = t[p.second];
    update(p.first, value2, tmpcnt);
    update(p.second, value1, tmpcnt);
    std::swap(t[p.first], t[p.second]);
    return !tmpcnt;
}

void dfs(int sit, std::set <int> tmp){
    if (sit == n){
        if (tmp.size() > 2){
            return;
        }
        if (tmp.size() == 2){
            pii p = {*(tmp.begin()), *(-- tmp.end())};
            if (check(p)){
                set.insert(p);
            }
            return;
        }
        for (int i = 1; i <= n; ++ i){
            pii p = {i, *(tmp.begin())};
            if (p.first > p.second){
                std::swap(p.first, p.second);
            }
            if (check(p)){
                set.insert(p);
            }
        }
        return;
    }
    if (!valid[sit]){
        std::set <int> ttmp = tmp;
        ttmp.insert(sit);
        dfs(sit + 1, ttmp);
        ttmp = tmp;
        ttmp.insert(sit + 1);
        dfs(sit + 1, ttmp);
    }
    else{
        dfs(sit + 1, tmp);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &t[i]);
    }
    for (int i = 1; i < n; ++ i){
        valid[i] = check(i);
        cnt += !valid[i];
    }
    if (cnt > 4){
        puts("0");
        return 0;
    }
    dfs(1, std::set <int>());
    printf("%d\n", (int) set.size());
    return 0;
}