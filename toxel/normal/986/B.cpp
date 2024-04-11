#include<bits/stdc++.h>

const int N = 1000010;

int c[N];

void add(int sit, int value){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] ^= value;
    }
}

int query(int sit){
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret ^= c[sit];
    }
    return ret;
}

int p[N], inv[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
        inv[p[i]] = i;
    }
    int ans = n & 1;
    for (int i = n; i >= 1; -- i){
        ans ^= query(inv[i]);
        add(inv[i], 1);
    }
    puts(ans ? "Um_nik" : "Petr");
    return 0;
}