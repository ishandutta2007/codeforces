#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        if (i%2==0) for (int j=0;j<m;j++) printf("#");
        else {
            if (i%4==3) printf("#");
            for (int j=0;j<m-1;j++) printf(".");
            if (i%4==1) printf("#");
        }
        printf("\n");
    }

    return 0;
}