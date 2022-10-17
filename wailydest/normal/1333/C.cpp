#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<long long> arr(n);
    
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    
    for (int i = 1; i < n; ++i) arr[i] += arr[i - 1];
    
//    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
//    printf("\n");
    
    long long amount = 0;
    
    map<long long, int> el_index;
    int prev = 0, current;
    bool pr = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0 && prev == 0) {
            if (!pr) {
                amount += (n - i);
                el_index[0] = i;
                prev = 1;
                pr = true;
                continue;
            }
        }
        if (el_index.count(arr[i])) {
            current = el_index[arr[i]] + 1;
            for (int i = max(0, prev - 1); i < current; ++i) el_index.erase(arr[i]);
            amount += (long long)(current - prev + 1) * (n - i);
            prev = current + 1;
        }
        el_index[arr[i]] = i;
    }
    
//    printf("%lld\n", amount);
    printf("%lld\n", (long long)n * (n + 1) / 2 - amount);
    
    return 0;
}