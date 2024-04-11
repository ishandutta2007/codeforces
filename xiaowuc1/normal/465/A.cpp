#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    char buf[105];
    scanf("%s", buf);
    int ret = 0;
    for(; ret < n && buf[ret] == '0'; ret++) {}
    for(ret = 0; ret < n && buf[ret] == '1'; ret++);
    printf("%d\n", min(n, ret+1));
}