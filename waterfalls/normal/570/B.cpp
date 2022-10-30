#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;

int main() {
    scanf("%d%d",&n,&m);
    if (n==1) return printf("1\n"),0;
    int l = m-1;
    int r = n-m;
    printf("%d\n",l>=r ? m-1 : m+1);

    return 0;
}