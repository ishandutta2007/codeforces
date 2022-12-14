#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MN = 1e5 + 1;

int N, K;
int A[MN];

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d", &N, &K);

        bool has_k = false;
        for(int i = 0 ; i < N; i++) {
            scanf("%d", &A[i]);
            if (A[i] < K) {
                A[i] = -1;
            }
            else if (A[i] > K) {
                A[i] = 1;
            }
            else {
                A[i] = 0;
                has_k = true;
            }
        }

        if (N == 1) {
            puts(has_k ? "yes" : "no");
            continue;
        }

        bool interval = false;
        for(int i = 0; i < N; i++) {
            if(i+1 < N && A[i] >= 0 && A[i+1] >= 0)
                interval = true;
            if(i+2 < N && A[i] >= 0 && A[i+2] >= 0)
                interval = true;
        }
        puts((has_k && interval) ? "yes" : "no");
    }
    return 0;
}