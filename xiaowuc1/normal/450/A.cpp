#include <cstdio>
using namespace std;
int main() {
    int n, m;
    scanf("%d", &n);
    int currentMax = -1;
    scanf("%d", &m);
    int indexOfMax = -1;
    for (int i = 0; i < n; i++) {
        int curr;
        scanf("%d", &curr);
        if(curr >= currentMax) {
        }
        if((curr + m - 1) / m >= (currentMax + m - 1) / m) {
            indexOfMax = i;
            currentMax = curr;
        }
    }
    printf("%d\n", indexOfMax + 1);
}