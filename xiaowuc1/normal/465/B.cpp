#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int list[1005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int ans = 0;
    bool last_was_unread = false;
    for (int i = 0; i < n; i++) {
        if (list[i] == 1) {
            ans++;
            if (!last_was_unread) {
                ans++;
            }
            last_was_unread = true;
        } else {
            last_was_unread = false;
        }
    }
    printf("%d\n", max(ans - 1, 0));
}