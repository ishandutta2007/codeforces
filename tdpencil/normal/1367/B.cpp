#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;
#define runcase LOL
void solve(int test_case = 0)
{
    vector<int> a, b;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int X; cin >> X;
        if(X%2!=i%2) {
            if(X%2)
                a.push_back(X);
            else
                b.push_back(X);
        }
    }

    if(a.size() == b.size()) {
        cout << a.size() << "\n";
    } else {
        cout << -1 << "\n";
    }
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