#include <bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

int d[N];
pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &d[i]);
        p[i] = {d[i], i};
    }
    std::sort(p + 1, p + n + 1, std::greater <pii>());
    for (int i = 1; i < n; ++ i){
        printf("%d %d\n", p[i].second * 2, p[i + 1].second * 2);
    }
    std::deque <int> queue;
    for (int i = 1; i <= n; ++ i){
        queue.push_back(p[i].second * 2);
    }
    for (int i = 1; i <= n; ++ i){
        int pos = p[i].first - 1;
        printf("%d %d\n", 2 * p[i].second - 1, queue[pos]);
        if (pos == (int) queue.size() - 1){
            queue.push_back(p[i].second * 2 - 1);
        }
        queue.pop_front();
    }
    return 0;
}