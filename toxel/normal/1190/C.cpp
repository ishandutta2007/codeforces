#include <bits/stdc++.h>

const int N = 100010;

char s[N];
std::vector <int> vec0, vec1;

void print(bool flag){
    puts(flag ? "tokitsukaze" : "quailty");
    exit(0);
}

int findLeft(std::vector <int> &vec, int l, int r){
    if (l > r){
        return -1;
    }
    auto u = std::lower_bound(vec.begin(), vec.end(), l);
    if (u != vec.end() && *u <= r){
        return *u;
    }
    return -1;
}

int findRight(std::vector <int> &vec, int l, int r){
    if (l > r){
        return -1;
    }
    auto u = std::upper_bound(vec.begin(), vec.end(), r);
    if (u == vec.begin()){
        return -1;
    }
    -- u;
    if (*u >= l){
        return *u;
    }
    return -1;
}

int find(std::vector <int> &vec, int l, int r){
    if (findLeft(vec, l, r) == -1){
        return -1;
    }
    return findRight(vec, l, r) - findLeft(vec, l, r) + 1;
}

int main(){
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    bool flag = true;
    for (int i = 0; i < n; ++ i){
        if (s[i] != s[0]){
            flag = false;
            break;
        }
    }
    for (int i = 0; i < n; ++ i){
        (s[i] == '0' ? vec0 : vec1).push_back(i);
    }
    if (flag){
        print(true);
    }
    int left0 = 0, right0 = 0, left1 = 0, right1 = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0'){
            left0 = i;
            break;
        }
    }
    for (int i = 0; i < n; ++ i){
        if (s[i] == '1'){
            left1 = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '0'){
            right0 = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '1'){
            right1 = i;
            break;
        }
    }
    if (right0 - left0 + 1 <= k || right1 - left1 + 1 <= k){
        print(true);
    }
    flag = false;
    for (int i = 0; i <= n - k; ++ i){
        int l1 = 0, r1 = i - 1, l2 = i + k, r2 = n - 1;
        if (findLeft(vec0, l1, r1) != -1 && findLeft(vec0, l2, r2) != -1){
            flag = true;
            break;
        }
        if (findLeft(vec1, l1, r1) != -1 && findLeft(vec1, l2, r2) != -1){
            flag = true;
            break;
        }
        if (find(vec0, l1, r1) > k || find(vec0, l2, r2) > k || find(vec1, l1, r1) > k || find(vec1, l2, r2) > k){
            flag = true;
            break;
        }
    }
    if (flag){
        puts("once again");
    }
    else{
        print(false);
    }
    return 0;
}