#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long m;
int num[50];

int main() {
    scanf("%d%I64d",&n,&m);
    int l = 0;
    int r = n-1;
    for (int i=0;i<n-1;i++) {
        if (m<=((1LL)<<(n-i-2))) {
            num[l] = i+1;
            l+=1;
        } else {
            num[r] = i+1;
            r-=1;
            m-=((1LL)<<(n-i-2));
        }
    }
    num[l] = n;
    for (int i=0;i<n;i++) printf("%d ",num[i]);
    printf("\n");

    return 0;
}