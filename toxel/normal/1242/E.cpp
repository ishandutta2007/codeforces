#include <bits/stdc++.h>

const int N = 100010;

struct Polygon{
    int sz, id;
    std::vector <int> a;

    explicit Polygon(int sz = 0, int id = 0):sz(sz), id(id), a(){}

    bool operator <(const Polygon &p)const {
        return sz > p.sz;
    }
};

int a[N];
Polygon p[N];
std::vector <int> ans[N];

int main(){
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; ++ i){
        scanf("%d", &a[i]);
        p[i] = Polygon(a[i], i);
    }
    int n;
    if (f == 1){
        n = a[0];
        for (int i = 1; i <= n; ++ i){
            p[0].a.push_back(i);
        }
    }
    else if (f == 2){
        if (p[0].sz == p[1].sz){
            n = a[0] + 1;
            p[0].a.push_back(1);
            p[0].a.push_back(2);
            p[0].a.push_back(3);
            for (int i = 5; i <= n; ++ i){
                p[0].a.push_back(i);
            }
            p[1].a.push_back(1);
            p[1].a.push_back(4);
            p[1].a.push_back(3);
            for (int i = 5; i <= n; ++ i){
                p[1].a.push_back(i);
            }
        }
        else{
            std::sort(p, p + f);
            n = p[0].sz;
            for (int i = 1; i <= n; ++ i){
                p[0].a.push_back(i);
            }
            for (int i = 1; i <= p[1].sz; ++ i){
                p[1].a.push_back(i);
            }
        }
    }
    else{
        std::sort(p, p + f);
        int sum = 0;
        for (int i = 0; i < f; ++ i){
            sum += a[i];
        }
        int other = sum - p[0].sz;
        if (p[0].sz - (other - 2 * (f - 1)) > 4){
            n = p[0].sz;
            for (int i = 1; i <= n; ++ i){
                p[0].a.push_back(i);
            }
            int tmp = n;
            for (int i = 1; i < f; ++ i){
                for (int j = tmp; j >= tmp - p[i].sz + 2; -- j){
                    p[i].a.push_back(j);
                }
                p[i].a.push_back(1);
                tmp -= p[i].sz - 2;
            }
        }
        else{
            for (int i = 1; i <= p[0].sz; ++ i){
                p[0].a.push_back(i);
            }
            std::vector <int> stack;
            if (sum % 2 == 1){
                if (p[0].sz == 3){
                    stack = {4, 2, 3, 1};
                    n = 4;
                }
                else{
                    for (int i = 2; i <= p[0].sz; ++ i){
                        stack.push_back(i);
                    }
                    n = p[0].sz;
                }
            }
            else{
                if (p[0].sz == 3){
                    stack = {5, 4, 2, 3, 1};
                    n = 5;
                }
                else if (p[0].sz == 4){
                    stack = {2, 5, 4, 3};
                    n = 5;
                }
                else{
                    for (int i = 2; i < p[0].sz; ++ i){
                        stack.push_back(i);
                    }
                    n = p[0].sz;
                }
            }
            int delta = int(stack.size()) - 2 - (other - 2 * (f - 1));
            bool rotated = false;
            std::vector <int> x_vec(f);
            for (int i = 1; i < f - 1; ++ i){
                int x = std::min(-delta, 2 * (p[i].sz - 2));
                delta += x;
                if (!rotated && x == 0){
                    rotated = true;
                    std::rotate(stack.begin(), stack.end() - 1, stack.end());
                }
                x = x / 2 + 1;
                int back = stack.back(), front = -1;
                int del_num = p[i].sz - x + 1;
                for (int j = 0; j < del_num; ++ j){
                    front = stack.back();
                    stack.pop_back();
                    p[i].a.push_back(front);
                }
                stack.push_back(front);
                int append_num = x - 1;
                for (int j = 0; j < append_num; ++ j){
                    ++ n;
                    stack.push_back(n);
                    p[i].a.push_back(n);
                }
                stack.push_back(back);
            }
            for (auto u : stack){
                p[f - 1].a.push_back(u);
            }
        }
    }
    printf("%d\n", n);
    for (int i = 0; i < f; ++ i){
        ans[p[i].id] = p[i].a;
    }
    for (int i = 0; i < f; ++ i){
        for (int j = 0; j < a[i]; ++ j){
            printf("%d%c", ans[i][j], " \n"[j == a[i] - 1]);
        }
    }
    return 0;
}