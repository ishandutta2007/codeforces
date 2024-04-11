#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int floors[1000];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> floors[i];
    
    int opt[1000];
    long long sum_max = -1, sum_cur;
    int max_current = 0;
    for (int current = 0; current < n; ++current) {
        opt[current] = floors[current];
        for (int i = current + 1; i < n; ++i) {
            opt[i] = min(opt[i - 1], floors[i]);
        }
        for (int i = current - 1; i >= 0; --i) {
            opt[i] = min(opt[i + 1], floors[i]);
        }
        sum_cur = 0;
        for (int i = 0; i < n; ++i) sum_cur += opt[i];
        if (sum_max < sum_cur) {
            max_current = current;
            sum_max = sum_cur;
        }
    }
    int current = max_current;
    opt[current] = floors[current];
    for (int i = current + 1; i < n; ++i) {
        opt[i] = min(opt[i - 1], floors[i]);
    }
    for (int i = current - 1; i >= 0; --i) {
        opt[i] = min(opt[i + 1], floors[i]);
    }
    for (int i = 0; i < n; ++i) cout << opt[i] << ' ';
    cout << '\n';
    
    return 0;
}