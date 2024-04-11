#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int even = 0;
    int odd = 0;
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if (a%2==0) even+=1;
        else odd+=1;
    }
    int turns = n-k;
    if (turns==0) {
        if (odd%2==0) printf("Daenerys\n");
        else printf("Stannis\n");
        return 0;
    }
    if (turns%2==0) {
        if (k%2==0) {
            printf("Daenerys\n");
        } else {
            if (even<=turns/2) printf("Stannis\n");
            else printf("Daenerys\n");
        }
    } else {
        if (k%2==0) {
            if (even<=turns/2 || odd<=turns/2) printf("Daenerys\n");
            else printf("Stannis\n");
        } else {
            if (odd<=turns/2) printf("Daenerys\n");
            else printf("Stannis\n");
        }
    }

    return 0;
}