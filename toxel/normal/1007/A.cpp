#include<bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::priority_queue <int> queue;
    std::sort(a, a + n, std::greater <int>());
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (!queue.empty()){
            int x = queue.top();
            if (x > a[i]){
                queue.pop();
                ++ cnt;
            }
        }
        queue.push(a[i]);
    }
    printf("%d\n", cnt);
    return 0;
}