#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[MAXN];
int n;

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i];
    int u = max(a[n], 2 * sum / n);
    while (n * u - sum <= sum)
        u++;
    printf("%d\n", u);
}

int main(){
    int T = 1;
    //scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}