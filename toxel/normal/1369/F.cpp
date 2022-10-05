#include <bits/stdc++.h>

using ll = long long;
const int N = 100010;

int sg[N];

bool win(ll s, ll e){
    ll left = e / 2 + 1, right = e;
    int type = right % 2;
    while (true){
        if (s >= left){
            if (type == 0){
                return s % 2 == 1;
            }
            if (type == 1){
                return s % 2 == 0;
            }
            if (type == 2){
                return true;
            }
        }
        ll nleft = (left + 1) / 2, nright = left - 1;
        left = nleft, right = nright;
        if (type == 0){
            type = 2;
        }
        else if (type == 1){
            type = 1;
        }
        else if (type == 2){
            type = right % 2;
        }
    }
}

bool lose(ll s, ll e){
    ll left = e / 2 + 1, right = e;
    int type = 2;
    while (true){
        if (s >= left){
            if (type == 0){
                return s % 2 == 1;
            }
            if (type == 1){
                return s % 2 == 0;
            }
            if (type == 2){
                return true;
            }
        }
        ll nleft = (left + 1) / 2, nright = left - 1;
        left = nleft, right = nright;
        if (type == 0){
            type = 2;
        }
        else if (type == 1){
            type = 1;
        }
        else if (type == 2){
            type = right % 2;
        }
    }
}

void gen(int x){
    for (int i = x - 1; i >= 1; -- i){
        if (i * 2 <= x && !sg[i * 2]){
            sg[i] = true;
        }
        if (i + 1 <= x && !sg[i + 1]){
            sg[i] = true;
        }
        if (sg[i] != int(win(i, x))){
            printf("%d\n", i);
        }
    }
}

ll s[N], e[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld", &s[i], &e[i]);
    }
    int cur = 1;
    for (int i = n - 1; i >= 0; -- i){
        if (cur){
            cur = win(s[i], e[i]) ^ 1;
        }
        else{
            cur = lose(s[i], e[i]) ^ 1;
        }
    }
    int ans1 = cur == 0;
    cur = 0;
    for (int i = n - 1; i >= 0; -- i){
        if (cur){
            cur = win(s[i], e[i]) ^ 1;
        }
        else{
            cur = lose(s[i], e[i]) ^ 1;
        }
    }
    int ans2 = cur == 0;
    printf("%d %d\n", ans1, ans2);
}