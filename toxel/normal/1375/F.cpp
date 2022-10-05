#include <bits/stdc++.h>

using ll = long long;

struct State{
    static const int N = 3;
    ll a[N], pos[N];
    int prev;

    State(int _a, int b, int c){
        a[0] = _a, a[1] = b, a[2] = c;
        for (int i = 0; i < N; ++ i){
            pos[i] = i;
        }
        prev = -1;
        sort();
    }

    void sort(){
        for (int i = 0; i < N; ++ i){
            for (int j = 0; j < N - 1; ++ j){
                if (a[j] > a[j + 1]){
                    std::swap(a[j], a[j + 1]);
                    std::swap(pos[j], pos[j + 1]);
                }
            }
        }
    }

    State update(int p, ll value){
        State ret = *this;
        for (int i = 0; i < N; ++ i){
            if (ret.pos[i] == p){
                ret.a[i] += value;
                break;
            }
        }
        ret.prev = p;
        ret.sort();
        return ret;
    }

    bool illegal(){
        for (int i = 0; i < N - 1; ++ i){
            if (a[i] == a[i + 1]){
                return true;
            }
        }
        return a[0] + a[2] == 2 * a[1] && prev == pos[2];
    }
};

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    puts("First");
    fflush(stdout);
    State s(a, b, c);
    ll value = 1e10;
    printf("%lld\n", value);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x <= 0){
        return 0;
    }
    s = s.update(x - 1, value);
    value = 2 * s.a[2] - s.a[0] - s.a[1];
    printf("%lld\n", value);
    fflush(stdout);
    scanf("%d", &x);
    if (x <= 0){
        return 0;
    }
    s = s.update(x - 1, value);
    value = s.a[2] - s.a[1];
    printf("%lld\n", value);
    fflush(stdout);
    scanf("%d", &x);
    if (x <= 0){
        return 0;
    }
    return 0;
}