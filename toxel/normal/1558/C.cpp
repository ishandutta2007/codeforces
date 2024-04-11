#include <bits/stdc++.h>

const int N = 3010;

std::vector <int> output;
int a[N];

void op(int pos){
    std::reverse(a + 1, a + pos + 1);
    output.emplace_back(pos);
}

std::mt19937 rnd(19971109);

void solve(){
    int n;
    scanf("%d", &n);
    // n = 101;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        // a[i] = i;
    }
    /*for (int i = 3; i <= n; ++ i){
        int x = i - rnd() % (i / 2) * 2;
        std::swap(a[i], a[x]);
    }*/
    for (int i = 1; i <= n; ++ i){
        if (a[i] % 2 != i % 2){
            puts("-1");
            return;
        }
    }
    output.clear();
    for (int i = n; i >= 5; i -= 2){
        int p1, p2;
        auto find = [&](){
            for (int j = 1; j <= n; ++ j){
                if (a[j] == i - 1){
                    p1 = j;
                }
                if (a[j] == i){
                    p2 = j;
                }
            }
        };
        find();
        if (p1 < p2){
            op(p2);
            find();
            if (p1 >= 4){
                op(p1 - 1);
                op(p1 + 1);
                op(3);
            }
            op(i);
        }
        else{
            op(p2);
            op(p1 - 1);
            op(p1 + 1);
            op(3);
            op(i);
        }
    }
    if (a[1] == 3){
        op(3);
    }
    for (int i = 1; i <= n; ++ i){
        assert(a[i] == i);
    }
    int sz = output.size();
    assert(2 * sz <= 5 * n);
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", output[i], " \n"[i == sz - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}