#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, all;
    set <int> use;
    scanf("%d\n", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
        use.insert(a[i]);
    }
    all = use.size();
    use.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (use.find(a[i]) == use.end()) {
            all--;
            use.insert(a[i]);
        }
        if (all == 0) {
            printf("%d\n", a[i]);
            return 0;
        }
    }
    return 0;
}