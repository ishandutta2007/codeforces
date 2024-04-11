#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

const int ML = 200000 + 10;

char a[ML], b[ML];
int N, M;

int main() {
    scanf("%d%d",&N,&M);
    scanf("%s%s",a,b);
    int wp = -1;
    for(int i=0;i<N;i++) {
        if(a[i] == '*') wp = i;
    }

    if(wp==-1){
        puts(strcmp(a, b) ? "NO" : "YES");
    }
    else {
        if (N > M + 1) {
            puts("NO");
            return 0;
        }
        for(int i = 0; i < wp; i++) {
            if(a[i] != b[i]) {
                puts("NO");
                return 0;
            }
        }
        for(int i = N-1; i > wp; i--) {
            if(a[i] != b[M-(N-i)]) {
                puts("NO");
                return 0;
            }
        }
        puts("YES");
    }
    return 0;
}