#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100013];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        while (a[i]%2==0) a[i]/=2;
        while (a[i]%3==0) a[i]/=3;
    }
    int ok = 1;
    for (int i=0;i<n;i++) if (a[i]!=a[0]) ok = 0;
    printf("%s\n",ok ? "Yes" : "No");

    return 0;
}