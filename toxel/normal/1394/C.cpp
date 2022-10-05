#include <bits/stdc++.h>

const int N = 500010;
using pii = std::pair<int, int>;

char s[N];
int b[N], w[N];

pii check(int mid, int n){
    int l1 = 0, l2 = 0, l3 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX, r3 = INT_MAX;
    for (int i = 0; i < n; ++ i){
        l1 = std::max(l1, b[i] - mid);
        l2 = std::max(l2, w[i] - mid);
        l3 = std::max(l3, w[i] - b[i] - mid);
        r1 = std::min(r1, b[i] + mid);
        r2 = std::min(r2, w[i] + mid);
        r3 = std::min(r3, w[i] - b[i] + mid);
    }
    if (l1 > r1 || l2 > r2 || l3 > r3){
        return {0, 0};
    }
    for (int type1 = 0; type1 < 2; ++ type1){
        for (int type2 = 0; type2 < 2; ++ type2){
            int bb = type2 ? l3 : r3;
            int x = type1 ? l1 : r1;
            int y = x + bb;
            if (l2 <= y && y <= r2){
                if (x || y){
                    return {x, y};
                }
            }
        }
    }
    for (int type1 = 0; type1 < 2; ++ type1){
        for (int type2 = 0; type2 < 2; ++ type2){
            int bb = type2 ? l3 : r3;
            int y = type1 ? l2 : r2;
            int x = y - bb;
            if (l1 <= x && x <= r1){
                if (x || y){
                    return {x, y};
                }
            }
        }
    }
    return {0, 0};
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; ++ j){
            b[i] += s[j] == 'B';
            w[i] += s[j] == 'N';
        }
    }
    int left = 0, right = 1e6;
    while (left < right){
        int mid = (left + right) / 2;
        pii p = check(mid, n);
        if (p.first || p.second){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    pii p = check(left, n);
    printf("%d\n", left);
    int numx = p.first;
    int numy = p.second;
    for (int i = 0; i < numx; ++ i){
        putchar('B');
    }
    for (int i = 0; i < numy; ++ i){
        putchar('N');
    }
    puts("");
    return 0;
}