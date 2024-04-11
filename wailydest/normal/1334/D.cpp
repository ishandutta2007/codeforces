#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve()
{
    int n;
    long long l, r;
    scanf("%d%lld%lld", &n, &l, &r);
    
    --l;
    --r;
    vector<long long> arr(n + 2);
    arr[1] = 0;
    for (int i = 2; i <= n; ++i) arr[i] = arr[i - 1] + 2 * (n - i + 1);
    arr[n + 1] = LLONG_MAX;
    
    int num = 1;
    while (arr[num + 1] <= l) ++num;
    
    int i = 0;
    while (arr[num] + 2 * i < l) ++i;
    if (arr[num] + 2 * i - 1 == l) printf("%d ", num + i);
    if (arr[num] == r && r != (long long)n * (n - 1)) printf("%d ", num);
    bool toprint1 = r == (long long)n * (n - 1);
    r = min(r, (long long)n * (n - 1) - 1);
    while (arr[num] < r) {
        while (arr[num] + 2 * i + 1 <= r && arr[num] + 2 * i < arr[num + 1]) {
            printf("%d %d ", num, num + i + 1);
            ++i;
        }
        if (arr[num] + 2 * i == r) {
            if (arr[num] + 2 * i < arr[num + 1]) printf("%d ", num);
            else printf("%d ", num + 1);
        }
        ++num;
        i = 0;
    }
    if (toprint1) printf("1");
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}