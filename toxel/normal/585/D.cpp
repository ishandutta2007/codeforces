#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef std::pair <int, std::string> pis;
const int N = 30;

std::map <pii, pis> Hash1, Hash2;

int a[N], b[N], c[N];

void process(std::map <pii, pis> &Hash, int begin, int end){
    Hash[{0, 0}] = {0, ""};
    for (int i = begin; i <= end; ++ i){
        std::map <pii, pis> tmp;
        for (auto &u : Hash){
            pii p1 = u.first;
            pis p2 = u.second;
            pii p3 = {p1.first + b[i] - a[i], p1.second - a[i]};
            pis p4 = {p2.first + a[i], p2.second + "W"};
            pis now;
            if (tmp.count(p3)){
                tmp[p3] = std::max(tmp[p3], p4);
            }
            else{
                tmp[p3] = p4;
            }
            p3 = {p1.first - a[i], p1.second + c[i] - a[i]};
            p4 = {p2.first + a[i], p2.second + "M"};
            if (tmp.count(p3)){
                tmp[p3] = std::max(tmp[p3], p4);
            }
            else{
                tmp[p3] = p4;
            }
            p3 = {p1.first + b[i], p1.second + c[i]};
            p4 = {p2.first, p2.second + "L"};
            if (tmp.count(p3)){
                tmp[p3] = std::max(tmp[p3], p4);
            }
            else{
                tmp[p3] = p4;
            }
        }
        Hash = tmp;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    process(Hash1, 0, n - 1 >> 1);
    process(Hash2, (n - 1 >> 1) + 1, n - 1);
    pis ans = {INT_MIN, ""};
    for (auto u : Hash1){
        pii p = {-u.first.first, -u.first.second};
        if (Hash2.count(p)){
            pis p1 = u.second;
            pis p2 = Hash2[p];
            ans = std::max(ans, {p1.first + p2.first, p1.second + p2.second});
        }
    }
    if (ans.second.empty()){
        puts("Impossible");
        return 0;
    }
    for (int i = 0, sz = ans.second.size(); i < sz; ++ i){
        switch (ans.second[i]){
            case 'L': puts("MW"); break;
            case 'W': puts("LM"); break;
            case 'M': puts("LW"); break;
        }
    }
    return 0;
}