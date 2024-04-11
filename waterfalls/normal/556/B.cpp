#include <cstdio>
#include <algorithm>

using namespace std;

int a[1013];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int found = 0;
    for (int r=0;r<n;r++) {
        for (int i=0;i<n;i++) {
            if (i%2==0) a[i] = (a[i]+1)%n;
            else a[i] = (a[i]-1+n)%n;
        }
        int ok = 1;
        for (int i=0;i<n;i++) if (a[i]!=i) ok = 0;
        if (ok) found = 1;
    }
    if (found) printf("Yes\n");
    else printf("No\n");

    return 0;
}