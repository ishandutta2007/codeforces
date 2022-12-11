#include <stdio.h>
#include <iostream>
using namespace std;

int main () {
    long long int a[200004], sum[200004];
    int n, t, ai, xi, quan;
    double mean;
    
    scanf("%d", &n);
    a[0] = 0;
    quan = 1;
    mean = 0;
    sum[0] = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        
        if (t == 2) {
            scanf("%I64d", &a[quan]);
            sum[quan] = 0;
            mean = (mean * quan + (double)a[quan]) / (double)(quan + 1);
            quan++;
        } else if (t == 1) {
            scanf("%d%d", &ai, &xi);
            sum[ai-1] += xi;
            mean += (double)ai*xi / quan;
        } else {
            mean = (mean * quan - (double)a[quan-1] - (double)sum[quan-1]) / (double)(quan-1);
            quan--;
            sum[quan-1] += sum[quan];
        }
        
        printf("%lf\n", mean);
    }
    
    return 0;
}