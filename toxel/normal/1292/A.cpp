#include <bits/stdc++.h>

const int N = 100010;

bool able[N];
int state[N][2];
int cnt;

void calc(int c, int value){
    if (able[c]){
        cnt += value;
    }
}

void update(int c){
    if (state[c][0] == 0 && state[c + 1][0] == 0){
        able[c] = true;
        return;
    }
    if (state[c][1] == 0 && state[c + 1][1] == 0){
        able[c] = true;
        return;
    }
    able[c] = false;
}

int main(){
    for (int i = 0; i < N; ++ i){
        able[i] = true;
    }
    int n, q;
    scanf("%d%d", &n, &q);
    cnt = n - 1;
    while (q --){
        int r, c;
        scanf("%d%d", &r, &c);
        -- r, -- c;
        if (c >= 1){
            calc(c - 1, -1);
        }
        if (c < n - 1){
            calc(c, -1);
        }
        state[c][r] ^= 1;
        if (c >= 1){
            update(c - 1);
            calc(c - 1, 1);
        }
        if (c < n - 1){
            update(c);
            calc(c, 1);
        }
        if (state[n - 1][1] == 0 && cnt == n - 1){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
}