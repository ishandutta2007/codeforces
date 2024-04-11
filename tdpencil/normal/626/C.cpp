#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> thirds, seconds;
void run_case() {
    cin >> N >> M;
    for(int i = 0; i < int(60000000); i++) {
        int res = i / 3;
        int ans = i / 2;
        int over = i / 6;
        if(ans >= N && res >= M && N + M <= res + ans - over) {
            cout << i;
            return;
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;

#ifdef RUN_CASE
    cin >> T;
#endif

    for(int test_case = 0; test_case < T; test_case++)
        run_case();
}