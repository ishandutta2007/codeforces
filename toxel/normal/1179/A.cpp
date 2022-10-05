#include <bits/stdc++.h>

typedef long long ll;
const int N = 300010;
const int M = 150010;

int ans1[N], ans2[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    std::deque <int> deque;
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        deque.push_back(x);
    }
    for (int i = 1; i < N; ++ i){
        int x = deque.front();
        deque.pop_front();
        int y = deque.front();
        deque.pop_front();
        deque.push_front(std::max(x, y));
        deque.push_back(std::min(x, y));
        ans1[i] = x;
        ans2[i] = y;
    }
    while (q --){
        ll m;
        scanf("%lld", &m);
        if (m >= M) {
            m = (m - M) % (n - 1) + M;
        }
        printf("%d %d\n", ans1[m], ans2[m]);
    }
    return 0;
}