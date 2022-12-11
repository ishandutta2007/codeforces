#include <bits/stdc++.h>

const int N = 110;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    std::priority_queue <int> queue;
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        queue.push(x);
    }
    int mid = n >> 1;
    a[mid] = queue.top();
    queue.pop();
    for (int i = 1; i < n; ++ i){
        if (mid - i >= 0){
            a[mid - i] = queue.top();
            queue.pop();
        }
        if (mid + i < n){
            a[mid + i] = queue.top();
            queue.pop();
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}