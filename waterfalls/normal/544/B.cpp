#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;

int main() {
    scanf("%d%d",&n,&k);
    if ((n*n+1)/2<k) printf("NO\n");
    else {
        printf("YES\n");
        int has = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if ((i+j)%2==0 && has<k) printf("L"), has+=1;
                else printf("S");
            }
            printf("\n");
        }
    }

    return 0;
}