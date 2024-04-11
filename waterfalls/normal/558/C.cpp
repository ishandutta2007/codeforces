#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100013];
int num[100013];
int req[100013];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) {
        int cur = 0;
        do {
            req[a[i]]+=cur;
            num[a[i]]+=1;
            cur+=1;
            a[i]/=2;
        } while (a[i]>1);
        req[a[i]]+=cur;
        num[a[i]]+=1;
    }
    int ans = 1e9;
    for (int i=1;i<100013;i++) {
        if (num[i]==n) {
            ans = min(ans,req[i]);
            if (i*2<100013 && num[i*2]!=n) {
                int low = req[i]-(req[i*2]+num[i*2]);
                req[i*2]+=low+(n-num[i*2]);
                num[i*2] = n;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}