#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
const int N = 1010;

int n;
int a[N], b[N], c[N], d[N];
pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        p[i] = {- a[i] - b[i] - c[i] - d[i], i};
    }
    std::sort(p, p + n);
    for (int i = 0; i < n; ++ i){
        if (p[i].second == 0){
            printf("%d\n", i + 1);
        }
    }
    return 0;
}