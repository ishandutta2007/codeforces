#include <cstdio>
#include <vector>

using namespace std;

int n, k, now = 1, counter;
bool flag = true, newb = true;
bool arr[100001];

main() {
    scanf("%d %d", &n, &k);
    counter = k;
    for (int i = 0; i < n; ++i) {
        printf("%d ", now);
        arr[now] = true;
        if (counter == 0) {
            for (int i = 1; i < n + 1; ++i) {
                if (!arr[i]) printf("%d ", i);
            }
            return 0;
        }
        else {
            if (flag) {
                now += counter;
            }
            else {
                now -= counter;
            }
            counter--;
            flag = !flag;
        }
    }
}