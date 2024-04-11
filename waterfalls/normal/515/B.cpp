#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,b,g;
int boy[100];
int girl[100];

int main() {
    scanf("%d%d",&n,&m);
    scanf("%d",&b);
    for (int i=0;i<b;i++) {
        int which;
        scanf("%d",&which);
        boy[which] = 1;
    }
    scanf("%d",&g);
    for (int i=0;i<g;i++) {
        int which;
        scanf("%d",&which);
        girl[which] = 1;
    }
    for (int i=0;i<2*n*m;i++) {
        boy[i%n]|=girl[i%m];
        girl[i%m]|=boy[i%n];
    }
    int ok = 1;
    for (int i=0;i<n;i++) ok&=boy[i];
    for (int i=0;i<m;i++) ok&=girl[i];
    printf("%s\n",ok ? "Yes" : "No");

    return 0;
}