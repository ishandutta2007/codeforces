#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, k, S[N], T[N];

void rmain() {
    scanf("%d%d", &k, &n);
    for(int i = 1; i <= n; ++ i) S[i] = 0;
    for(int i = 1; i <= k; ++ i) {
        scanf("%d", &m);
        ++ S[m];
    }
    for(int i = 1; i <= n; ++ i) T[i] = T[i - 1] + S[i];

    if(!S[1]) {
        puts("No");
        return;
    }

    for(int i = 2; i <= n; ++ i) if(!S[i]) {
        for(int j = 1; j <= n / i; ++ j) if(S[j]){
            if((T[min((j) * (i + 1) - 1, n)] - T[j * i - 1]) == 0) continue;
            else {
                //cerr << j <<' ' << i << endl;
                puts("No");
                return;
            }
        }
    }
    puts("Yes");
}

int main() {
    int t;
    for(cin >> t; t --;) {
        rmain();
    }
}