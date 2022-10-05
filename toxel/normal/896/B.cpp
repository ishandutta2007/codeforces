#include<bits/stdc++.h>

const int N = 1010;

int sit[N], a[N];
int n, m, c;

void ask(int x, int pos){
    printf("%d\n", pos);
    a[pos] = x;
    fflush(stdout);
    bool flag = true;
    for (int i = 1; i <= n; ++ i){
        if (!a[i]){
            flag = false;
            break;
        }
    }
    for (int i = 1; i < n; ++ i){
        if (a[i] > a[i + 1]){
            flag = false;
            break;
        }
    }
    if (flag){
        exit(0);
    }
    if (x <= (c + 1) >> 1){
        for (int i = x; i <= (c + 1) >> 1; ++ i){
            sit[i] = std::max(sit[i], pos + 1);
        }
    }
    else{
        for (int i = x; i > (c + 1) >> 1; -- i){
            sit[i] = std::min(sit[i], pos - 1);
        }
    }
}

int main(){
   scanf("%d%d%d", &n, &m, &c);
   for (int i = 1; i <= (c + 1) >> 1; ++ i){
       sit[i] = 1;
   }
   for (int i = c; i > (c + 1) >> 1; -- i){
       sit[i] = n;
   }
   while (true){
       int x;
       scanf("%d", &x);
       ask(x, sit[x]);
   }
}