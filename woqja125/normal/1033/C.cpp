#include <cstdio>
int p[100001];
int l[100001];
int d[100001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", p+i);
        l[p[i]] = i;
    }
    d[n] = 0; // start lose
    for(int i=n-1; i>=1; i--) {
        for(int j=l[i]+i; j <= n; j+=i) {
            if(p[j] <= i) continue;
            if(d[p[j]] == 0) d[i] = 1;
        }
        for(int j=l[i]-i; j >= 0; j-=i) {
            if(p[j] <= i) continue;
            if(d[p[j]] == 0) d[i] = 1;
        }
    }
    for(int i=1; i<=n; i++) printf(d[p[i]]?"A":"B");
    printf("\n");
    return 0;
}