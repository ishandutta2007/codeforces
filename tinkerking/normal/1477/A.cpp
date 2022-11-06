#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL K, a[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%lld",&N,&K);
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
        }
        sort(a + 1, a + N + 1);
        LL g = 0;
        for (int i=1;i<N;i++) {
            g = __gcd(a[i + 1] - a[i], g);
        }
        //printf("g = %lld\n",g);
        puts(abs(a[1] - K) % g == 0 ? "YES" : "NO");
    }
}