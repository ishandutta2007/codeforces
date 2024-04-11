#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

void solve(int casi){
    ll p1, q1, p2, q2, ans;
    scanf("%lld%lld%lld%lld", &p1, &q1, &p2, &q2);
    if (p1 == p2) {
        ans = std::abs(q2 - q1);
    } else if (q1 == q2) {
        ans = std::abs(p2 - p1);
    } else {
        ans = std::abs(q2 - q1) + std::abs(p2 - p1) + 2;
    }
    printf("%lld\n", ans);
}

int main(){
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}