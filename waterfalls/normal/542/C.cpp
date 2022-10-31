#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int f[213];
int visited[213];
int cycle[213];
int chain[213];

long long gcd(long long a, long long b) {
    if (a==0) return b;
    return gcd(b%a,a);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&f[i]);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) visited[j] = 0;
        int cur = i;
        visited[cur] = 1;
        int num = 1;
        while (true) {
            cur = f[cur];
            num+=1;
            if (visited[cur]) {
                chain[i] = visited[cur]-1;
                cycle[i] = num-visited[cur];
                break;
            }
            visited[cur] = num;
        }
    }
    long long ans = 1;
    for (int i=1;i<=n;i++) ans = ans*cycle[i]/gcd(ans,cycle[i]);
    int add = 0;
    for (int i=1;i<=n;i++) add = max(add,chain[i]);
    long long c = ans;
    while (add>ans) ans+=c;
    printf("%I64d\n",ans);

    return 0;
}