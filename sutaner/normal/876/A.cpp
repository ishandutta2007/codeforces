#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    if (n == 1) {
        printf("0");
        return 0;
    }
    int minnum = min(a, min(b, c));
    if (a == minnum || b == minnum){
        printf("%d", (n - 1) * minnum);
    }
    else{
        if (a > b) swap(a, b);
        printf("%d", a + (n - 2) * minnum);
    }
    return 0;
}