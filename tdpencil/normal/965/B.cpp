#include <bits/stdc++.h>
using namespace std;


string GRID[100];
int multiple[100][100];
void run_case() {
    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> GRID[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // go down, go right
            bool works = 1;
            for(int k = 0; k < K; k++) {
                works &= j + k < N && GRID[i][j + k] != '#';
            }
            if(works) {
                for(int k = 0; k < K; k++)
                    multiple[i][j + k]++;
            }
            works = 1;
            for(int k = 0; k < K; k++) {
                works &= i + k < N && GRID[i + k][j] != '#';
            }
            if(works) {
                for(int k = 0; k < K; k++) {
                    multiple[i + k][j]++;
                }
            }
        }
    }

    array<int, 2> pos = {0, 0};
    int mx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(multiple[i][j] > mx) {
                mx = multiple[i][j];
                pos = {i, j};
            }
        }
    }

    cout << pos[0] + 1 << " " << pos[1] + 1 << "\n";
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