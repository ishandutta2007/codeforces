#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

int main() {
    scanf("%d%d",&n,&m);
    printf("%d\n",min((m+n)/3,min(m,n)));

    return 0;
}