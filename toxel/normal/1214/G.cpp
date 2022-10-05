#include <bits/stdc++.h>

const int N = 2010;

struct Ans{
    int x1, y1, x2, y2;

    Ans():x1(-1), y1(-1), x2(-1), y2(-1){}
    Ans(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2){}
};

struct Bitset{
    std::bitset <N> set;
    int count;
    Ans ans;

    Bitset() noexcept :set(), count(0){}
    explicit Bitset(std::bitset <N> set) noexcept :set(set), count(set.count()){}
};

struct Bitset_Pt{
    Bitset *pt;

    explicit Bitset_Pt(Bitset *pt = nullptr) noexcept :pt(pt){}
    Bitset &operator *()const{return *pt;}
    Bitset *operator ->()const{return pt;}

    bool operator <(const Bitset_Pt &b)const{
        if (pt -> count != b.pt -> count){
            return pt -> count < b.pt -> count;
        }
        return pt < b.pt;
    }
};

Bitset set[N];
Bitset_Pt pt[N];

Ans process(Bitset &set1, Bitset &set2){
    std::bitset <N> set3 = ~set1.set & set2.set, set4 = ~set2.set & set1.set;
    int y1 = set3._Find_first(), y2 = set4._Find_first();
    if (y1 == N || y2 == N){
        return {};
    }
    int x1 = static_cast <Bitset *>(&set1) - set, x2 = static_cast <Bitset *>(&set2) - set;
    if (x1 > x2){
        std::swap(x1, x2);
    }
    if (y1 > y2){
        std::swap(y1, y2);
    }
    return {x1, y1, x2, y2};
}

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    std::set <Bitset_Pt> pt_set;
    for (int i = 0; i < n; ++ i){
        pt[i] = Bitset_Pt(set + i);
        pt_set.insert(pt[i]);
    }
    std::set <int> has_ans;
    while (q --){
        int a, l, r;
        scanf("%d%d%d", &a, &l, &r);
        -- a, -- l, -- r;
        auto u = pt_set.find(pt[a]);
        (*u) -> ans = Ans();
        has_ans.erase((*u).pt - set);
        if (u != pt_set.begin()){
            auto v = u;
            -- v;
            (*v) -> ans = Ans();
            has_ans.erase((*v).pt - set);
            auto w = u;
            ++ w;
            if (w != pt_set.end()){
                Ans ans = process(**v, **w);
                if (ans.x1 != -1){
                    has_ans.insert((*v).pt - set);
                }
                (*v) -> ans = ans;
            }
        }
        pt_set.erase(u);
        set[a].set = set[a].set ^ (~std::bitset<N>() << (N - (r - l + 1)) >> (N - 1 - r));
        set[a].count = set[a].set.count();
        u = pt_set.insert(pt[a]).first;
        auto w = u;
        ++ w;
        if (w != pt_set.end()){
            Ans ans = process(**u, **w);
            if (ans.x1 != -1){
                has_ans.insert((*u).pt - set);
            }
            (*u) -> ans = ans;
        }
        if (u != pt_set.begin()){
            auto v = u;
            -- v;
            has_ans.erase((*v).pt - set);
            Ans ans = process(**v, **u);
            if (ans.x1 != -1){
                has_ans.insert((*v).pt - set);
            }
            (*v) -> ans = ans;
        }
        if (has_ans.empty()){
            puts("-1");
            continue;
        }
        Ans ans = set[*has_ans.begin()].ans;
        printf("%d %d %d %d\n", ans.x1 + 1, ans.y1 + 1, ans.x2 + 1, ans.y2 + 1);
    }
    return 0;
}