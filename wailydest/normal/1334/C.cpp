#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

long long solve()
{
    int n;
    scanf("%d", &n);
    vector<pair<long long, long long> > par(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld", &par[i].first, &par[i].second);
    }
    vector<long long> arr(n);
    arr[0] = par[0].first - par[n - 1].second;
    for (int i = 1; i < n; ++i) {
        arr[i] = par[i].first - par[i - 1].second;
    }
    for (int i = 0; i < n; ++i) if (arr[i] < 0) arr[i] = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) sum += arr[i];
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) ans = min(ans, sum - arr[i] + par[i].first);
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        printf("%lld\n", solve());
    }
    return 0;
}