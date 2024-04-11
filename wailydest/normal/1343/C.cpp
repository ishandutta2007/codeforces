#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int val;
        scanf("%d", &val);
        int maxel = val;
        long long sum = 0;
        bool sign = val > 0;
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d", &val);
            if ((bool)(val > 0) == sign) {
                maxel = max(val, maxel);
            }
            else {
                sum += maxel;
                sign = !sign;
                maxel = val;
            }
        }
        sum += maxel;
        printf("%lld\n", sum);
    }
    return 0;
}