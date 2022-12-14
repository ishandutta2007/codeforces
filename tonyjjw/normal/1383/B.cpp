#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 1e5 + 1;
const int MK = 30;

int N;
int A[MN];

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d", &N);
        int xor_sum = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            xor_sum ^= A[i];
        }
        if (xor_sum == 0) {
            puts("DRAW");
            continue;
        }

        int k = -1;
        for(int i = MK; i >= 0; i--) {
            if(xor_sum & (1 << i)) {
                k = i;
                break;
            }
        }
        int zero_cnt = 0, one_cnt = 0;
        for(int i = 0; i < N; i++) {
            if (A[i] & (1<<k)) one_cnt++;
            else zero_cnt++;
        }
        if(((one_cnt + 1) / 2) % 2 == 1) puts("WIN");
        else if (zero_cnt % 2 == 1) puts("WIN");
        else puts("LOSE");
    }
    return 0;
}