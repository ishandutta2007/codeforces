#include<bits/stdc++.h>

const int N = 100;

bool lie[N];

int ask(int n){
    printf("%d\n", n);
    fflush(stdout);
    int t;
    scanf("%d", &t);
    if (t == 0 || t == -2){
        exit(0);
    }
    return t;
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++ i){
        int x = ask(1);
        lie[i] = x == -1;
    }
    int now = 0, left = 1, right = m;
    while (left <= right){
        int mid = (left + right) >> 1;
        int x = ask(mid);
        if (lie[now]){
            x = -x;
        }
        if (x == -1){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
        now = (now + 1) % n;
    }
    return 0;
}