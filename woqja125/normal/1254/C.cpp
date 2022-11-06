#include <cstdio>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<long long, int>> A;

int s(int x, int y, int z) {
    int r;
    printf("2 %d %d %d\n", x, y, z);
    fflush(stdout);
    scanf("%d", &r);
    return r;
}

long long Q(int x, int y, int z) {
    long long r = 0;
    printf("1 %d %d %d\n", x, y, z);
    fflush(stdout);
    scanf("%lld", &r);
    return r * s(x, y, z);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=3; i<=n; i++) {
        A.emplace_back(Q(1, 2, i), i);
    }
    sort(A.begin(), A.end());
    deque<int> a, b;
    int u = A[0].second, i;

    a.push_back(u);
    for(i=1; i<A.size() && A[i].first < 0; i++) {
        if(s(1, u, A[i].second) > 0) {
            a.push_back(A[i].second);
        }
        else a.push_front(A[i].second);
    }

    u = A.back().second;
    b.push_back(u);
    for(i=A.size()-2; i >= 0 && A[i].first > 0; i--) {
        if(s(1, u, A[i].second) > 0) {
            b.push_back(A[i].second);
        }
        else b.push_front(A[i].second);
    }


    printf("0 1 ");
    if(A[0].first < 0) for(auto x: a) printf("%d ", x);
    printf("2 ");
    if(A.back().first > 0) for(auto x: b) printf("%d ", x);
    printf("\n");
    return 0;
}