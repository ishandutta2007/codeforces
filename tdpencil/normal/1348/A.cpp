#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;
#define runcase LOL
void solve(int test_case = 0)
{
    int N; cin >> N;
    vector<int> A, B;
    for(int i = 1; i <= N / 2 - 1; i++) {
        A.push_back(1 << i);
    }
    for(int i = N / 2; i < N; i++) {
        B.push_back(1 << i);
    }
    A.push_back(1 << N);
    int x = 0;
    for(int i : A) x += i;
    int y = 0;
    for(int i : B) y += i;
    cout << abs(x - y) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}