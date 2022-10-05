#include <bits/stdc++.h>

using ll = long long;
const int N = 1000010;
using pii = std::pair <ll, ll>;

struct State{
    ll l, r;
    int type;

    State (ll l = 0, ll r = 0, int type = 0):l(l), r(r), type(type){}
};

using rb_type = std::tuple <int, int, State>;

std::vector <rb_type> rollback[N][2];
std::vector <rb_type> *rb;

struct stack_wrapper{
    std::deque<State> deque;
    ll offset;
    bool reverse;

    stack_wrapper():deque(std::deque<State>()), offset(0), reverse(false){}

    size_t size()const{
        return deque.size();
    }

    bool empty()const{
        return deque.empty();
    }

    void emplace_back(ll l, ll r, int type){
        if (reverse){
            deque.emplace_front(offset - r, offset - l, type);
            rb -> push_back({0, 0, {0, 0, 0}});
        }
        else{
            deque.emplace_back(l - offset, r - offset, type);
            rb -> push_back({1, 0, {0, 0, 0}});
        }
    }

    pii back()const{
        if (reverse){
            return {offset - deque.front().r, offset - deque.front().l};
        }
        else{
            return {offset + deque.back().l, offset + deque.back().r};
        }
    }

    State operator [](const int &n)const{
        if (reverse){
            int sz = deque.size();
            return {offset - deque[sz - 1 - n].r, offset - deque[sz - 1 - n].l, deque[sz - 1 - n].type};
        }
        else{
            return {offset + deque[n].l, offset + deque[n].r, deque[n].type};
        }
    }

    State get(const int &n)const{
        if (reverse){
            return {offset - deque[n].r, offset - deque[n].l, deque[n].type};
        }
        else{
            return {offset + deque[n].l, offset + deque[n].r, deque[n].type};
        }
    }

    void pop_back(){
        if (reverse){
            rb -> push_back({0, 1, deque.front()});
            deque.pop_front();
        }
        else{
            rb -> push_back({1, 1, deque.back()});
            deque.pop_back();
        }
    }

    void revert(ll x){
        rb -> push_back({2, 0, {offset, reverse, 0}});
        offset = x - offset;
        reverse = !reverse;
    }
};

ll w[N];
ll ans[N];
bool reverse[N];

int main(){
    int n;
    ll c;
    scanf("%d%lld", &n, &c);
    for (int i = 1; i <= n - 2; ++ i){
        scanf("%lld", &w[i]);
    }
    stack_wrapper stack;
    rb = rollback[0] + 0;
    stack.emplace_back(0, c, -1);
    for (int i = 1; i <= n - 2; ++ i){
        rb = rollback[i] + 0;
        while (!stack.empty()){
            pii p = stack.back();
            if (p.first > w[i]){
                stack.pop_back();
                continue;
            }
            if (p.second > w[i]){
                stack.pop_back();
                stack.emplace_back(p.first, w[i], 0);
            }
            break;
        }
        if (stack.empty()){
            puts("NO");
            return 0;
        }
        rb = rollback[i] + 1;

        pii p = stack.back();
        stack.pop_back();
        stack.emplace_back(p.first, p.second, 0);
        p = stack.back();
        if (p.second == w[i]){
            while (!stack.empty()){
                stack.pop_back();
            }
            stack.emplace_back(0, w[i], 1);
            continue;
        }
        stack.revert(w[i]);
        if (stack.back().second < w[i]){
            stack.emplace_back(w[i], w[i], 2);
        }
    }
    int pos = 0;
    ans[n - 1] = stack.get(pos).l;
    for (int i = n - 2; i >= 1; -- i){
        auto operate = [&](std::vector <rb_type> &x){
            while (!x.empty()){
                auto [fl1, fl2, state] = x.back();
                x.pop_back();
                if (fl1 == 2){
                    stack.offset = state.l;
                    stack.reverse = state.r;
                }
                else if (fl1 == 0){
                    if (fl2 == 0){
                        stack.deque.pop_front();
                        -- pos;
                    }
                    else{
                        stack.deque.push_front(state);
                        ++ pos;
                    }
                }
                else{
                    if (fl2 == 0){
                        stack.deque.pop_back();
                    }
                    else{
                        stack.deque.emplace_back(state);
                    }
                }
            }
        };
        State s = stack.get(pos);
        operate(rollback[i][1]);
        if (s.type == 0){
            ans[i] = w[i] - ans[i + 1];
        }
        else if (s.type == 1){
            pos = stack.reverse ? 0 : int(stack.size()) - 1;
            ans[i] = w[i];
            reverse[i] = true;
        }
        else if (s.type == 2){
            ans[i] = stack.get(0).l;
            pos = 0;
            reverse[i] = true;
        }
        operate(rollback[i][0]);
    }
    int rev = 0;
    for (int i = n - 2; i >= 1; -- i){
        rev ^= int(reverse[i]);
        if (rev){
            ans[i] = -ans[i];
        }
    }
    for (int i = 1; i <= n - 1; ++ i){
        ans[i] += ans[i - 1];
    }
    ll min = *std::min_element(ans, ans + n);
    puts("YES");
    for (int i = 0; i < n; ++ i){
        ans[i] -= min;
        printf("%lld%c", ans[i], " \n"[i == n - 1]);
    }
    for (int i = 1; i < n - 2; ++ i){
        ll x[3] = {ans[i - 1], ans[i], ans[i + 1]};
        std::sort(x, x + 3);
        assert(x[2] - x[0] == w[i]);
    }
    return 0;
}