#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int b[300];
int num[401];
int sums[402];

void findNext(int sum) {
    int cur = 0;
    int bigger = 0;
    int found = 0;
    for (int i=400;i>=0 && !found;i--) {
        for (int j=1;num[i]+j<10 && !found;j++) {
            if (sums[i]+num[i]+j<=sum && sums[i]+num[i]+j+9*(400-i)>=sum) {
                found = 1;
                num[i]+=j;
                if (i!=400) {
                    int start = i+1;
                    while (9*(400-start)>=sum-sums[i]-num[i] && start<=400) {
                        num[start] = 0;
                        start+=1;
                    }
                    if (start!=401) {
                        num[start] = (sum-sums[i]-num[i]+8)%9+1;
                        for (start+=1;start<=400;start++) num[start] = 9;
                    }
                }
            }
        }
    }
    sums[0] = 0;
    for (int i=0;i<=400;i++) sums[i+1] = sums[i]+num[i];
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) {
        findNext(b[i]);
        int found = 0;
        for (int j=0;j<401;j++) {
            if (num[j]!=0) found = 1;
            if (found) printf("%d",num[j]);
        }
        printf("\n");
    }

    return 0;
}