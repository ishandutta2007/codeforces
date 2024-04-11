#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N;
int a[100010];

int ask(int x) {
    if (a[x] != -1 || x < 1 || x > N) {
        return a[x];
    }
    printf("? %d\n",x);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return a[x] = ret;
}

void answer(int x) {
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        a[i] = -1;
    }
    a[0] = a[N + 1] = 1e9;
    ask(1);
    ask(2);
    ask(N);
    ask(N-1);
    if (a[1] < a[2]) answer(1);
    if (a[N] < a[N - 1]) answer(N);
    int L = 1, R = N;
    while(L < R - 2) {
        int mid = (L + R) / 2;
        ask(mid);
        ask(mid - 1);
        ask(mid + 1);
        if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1]) {
            answer(mid);
        }
        if (a[mid - 1] < a[mid]) R = mid;
        else L = mid;
    }
    for (int i=L-1;i<=R+1;i++) ask(i);
    for (int i=L;i<=R;i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            answer(i);
        }
    }
    assert(false);
}