#include <iostream>
using namespace std;

bool solve()
{
    int n, arr[100000], num[100000];
    scanf("%d", &n);
    int a = 0, b = 0, c = 0;
    int el;
    arr[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", num + i);
        el = num[i];
        if (el == -1) a = 1;
        else if (el == 0) b = 2;
        else c = 4;
        arr[i + 1] = a + b + c;
    }
    bool f = false;
    scanf("%d", num + n - 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &el);
        if (el > 0) {
            if (!f && num[i] != el && arr[i] < 4) {
                f = true;
            }
        }
        if (el < 0) {
            if (!f && num[i] != el && arr[i] != 1 && arr[i] != 3 && arr[i] != 7 && arr[i] != 5) {
                f = true;
            }
        }
        if (el == 0) {
            if (num[i] > 0 && arr[i] != 1 && arr[i] != 3 && arr[i] != 7 && arr[i] != 5) f = true;
            if (num[i] < 0 && arr[i] < 4) f = true;
        }
    }
    if (f) return 0;
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}